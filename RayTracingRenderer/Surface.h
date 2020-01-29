#pragma once
#include "Hitable.h"
#include "Material.h"
class vec3;
class Ray;
struct IntersectionInfo;

class Surface: public Hitable 
{
public:
	virtual bool GetIntersection(const Ray& ray, IntersectionInfo& info) const = 0;
	virtual const Material& GetMaterial() const = 0;
	virtual const int& GetIdentifier() const = 0;

protected:
	Surface(const int id) : objID(id) {};
	Material material;
	const int objID;
};
