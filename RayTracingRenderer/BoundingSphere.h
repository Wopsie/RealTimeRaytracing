#pragma once
#include "BoundingVolume.h"
class BoundingSphere :
	public BoundingVolume
{
public:
	BoundingSphere(const vec3& pos, const float& rad, std::vector<Hitable*> elements);
	bool GetIntersection(const Ray& ray, IntersectionInfo& info) const;
	const std::vector<Hitable*> GetVolumeContent() const;

private: 
	float radius;
};

