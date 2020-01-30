#pragma once
#include "Surface.h"
#include "MathLibrary.h"
#include "Material.h"
struct ShadingInfo;
struct IntersectionInfo;

class Plane : public Surface
{
public:
	Plane();
	Plane(const vec3& pos, const vec3& inclination, const int& id, const Material& mat);
	Plane(const vec3& pos, const vec3& inclination, const int& id, const vec3& ambient = vec3(1,1,1));
	bool GetShadingInfo(const Ray& ray, ShadingInfo& info) const;
	std::shared_ptr<IntersectionInfo> GetIntersection(const Ray& ray) const;
	const Material& GetMaterial() const;
	const int& GetIdentifier() const;

private:
	vec3 normal;
};
