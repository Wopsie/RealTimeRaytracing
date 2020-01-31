#pragma once
#include "Hitable.h"
#include "Material.h"
class vec3;
class Ray;
struct ShadingInfo;
struct IntersectionInfo;

class Surface: public Hitable 
{
public:
	virtual bool GetShadingInfo(const Ray& ray, ShadingInfo& info) const = 0;
	virtual std::shared_ptr<IntersectionInfo> GetIntersection(const Ray& ray) const = 0;
	virtual const Material& GetMaterial() const = 0;
	virtual const int& GetIdentifier() const = 0;
	glm::vec3 GetPosition() { return position; };

protected:
	Surface(const int id) : objID(id) {};
	Material material;
	const int objID;
};
