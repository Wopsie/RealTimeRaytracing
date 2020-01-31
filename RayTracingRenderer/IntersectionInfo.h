#pragma once
#include "Surface.h"
#include "glm/vec3.hpp"

struct IntersectionInfo 
{
	const Surface* pSurface = nullptr;
	glm::vec3 intersectPos = glm::vec3();
	float distToRayOrigin = 0;
};