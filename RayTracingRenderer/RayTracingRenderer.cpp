#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <chrono>
#include <random>
#include <map>
#include "RayTracingRenderer.h"
#include "Scene.h"
#include "Camera.h"
#include "Ray.h"
#include "Surface.h"
#include "Sphere.h"
#include "Plane.h"
#include "LightSource.h"
#include "Material.h"
#include "glm/glm.hpp"

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
	std::srand(0);
	//set up sfml window
	window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(viewportSize.x), static_cast<unsigned int>(viewportSize.y)), "Tracing");
	viewport.create(static_cast<unsigned int>(viewportSize.x), static_cast<unsigned int>(viewportSize.y), sf::Color(0, 0, 0, 255));

	//scene building
	glm::vec3 v = glm::vec3();
	Camera cam = Camera(glm::vec3(0, 0, 0), glm::normalize(glm::vec3(0, 0, 1)));
	//LightSource light = LightSource(glm::vec3(350, 0, 300), glm::vec3(-1, -1, -1), glm::vec3(1, 1, 1), LightType::Point);


	lightMat.isLight = true;
	diffuseRed.albedo = glm::vec3(1, 0, 0);
	diffuseGreen.albedo = glm::vec3(0, 1, 0);
	diffuseBlue.albedo = glm::vec3(0, 0, 1);
	
	std::shared_ptr<Sphere> sphereWhite1 = std::make_shared<Sphere>(glm::vec3(-0.5f, -0.5f, 3), 0.5f, diffuseWhite);
	std::shared_ptr<Sphere> sphereWhite2 = std::make_shared<Sphere>(glm::vec3(0.5f, -0.5f, 3), 0.5f, diffuseWhite);
	std::shared_ptr<Sphere> sphereWhite3 = std::make_shared<Sphere>(glm::vec3(-1.f, -0.5f, 3), 0.5f, diffuseWhite);
	std::shared_ptr<Sphere> sphereWhite4 = std::make_shared<Sphere>(glm::vec3(1.f, -0.5f, 3), 0.5f, diffuseWhite);
	std::shared_ptr<Sphere> sphere1 = std::make_shared<Sphere>(glm::vec3(0, 0.5f, 3), 0.5f, diffuseRed);
	std::shared_ptr<Sphere> sphere2 = std::make_shared<Sphere>(glm::vec3(1.2f, 0.5f, 3), 0.5f, diffuseGreen);
	std::shared_ptr<Sphere> sphere3 = std::make_shared<Sphere>(glm::vec3(-1.2f, 0.5f, 3), 0.5f, diffuseBlue);
	std::shared_ptr<Sphere> sphereLight = std::make_shared<Sphere>(glm::vec3(0, 20, 0), 17.f, lightMat);

	scene.primitives.push_back(sphereWhite1);
	scene.primitives.push_back(sphereWhite2);
	scene.primitives.push_back(sphereWhite3);
	scene.primitives.push_back(sphereWhite4);
	scene.primitives.push_back(sphere1);
	scene.primitives.push_back(sphere2);
	scene.primitives.push_back(sphere3);
	scene.primitives.push_back(sphereLight);
	scene.primitives.push_back(plane);

	scene.camera = cam;

	std::cout << scene.camera.GetTransform()->modelMat[0][0] << scene.camera.GetTransform()->modelMat[0][1] << scene.camera.GetTransform()->modelMat[0][2] << scene.camera.GetTransform()->modelMat[0][3] << std::endl << scene.camera.GetTransform()->modelMat[1][0] << scene.camera.GetTransform()->modelMat[1][1] << scene.camera.GetTransform()->modelMat[1][2] << scene.camera.GetTransform()->modelMat[1][3] << std::endl << scene.camera.GetTransform()->modelMat[2][0] << scene.camera.GetTransform()->modelMat[2][1] << scene.camera.GetTransform()->modelMat[2][2] << scene.camera.GetTransform()->modelMat[2][3] << std::endl << scene.camera.GetTransform()->modelMat[3][0] << scene.camera.GetTransform()->modelMat[3][1] << scene.camera.GetTransform()->modelMat[3][2] << scene.camera.GetTransform()->modelMat[3][3] << std::endl;
}

