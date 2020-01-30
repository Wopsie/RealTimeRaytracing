// RayracingRenderer.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <chrono>
#include <random>
#include <map>
#include "RayTracingRenderer.h"
#include "MathLibrary.h"
#include "Scene.h"
#include "Camera.h"
#include "Ray.h"
#include "Surface.h"
#include "Sphere.h"
#include "Plane.h"
#include "BoundingVolume.h"
#include "IntersectionInfo.h"
#include "ShadingInfo.h"
#include "LightSource.h"
#include "Material.h"
#include "Hitable.h"
#include "BoundingSphere.h"

int main()
{
	RayTracingRenderer();
	return 0;
}

RayTracingRenderer::RayTracingRenderer()
{
	Init();
	Tick();
}

//construct scene and bounding volumes
void RayTracingRenderer::Init()
{
	//set up sfml window
	window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(viewportSize.m_X), static_cast<unsigned int>(viewportSize.m_Y)), "Tracing");
	viewport.create(static_cast<unsigned int>(viewportSize.m_X), static_cast<unsigned int>(viewportSize.m_Y), sf::Color(0, 0, 0, 255));

	//scene building
	Camera cam = Camera(vec3(0, 0, 0), vec3(0, 0, 1).normalize());
	Sphere* s1 = new Sphere(vec3(0, 0, 500), 50, 1, vec3(1,1,1));
	LightSource light = LightSource(vec3(350, 0, 300), vec3(-1, -1, -1), vec3(1, 1, 1), LightType::Point);
	scene.camera = cam;
	scene.surfaceList.push_back(s1);
	scene.lightsList.push_back(light);
}

void RayTracingRenderer::Tick()
{
	float deltaTime = 0;
	while (window->isOpen())
	{
		auto start = std::chrono::high_resolution_clock::now();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		//input stuff here

		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> elapsed = finish - start;
		deltaTime = elapsed.count();
		std::cout << deltaTime << std::endl;

		Render(mat4::identity());
		Draw();
	}
}

void RayTracingRenderer::Render(const mat4& camTrans)
{
	vec3 topLeft = camTrans * vec3(-1, 1, 1);
	vec3 topRight = camTrans * vec3(1, 1, 1);
	vec3 botLeft = camTrans * vec3(-1, -1, 1);

	vec3 camWorldPos = camTrans * vec3(0, 0, 0);
	vec3 right = topRight - topLeft;
	vec3 down = botLeft - topLeft;

	for (int y = 0; y < viewportSize.m_Y; y++)
	{
		for (int x = 0; x < viewportSize.m_X; x++)
		{
			float u = x / static_cast<float>(viewportSize.m_X);
			float v = y / static_cast<float>(viewportSize.m_Y);

			vec3 pixel = topLeft + right * u + down * v;
			vec3 direction = vec3(pixel - camWorldPos).normalize();

			vec3 color = Trace(Ray(camWorldPos, direction, INFINITY));
			sf::Color sfColor = sf::Color(static_cast<sf::Uint8>(color.m_X * 255.0f), static_cast<sf::Uint8>(color.m_Y * 255.0f), static_cast<sf::Uint8>(color.m_Z * 255.0f), 255);
			viewport.setPixel(x, y, sfColor);
		}
	}
}

//void RayTracingRenderer::Trace()
//{
//	for (int y = 0; y < viewportSize.m_Y; y++)
//	{
//		for (int x = 0; x < viewportSize.m_X; x++)
//		{
//			const int xPixelPos = static_cast<int>(scene.camera.GetPosition().m_X - (viewportSize.m_X * 0.5f)) + x;
//			const int yPixelPos = static_cast<int>(scene.camera.GetPosition().m_Y - (viewportSize.m_Y * 0.5f)) + y;
//
//			reflectionRecursionDepth = 0;
//			refractionRecursionDepth = 0;
//			IntersectionInfo info;
//			//Cast a ray at the pixel coordinates
//			if (CastRay(vec3(static_cast<float>(xPixelPos), static_cast<float>(yPixelPos), scene.camera.GetPosition().m_Z), scene.camera.GetLookDirection(), info))
//			{
//				litPointColor.m_X = 0;
//				litPointColor.m_Y = 0;
//				litPointColor.m_Z = 0;
//				///Light pass, handles soft shading & hard shadow casting
//				litPointColor += SurfaceShading(info, vec3(static_cast<float>(xPixelPos), static_cast<float>(yPixelPos), scene.camera.GetPosition().m_Z));
//				
//				litPointColor.m_X = std::clamp(litPointColor.m_X, 0.0f, 1.0f);
//				litPointColor.m_Y = std::clamp(litPointColor.m_Y, 0.0f, 1.0f);
//				litPointColor.m_Z = std::clamp(litPointColor.m_Z, 0.0f, 1.0f);
//
//				sf::Color sphereColor = sf::Color(static_cast<sf::Uint8>(litPointColor.m_X * 255.0f), static_cast<sf::Uint8>(litPointColor.m_Y * 255.0f), static_cast<sf::Uint8>(litPointColor.m_Z * 255.0f), 255);
//				viewport.setPixel(x, y, sphereColor);
//			}
//			else
//			{
//				viewport.setPixel(x, y, sf::Color(static_cast<sf::Uint8>(skyColor.m_X * 255.0f), static_cast<sf::Uint8>(skyColor.m_Y * 255.0f), static_cast<sf::Uint8>(skyColor.m_Z * 255.0f), 255));
//			}
//		}
//	}
//}

