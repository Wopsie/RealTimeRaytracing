#pragma once
#include "Surface.h"
#include "MathLibrary.h"

struct IntersectionInfo 
{
	const Surface* pSurface = nullptr;
	vec3 intersectPos = vec3();
	float distToRayOrigin = 0;
};