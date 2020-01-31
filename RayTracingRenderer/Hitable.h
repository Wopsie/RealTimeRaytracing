#pragma once
#include <memory>
#include "glm/vec3.hpp"

class Ray;
struct IntersectionInfo;

class Hitable
{
public:
	virtual std::shared_ptr<IntersectionInfo> GetIntersection(const Ray& ray) const = 0;
	void TranslatePosition(glm::vec3 offset) { position += (offset * 20.f); };
protected: 
	glm::vec3 position = glm::vec3();
};

