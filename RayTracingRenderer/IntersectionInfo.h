#pragma once
#include "glm/vec3.hpp"
#include "Material.h"
#include <memory>

class Primitive;

struct IntersectionInfo 
{
	float intersectMagnitude;
	Material mat;
	glm::vec3 normal;
	glm::vec3 color;
};