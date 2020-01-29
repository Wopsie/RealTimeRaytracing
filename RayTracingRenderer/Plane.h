#pragma once
#include "Surface.h"
#include "MathLibrary.h"
#include "Material.h"
struct IntersectionInfo;

class Plane : public Surface
{
public:
	Plane();
	Plane(const vec3& pos, const vec3& inclination, const int& id, const Material& mat);
	Plane(const vec3& pos, const vec3& inclination, const int& id, const vec3& ambient = vec3(1,1,1));
	bool GetIntersection(const Ray& ray, IntersectionInfo& info) const;
	const Material& GetMaterial() const;
	const int& GetIdentifier() const;

private:
	vec3 normal;
};
