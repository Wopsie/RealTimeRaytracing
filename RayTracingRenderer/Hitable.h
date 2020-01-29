#pragma once
#include "MathLibrary.h"
class Ray;
struct IntersectionInfo;

class Hitable
{
public:
	virtual bool GetIntersection(const Ray& ray, IntersectionInfo& info) const = 0;

protected: 
	vec3 position;
};

