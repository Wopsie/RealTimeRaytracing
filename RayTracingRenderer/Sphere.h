#pragma once
#include "MathLibrary.h"
#include "Surface.h"
#include "Material.h"
struct IntersectionInfo;

class Sphere : public Surface
{
public:
	Sphere();
	Sphere(const vec3& pos, const float& rad, const int& id, const vec3& ambient = vec3(1, 1, 1));
	Sphere(const vec3& pos, const float& rad, const int& id, const Material& mat);
	bool GetIntersection(const Ray& ray, IntersectionInfo& info) const;
	const Material& GetMaterial() const;
	const int& GetIdentifier() const;
	~Sphere();
private:
	float radius;
};
