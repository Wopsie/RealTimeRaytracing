#pragma once
#include "glm/vec3.hpp"

class Ray
{
public:
	Ray(const glm::vec3& pos, const glm::vec3& dir);
	Ray(const glm::vec3& pos, const glm::vec3& dir, const float& distance = INFINITY);
	const glm::vec3& GetOrigin() const;
	const glm::vec3& GetDirection() const;
	const float& GetMaxRange() const;
	const glm::vec3 PointOnLineAt(float magnitude) const;
	~Ray();
private:
	const glm::vec3 direction;
	const glm::vec3 origin;
	const float range;
};