vec3 RayTracingRenderer::Trace(const Ray& ray)
{
	vec3 color;
	std::shared_ptr<IntersectionInfo> info = NearestIntersect(scene, ray);

	if (info == nullptr) 
	{
		//do skybox color
		color = vec3(0, 0, 1);
	}
	else 
	{
		color = info->pSurface->GetMaterial().color * DirectIllumination(*info);
	}
	//color = info.pSurface->GetMaterial().color * DirectIllumination(info);

	//trace the ray and find what it intersects with.

	//When you find an intersection, get 3 things:
		// The intersection position
		// The intersection normal
		// if applicable, the intersection material color

	return color;
}

vec3 RayTracingRenderer::Trace(const Ray& ray, const LightSource& target)
{
	target;
	ray;
	//const IntersectionInfo& info = 
	return vec3();
}

std::shared_ptr<IntersectionInfo> RayTracingRenderer::NearestIntersect(const Scene& s, const Ray& r)
{
	std::shared_ptr<IntersectionInfo> pClosestInfo = nullptr;
	//Scene includes the BVH
	for (const Surface* surface : s.surfaceList)
	{
		std::shared_ptr<IntersectionInfo> pInfo = surface->GetIntersection(r);
		if (pClosestInfo == nullptr || pInfo->distToRayOrigin <= pClosestInfo->distToRayOrigin)
			pClosestInfo = pInfo;
	}

	/*if (pClosestInfo == nullptr)
		pClosestInfo = std::make_shared<IntersectionInfo>();*/

	return pClosestInfo;
}

vec3 RayTracingRenderer::DirectIllumination(const IntersectionInfo& info)
{
	info;
	//start with simple lambertian shading with light source
	
	//cast shadow ray to light sources

	for (const LightSource& source : scene.lightsList)
	{
		source;
	}
	return vec3();
}

///Find the information of the closest intersection point
//const bool RayTracingRenderer::CastRay(const vec3& origin, const vec3& direction, ShadingInfo& info, const float& maxDistance) const
//{
//	const Ray ray = Ray(origin, direction, maxDistance);
//	std::vector<ShadingInfo> infoVec;
//	for (const Surface* surface : scene.surfaceList)	//for each surface in the scene
//	{
//		if (surface->GetIntersection(ray, info))
//		{
//			infoVec.push_back(info);
//			//optimize this maybe by checking the distance of the info before pushing or removing it after if its redundant
//		}
//	}
//	
//	float dist = -1.0f;
//	for (ShadingInfo i : infoVec)
//	{
//		if (dist < 0 || i.distance < dist)
//		{
//			dist = i.distance;
//			info = i;
//		}
//	}
//	
//	return info.hit;
//}

///For casting rays inside refractive surface, returns first object inside surface, if there is no other surface inside, return refractive surface
//const bool RayTracingRenderer::CastRay(const vec3 & origin, const vec3 & direction, ShadingInfo & info, const int & excludedID, const float & maxDistance) const
//{
//	const Ray ray = Ray(origin, direction, maxDistance);
//	std::vector<ShadingInfo> infoVec;
//	
//	const Surface* refractiveSurface = nullptr;
//
//	for (const Surface* surface : scene.surfaceList)	//for each surface in the scene
//	{
//		//exclude the given surface from collision checks for refraction purposes
//		if (surface->GetIdentifier() != excludedID)
//		{
//			if (surface->GetIntersection(ray, info))
//			{
//				infoVec.push_back(info);
//				//optimize this maybe by checking the distance of the info before pushing or removing it after if its redundant
//			}
//		}
//		else 
//		{
//			refractiveSurface = surface;
//		}
//	}
//
//	float dist = -1.0f;
//	//all intersections stored for that ray. Find the one that is closest to the origin
//	for (ShadingInfo i : infoVec)
//	{
//		if (dist < 0 || i.distance < dist)
//		{
//			dist = i.distance;
//			info = i;
//		}
//	}
//
//	return info.hit;
//}

