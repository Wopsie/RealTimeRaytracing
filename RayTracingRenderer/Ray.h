#pragma once
#include "glm/vec3.hpp"

class Ray
{
public:
	Ray() { direction = glm::vec3(0); origin = glm::vec3(0); range = INFINITY; };
	Ray(glm::vec3 pos, glm::vec3 dir);
	Ray(glm::vec3 pos, glm::vec3 dir, const float& distance);
	const glm::vec3& GetOrigin() const;
	const glm::vec3& GetDirection() const;
	const float& GetMaxRange() const;
	const glm::vec3 PointOnLineAt(float magnitude) const;
	void SetOrigin(glm::vec3 o);
	void SetDirection(glm::vec3 d);

	~Ray();
private:
	glm::vec3 direction;
	glm::vec3 origin;
	float range;
};

