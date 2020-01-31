#pragma once
#include "BoundingVolume.h"
#include "glm/geometric.hpp"

class BoundingSphere :
	public BoundingVolume
{
public:
	BoundingSphere(const glm::vec3& pos, const float& rad, std::vector<Hitable*> elements);
	bool GetIntersection(const Ray& ray, ShadingInfo& info) const;
	const std::vector<Hitable*> GetVolumeContent() const;

private: 
	float radius;
};

