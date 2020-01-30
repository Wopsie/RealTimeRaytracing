#pragma once
#include "MathLibrary.h"
#include "Surface.h"
#include "Material.h"
struct ShadingInfo;
struct IntersectionInfo;

class Sphere : public Surface
{
public:
	Sphere();
	Sphere(const vec3& pos, const float& rad, const int& id, const vec3& ambient = vec3(1, 1, 1));
	Sphere(const vec3& pos, const float& rad, const int& id, const Material& mat);
	bool GetShadingInfo(const Ray& ray, ShadingInfo& info) const;
	std::shared_ptr<IntersectionInfo> GetIntersection(const Ray& ray) const;
	const Material& GetMaterial() const;
	const int& GetIdentifier() const;
	~Sphere();
private:
	float radius;
};
