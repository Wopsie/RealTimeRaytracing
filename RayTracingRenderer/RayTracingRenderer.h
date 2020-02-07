#pragma once
#include "Scene.h"
#include "ShadingInfo.h"
#include "IntersectionInfo.h"
#include <SFML/Graphics.hpp>
#include "glm/matrix.hpp"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "Primitive.h"
#include "Sphere.h"
#include "Plane.h"

class RayTracingRenderer
{
public:
	RayTracingRenderer();

private:
	void Init();
	void Tick();
	void Render(const glm::mat4& camTrans);
	glm::vec3 Trace(IntersectionInfo& info, const Ray& ray);
	//glm::vec3 Trace(IntersectionInfo& info, const Ray& ray, const LightSource& target);
	glm::vec3 Sample(IntersectionInfo& info, Ray& ray, unsigned int& depth);
	const glm::vec3 DiffuseReflection(const glm::vec3 normal);
	//const std::pair<float, std::shared_ptr<Primitive>> NearestIntersect(std::vector<std::shared_ptr<Primitive>> primitives, const Ray& r);
	const float NearestIntersect(std::vector<std::shared_ptr<Primitive>> primitives, const Ray& r, IntersectionInfo& info);
	//glm::vec3 DirectIllumination(const IntersectionInfo& info);

	void Draw();

	/*const bool CastRay(const glm::vec3& origin, const glm::vec3& direction, ShadingInfo& info, const float& maxDistance = INFINITY) const;
	const bool CastRay(const glm::vec3& origin, const glm::vec3& direction, ShadingInfo& info, const int& excludedID, const float& maxDistance = INFINITY) const;*/
	const bool Refract(glm::vec3& rayDirection, const glm::vec3& normal, const float& refIndex);
	const glm::vec3 SurfaceShading(const ShadingInfo& info, const glm::vec3& rayOrigin = glm::vec3());
	const float phongExponent = 256.0f;
	glm::vec3 litPointColor;
	const int maxRecursionDepth = 3;
	int reflectionRecursionDepth = 0;
	int refractionRecursionDepth = 0; //this should be an even number
	int objectIdentifier = 1;
	bool quitting = false;
	sf::Image viewport;
	sf::Texture texture;
	sf::RenderWindow* window;
	const glm::vec2 viewportSize = glm::vec2(512, 512);
	Scene scene = Scene();

	float framerateInterval = 0;

	Material diffuseRed = Material();
	Material diffuseGreen = Material();
	Material diffuseBlue = Material();
	Material diffuseWhite = Material();
	Material lightMat = Material();

	const glm::vec3 skyColor = glm::vec3(0.8f, 0.9f, 1);
	std::shared_ptr<Plane> plane = std::make_shared<Plane>(glm::vec3(0, -0.5f, 0), glm::vec3(0, 1, 0));

	const double PI = 3.141592653589793238463;
	const float  PI_F = 3.14159265358979f;

	int frameCounter = 0;
};