void RayTracingRenderer::Tick()
{
	float deltaTime = 0;
	while (window->isOpen())
	{
		auto start = std::chrono::high_resolution_clock::now();
		scene.camera.isMoving = false;

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		float camSpeed = 25.f;

		//input stuff here
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		{
			scene.camera.GetTransform()->Translate(glm::vec3(-.01f, 0, 0) * camSpeed);
			scene.camera.isMoving = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		{
			scene.camera.GetTransform()->Translate(glm::vec3(.01f, 0, 0) * camSpeed);
			scene.camera.isMoving = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			scene.camera.GetTransform()->Translate(glm::vec3(0, 0, .01f) * camSpeed);
			scene.camera.isMoving = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			scene.camera.GetTransform()->Translate(glm::vec3(0, 0, -.01f) * camSpeed);
			scene.camera.isMoving = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
		{
			scene.camera.GetTransform()->Translate(glm::vec3(0, .01f, 0) * camSpeed);
			scene.camera.isMoving = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) 
		{
			scene.camera.GetTransform()->Translate(glm::vec3(0, -.01f, 0) * camSpeed);
			scene.camera.isMoving = true;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			scene.camera.GetTransform()->Translate(glm::vec3(0, -.01f, 0) * camSpeed);
			scene.camera.isMoving = true;
		}

		if (!scene.camera.isMoving)
			frameCounter++;
		else 
			frameCounter = 0;

		Render(scene.camera.GetTransform()->modelMat);
		Draw();

		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> elapsed = finish - start;
		deltaTime = elapsed.count();
		std::cout << 1.f / deltaTime << std::endl;
		/*framerateInterval += deltaTime;
		if (framerateInterval >= 1.f) {
			framerateInterval = 0;
		}*/

	}
}

void RayTracingRenderer::Render(const glm::mat4& camTrans)
{
	/*glm::quat rotation;
	glm::decompose(camTrans, glm::vec3(0), )

	float fov = 80;*/
	//glm::vec4 center = camTrans + glm::vec4(0, 0, 1, 0) * 80.f;
	//frustum
	/*p0*/glm::vec3 topLeft = camTrans * glm::vec4(-1, 1, 1, 0);
	/*p1*/glm::vec3 topRight = camTrans * glm::vec4(1, 1, 1, 0);
	/*p2*/glm::vec3 botLeft = camTrans * glm::vec4(-1, -1, 1, 0);

	glm::vec3 E = camTrans * glm::vec4(0, 0, 0, 1);
	glm::vec3 right = topRight - topLeft;
	glm::vec3 down = botLeft - topLeft;
	glm::vec3 color;
	Ray ray = Ray();
	IntersectionInfo info;

	const unsigned int sampleCountMax = 8;

	for (int y = 0; y < viewportSize.y; y++)
	{
		for (int x = 0; x < viewportSize.x; x++)
		{
			color = glm::vec3(0.8f, 0.9f, 1);
			float u = x / static_cast<float>(viewportSize.x);
			float v = y / static_cast<float>(viewportSize.y);
			ray.SetOrigin((topLeft + right * u + down * v) + E);
			ray.SetDirection(glm::normalize(ray.GetOrigin() - E));
			ray.SetRange(200);

			//color = Trace(info, ray);
			unsigned int sampleCount = sampleCountMax;

			color = Sample(info, ray, sampleCount);

			if(frameCounter != 0)
				color /= frameCounter;

			sf::Color sfColor = sf::Color(static_cast<sf::Uint8>(color.x * 255.0f), static_cast<sf::Uint8>(color.y * 255.0f), static_cast<sf::Uint8>(color.z * 255.0f), 255);

			if (!scene.camera.isMoving) {
				sf::Color pixelColor = viewport.getPixel(x, y) + sfColor;

				/*if (frameCounter != 0) {
					pixelColor = sf::Color(static_cast<sf::Uint8>(pixelColor.r / frameCounter), static_cast<sf::Uint8>(pixelColor.g / frameCounter), static_cast<sf::Uint8>(pixelColor.b / frameCounter));
				}*/

				viewport.setPixel(x, y, pixelColor);
			}
			else {
				viewport.setPixel(x, y, sfColor);
			}
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
//			if (CastRay(glm::vec3(static_cast<float>(xPixelPos), static_cast<float>(yPixelPos), scene.camera.GetPosition().m_Z), scene.camera.GetLookDirection(), info))
//			{
//				litPointColor.m_X = 0;
//				litPointColor.m_Y = 0;
//				litPointColor.m_Z = 0;
//				///Light pass, handles soft shading & hard shadow casting
//				litPointColor += SurfaceShading(info, glm::vec3(static_cast<float>(xPixelPos), static_cast<float>(yPixelPos), scene.camera.GetPosition().m_Z));
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

glm::vec3 RayTracingRenderer::Trace(IntersectionInfo& info, const Ray& ray)
{
	if (info.intersectMagnitude = NearestIntersect(scene.primitives, ray, info); info.intersectMagnitude != -1.f && info.intersectMagnitude != ray.GetMaxRange()) {
		return info.mat.albedo/* * DirectIllumination(info);*/;
	}
	else
	{
		return skyColor;
	}
}

//this is only for shadow rays, because it shouldn't check for anything but the intersection itself
//glm::vec3 RayTracingRenderer::Trace(IntersectionInfo& info, const Ray& ray, const LightSource& target)
//{
//	info;
//	target;
//	ray;
//	return glm::vec3();
//}

glm::vec3 RayTracingRenderer::Sample(IntersectionInfo& info, Ray& ray, unsigned int& depth)
{
	glm::vec3 color = Trace(info, ray);
	//temporary skycolor condition, should be if the ray didnt hit anything. boolean on intersectionInfo??
	if (color == skyColor) {
		return glm::vec3(0);
	}

	if (info.mat.isLight)
	{
		return info.mat.emittance;
	}

	if (info.mat.isMirror)
	{
		//reflect ray and sample/trace
		glm::vec3 intersectPoint = ray.PointOnLineAt(info.intersectMagnitude);
		ray.SetOrigin(intersectPoint);
		ray.SetDirection(glm::reflect(ray.GetDirection(), info.normal));
		return Trace(info, ray);
	}

	glm::vec3 intersectPoint = ray.PointOnLineAt(info.intersectMagnitude);
	ray.SetOrigin(intersectPoint);
	ray.SetDirection(DiffuseReflection(info.normal));
	glm::vec3 BRDF = info.mat.albedo / PI_F;
	float irradiance = glm::dot(info.normal, ray.GetDirection());
	glm::vec3 Ei = color;
	depth--;
	if (depth > 0)
	{
		//bounce
		Ei = Sample(info, ray, depth) * irradiance;
	}
	return PI_F * 2.0f * BRDF * Ei;
}

const glm::vec3 RayTracingRenderer::DiffuseReflection(const glm::vec3 normal)
{
	float azimuth = static_cast<float>(std::rand()) / RAND_MAX * PI_F * 2.0f;
	glm::vec3 hemisphere;

	hemisphere.y = static_cast<float>(std::rand()) / RAND_MAX;
	float sinElevation = sqrtf(1 - hemisphere.y * hemisphere.y);
	hemisphere.x = sinElevation * cosf(azimuth);
	hemisphere.z = sinElevation * sinf(azimuth);

	glm::vec3 nT;
	if (std::abs(normal.x) > std::abs(normal.y)) {
		nT = glm::normalize(glm::vec3(normal.z, 0, -normal.x));
	}
	else {
		nT = glm::normalize(glm::vec3(0, -normal.z, normal.y));
	}
	glm::vec3 nB = glm::cross(normal, nT);
	//return random direction within hemisphere
	return glm::vec3(
		hemisphere.x * nB.x + hemisphere.y * normal.x + hemisphere.z * nT.x,
		hemisphere.x * nB.y + hemisphere.y * normal.y + hemisphere.z * nT.y,
		hemisphere.x * nB.z + hemisphere.y * normal.z + hemisphere.z * nT.z
	);
}

const float RayTracingRenderer::NearestIntersect(std::vector<std::shared_ptr<Primitive>> primitives, const Ray& r, IntersectionInfo& info)
{
	std::shared_ptr<Primitive> nearestPrimitive;
	float nearestMag = r.GetMaxRange();
	for (std::shared_ptr<Primitive> p : primitives)
	{
		float tempMag = nearestMag;
		if (p->GetIntersection(nearestMag, r)) {
			if (nearestMag < tempMag) {
				nearestPrimitive = p;
			}
		}
	}

	if(nearestPrimitive)
		nearestPrimitive->IntersectionDetails(r.PointOnLineAt(nearestMag), info);
	return nearestMag;
}

//not needed for path tracing, make later or smth
//glm::vec3 RayTracingRenderer::DirectIllumination(const IntersectionInfo& info)
//{
//	//start with simple lambertian shading with light source
//	
//	//cast shadow ray to light sources
//
//	info;
//
//	//for (const LightSource& source : scene.lightsList)
//	//{
//	//	//Trace a shadow ray in direction of light source
//	//	Trace(Ray(info.intersectPos, source.GetDirection(info.intersectPos), static_cast<float>((source.GetPosition() - info.intersectPos).length())), source);
//	//}
//	return glm::vec3();
//}

///Find the information of the closest intersection point
//const bool RayTracingRenderer::CastRay(const glm::vec3& origin, const glm::vec3& direction, ShadingInfo& info, const float& maxDistance) const
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
//const bool RayTracingRenderer::CastRay(const glm::vec3 & origin, const glm::vec3 & direction, ShadingInfo & info, const int & excludedID, const float & maxDistance) const
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
//const glm::vec3 RayTracingRenderer::SurfaceShading(const ShadingInfo & info, const glm::vec3 & rayOrigin)
//{
//	ShadingInfo temp;
//	glm::vec3 pixelColor = glm::vec3();
//	bool shaded = false;
//
//	//for each light source calculations.
//	///Blinn-Phong reflections & diffuse shading
//	for (const LightSource& source : scene.lightsList)
//	{
//		glm::vec3 shadeColor;
//		shaded = false;
//		const glm::vec3 lightOffset = source.GetPosition() - info.position;
//		if (!info.material.reflective)
//		{
//			const glm::vec3 lightDirection = source.GetDirection(info.position);
//			if (true)
//			//if (CastRay(info.position, lightDirection, temp, lightOffset.length()))
//			{
//				//light ray was interupted, shading
//				shadeColor = info.material.color * scene.ambientLightIntensity;
//				shaded = true;
//			}
//			else
//			{
//				shadeColor = info.material.color * source.GetIntensity() * std::max(scene.ambientLightIntensity, dot(info.normal, source.GetDirection(info.position)));
//			}
//		}
//
//		pixelColor += shadeColor;
//
//		//specular highlights
//		if (!shaded) 
//		{
//			const glm::vec3 originOffset = rayOrigin - info.position;
//			glm::vec3 v = originOffset + lightOffset;
//
//			float xb = v.x;
//			float yb = v.y;
//			float zb = v.z;
//			float vl = static_cast<float>(v.length());
//			v = glm::vec3(xb * vl, yb * vl, zb * vl);
//			const glm::vec3 halfwayVec = normalize(v);
//			pixelColor += (source.GetColor() * info.material.specular) * (source.GetIntensity() * std::max(0.0f, powf(dot(info.normal, halfwayVec), phongExponent)) * info.material.glossiness);
//		}
//	}
//	
//
//	const glm::vec3 inRayDir = normalize(info.position - rayOrigin);
//	//Ideal specular reflection
//	if (info.material.reflective)
//	{
//		if (reflectionRecursionDepth >= maxRecursionDepth)
//		{
//			temp = info;
//			temp.material.reflective = false;
//			temp.material.opaque = true;
//			pixelColor += SurfaceShading(temp);	//make sure that normally reflective object is treated as diffuse in last render
//		}
//		else
//		{
//			reflectionRecursionDepth++;
//			const glm::vec3 reflectDir = normalize(inRayDir - (info.normal * dot(inRayDir, (info.normal))) * 2.0f);
//			if (true)
//			//if (CastRay(info.position, reflectDir, temp))
//			{
//				pixelColor += SurfaceShading(temp, info.position);
//			}
//			else
//			{
//				pixelColor += skyColor;
//			}
//		}
//	}
//	
//	if (!info.material.opaque)
//	{
//		if (refractionRecursionDepth >= maxRecursionDepth)
//		{
//			temp = info;
//			temp.material.opaque = true;
//			temp.material.reflective = false;
//			pixelColor = SurfaceShading(temp, temp.position);
//		}
//		else
//		{
//			temp = info;
//			refractionRecursionDepth++;
//			glm::vec3 refractionRayDir = normalize(info.position - rayOrigin);
//			//Cast another reflection ray and combine the color from them
//			if (Refract(refractionRayDir, info.normal, info.material.refractIndex))
//			{
//				//found the refraction ray direction
//				//add later that the interior of the surface is also checked for intersections
//				//used to be included but removed for bug fixing
//				Ray refractionRay = Ray(info.position, refractionRayDir, INFINITY);
//				//info.surface->GetIntersection(refractionRay, temp);		//very dangerous to comment this out
//				Refract(refractionRayDir, temp.mirrorNormal, scene.baseRefractiveIndex);
//				if (true)
//				//if (CastRay(temp.mirrorPosition, refractionRayDir, temp))
//				{
//					pixelColor += SurfaceShading(temp, temp.position);
//				}
//				else
//				{
//					pixelColor = skyColor;
//				}
//			}
//			else 
//			{
//				//if you cant refract, redo but as reflective surface
//				temp.material.reflective = true;
//				temp.material.opaque = true;
//				pixelColor += SurfaceShading(temp, rayOrigin);
//			}
//		}
//	}
//	return pixelColor;
//}
//
/////Calculate the new direction for a ray traveling through a refractive surface
//const bool RayTracingRenderer::Refract(glm::vec3 & rayDirection, const glm::vec3& normal, const float & refIndex)
//{
//	//total hack, implement snells law later
//	//better way to do this would be by using snells law
//	const float dt = dot(rayDirection, normal);
//	const float refractIndex = 1.0f / refIndex;
//	float discriminant = 1.0f - refractIndex * refractIndex * (1 - dt * dt);
//	if (discriminant > 0) 
//	{
//		rayDirection = normalize(((rayDirection - normal * rayDirection) * refractIndex) - normal * sqrtf(discriminant));
//		return true;
//	}
//	return false;
//}

void RayTracingRenderer::Draw()
{
	texture.loadFromImage(viewport);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	window->clear();
	window->draw(sprite);
	window->display();
}