///Return the color that the pixel should be based on direct lighting alone. Includes blinn-phong specular distribution
const vec3 RayTracingRenderer::SurfaceShading(const ShadingInfo & info, const vec3 & rayOrigin)
{
	ShadingInfo temp;
	vec3 pixelColor;
	bool shaded = false;

	//for each light source calculations.
	///Blinn-Phong reflections & diffuse shading
	for (const LightSource& source : scene.lightsList)
	{
		vec3 shadeColor;
		shaded = false;
		const vec3 lightOffset = source.GetPosition() - info.position;
		if (!info.material.reflective)
		{
			const vec3 lightDirection = source.GetDirection(info.position);
			if (true)
			//if (CastRay(info.position, lightDirection, temp, lightOffset.length()))
			{
				//light ray was interupted, shading
				shadeColor = info.material.color * scene.ambientLightIntensity;
				shaded = true;
			}
			else
			{
				shadeColor = info.material.color * source.GetIntensity() * std::max(scene.ambientLightIntensity, info.normal.dot(source.GetDirection(info.position)));
			}
		}

		pixelColor += shadeColor;

		//specular highlights
		if (!shaded) 
		{
			const vec3 originOffset = rayOrigin - info.position;
			const vec3 halfwayVec = ((originOffset + lightOffset) / (originOffset + lightOffset).length()).normalize();
			pixelColor += (source.GetColor() * info.material.specular) * (source.GetIntensity() * std::max(0.0f, powf(info.normal.dot(halfwayVec), phongExponent)) * info.material.glossiness);
		}
		
	}
	

	const vec3 inRayDir = (info.position - rayOrigin).normalize();
	//Ideal specular reflection
	if (info.material.reflective)
	{
		if (reflectionRecursionDepth >= maxRecursionDepth)
		{
			temp = info;
			temp.material.reflective = false;
			temp.material.opaque = true;
			pixelColor += SurfaceShading(temp);	//make sure that normally reflective object is treated as diffuse in last render
		}
		else
		{
			reflectionRecursionDepth++;
			const vec3 reflectDir = (inRayDir - (info.normal * (inRayDir.dot(info.normal))) * 2.0f).normalize();
			if (true)
			//if (CastRay(info.position, reflectDir, temp))
			{
				pixelColor += SurfaceShading(temp, info.position);
			}
			else
			{
				pixelColor += skyColor;
			}
		}
	}
	
	if (!info.material.opaque)
	{
		if (refractionRecursionDepth >= maxRecursionDepth)
		{
			temp = info;
			temp.material.opaque = true;
			temp.material.reflective = false;
			pixelColor = SurfaceShading(temp, temp.position);
		}
		else
		{
			temp = info;
			refractionRecursionDepth++;
			vec3 refractionRayDir = (info.position - rayOrigin).normalize();
			//Cast another reflection ray and combine the color from them
			if (Refract(refractionRayDir, info.normal, info.material.refractIndex))
			{
				//found the refraction ray direction
				//add later that the interior of the surface is also checked for intersections
				//used to be included but removed for bug fixing
				Ray refractionRay = Ray(info.position, refractionRayDir, INFINITY);
				//info.surface->GetIntersection(refractionRay, temp);		//very dangerous to comment this out
				Refract(refractionRayDir, temp.mirrorNormal, scene.baseRefractiveIndex);
				if (true)
				//if (CastRay(temp.mirrorPosition, refractionRayDir, temp))
				{
					pixelColor += SurfaceShading(temp, temp.position);
				}
				else
				{
					pixelColor = skyColor;
				}
			}
			else 
			{
				//if you cant refract, redo but as reflective surface
				temp.material.reflective = true;
				temp.material.opaque = true;
				pixelColor += SurfaceShading(temp, rayOrigin);
			}
		}
	}
	return pixelColor;
}

///Calculate the new direction for a ray traveling through a refractive surface
const bool RayTracingRenderer::Refract(vec3 & rayDirection, const vec3& normal, const float & refIndex)
{
	//total hack, implement snells law later
	//better way to do this would be by using snells law
	const float dt = rayDirection.dot(normal);
	const float refractIndex = 1.0f / refIndex;
	float discriminant = 1.0f - refractIndex * refractIndex * (1 - dt * dt);
	if (discriminant > 0) 
	{
		rayDirection = (((rayDirection - normal * rayDirection) * refractIndex) - normal * sqrtf(discriminant)).normalize();
		return true;
	}
	return false;
}

void RayTracingRenderer::Draw()
{
	sf::Texture texture;
	texture.loadFromImage(viewport);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	window->clear();
	window->draw(sprite);
	window->display();
}
