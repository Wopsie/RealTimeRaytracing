#pragma once
#include "MathLibrary.h"
#include "Scene.h"
#include "IntersectionInfo.h"
#include <SFML/Graphics.hpp>

class RayTracingRenderer
{
public:
	RayTracingRenderer();

private:
	void Init();
	void Tick(float& dt);
	void Render(const mat4& camTrans);
	void Trace();
	// Return pixel color
	vec3 Trace(const Ray& ray);
	
	void NearestIntersect(const Scene& s, const Ray& r);
	void DirectIllumination();

	void Draw();


	const bool CastRay(const vec3& origin, const vec3& direction, IntersectionInfo& info, const float& maxDistance = INFINITY) const;
	const bool CastRay(const vec3& origin, const vec3& direction, IntersectionInfo& info, const int& excludedID, const float& maxDistance = INFINITY) const;
	const bool Refract(vec3& rayDirection, const vec3& normal, const float& refIndex);
	const vec3 SurfaceShading(const IntersectionInfo& info, const vec3& rayOrigin = vec3());
	const float phongExponent = 256.0f;
	const vec3 skyColor = vec3(0.2f, 0.2f, 1.0f);
	vec3 litPointColor;
	const int maxRecursionDepth = 3;
	int reflectionRecursionDepth = 0;
	int refractionRecursionDepth = 0; //this should be an even number
	int objectIdentifier = 1;
	bool quitting = false;
	sf::Image viewport;
	vec2 viewportSize = vec2(512, 512);
	Scene scene = Scene();
};
