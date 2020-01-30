#pragma once
#include "MathLibrary.h"
class Ray;
struct IntersectionInfo;

class Hitable
{
public:
	virtual std::shared_ptr<IntersectionInfo> GetIntersection(const Ray& ray) const = 0;

protected: 
	vec3 position;
};

