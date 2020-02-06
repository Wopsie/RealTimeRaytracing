#pragma once
#include "Primitive.h"
#include "glm/glm.hpp"
#include "Material.h"

class Ray;
struct IntersectionInfo;

class Plane : public Primitive {
public:
	Plane(glm::vec3 origin, glm::vec3 normal);
	const bool GetIntersection(float& magnitude, const Ray& ray) const;
	void IntersectionDetails(const glm::vec3& collPos, IntersectionInfo& info) const;

private:
	glm::vec3 normal = glm::vec3(0, 1, 0);
	glm::vec3 origin = glm::vec3(0);

	Material* black = new Material();
	Material* white = new Material();
};