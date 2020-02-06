#pragma once
#include "glm/vec3.hpp"
#include <memory>

class Primitive;

struct IntersectionInfo 
{
	float intersectMagnitude;
	glm::vec3 normal;
	glm::vec3 color;
};