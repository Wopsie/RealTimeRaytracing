#pragma once
#include "MathLibrary.h"
#include "Scene.h"
#include "ShadingInfo.h"
#include "IntersectionInfo.h"
#include <SFML/Graphics.hpp>

class RayTracingRenderer
{
public:
	RayTracingRenderer();

private:
	void Init();
	void Tick();
	void Render(const mat4& camTrans);
	//void Trace();
	// Return pixel color
	vec3 Trace(const Ray& ray);
	vec3 Trace(const Ray& ray, const LightSource& target);
	
	std::shared_ptr<IntersectionInfo> NearestIntersect(const Scene& s, const Ray& r);
	vec3 DirectIllumination(const IntersectionInfo& info);

	void Draw();

	const bool CastRay(const vec3& origin, const vec3& direction, ShadingInfo& info, const float& maxDistance = INFINITY) const;
	const bool CastRay(const vec3& origin, const vec3& direction, ShadingInfo& info, const int& excludedID, const float& maxDistance = INFINITY) const;
	const bool Refract(vec3& rayDirection, const vec3& normal, const float& refIndex);
	const vec3 SurfaceShading(const ShadingInfo& info, const vec3& rayOrigin = vec3());
	const float phongExponent = 256.0f;
	const vec3 skyColor = vec3(0.2f, 0.2f, 1.0f);
	vec3 litPointColor;
	const int maxRecursionDepth = 3;
	int reflectionRecursionDepth = 0;
	int refractionRecursionDepth = 0; //this should be an even number
	int objectIdentifier = 1;
	bool quitting = false;
	sf::Image viewport;
	sf::RenderWindow* window;
	vec2 viewportSize = vec2(512, 512);
	Scene scene = Scene();


};
