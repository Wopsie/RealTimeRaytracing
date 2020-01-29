#pragma once
#include "MathLibrary.h"

class Ray
{
public:
	Ray(const vec3& pos, const vec3& dir);
	Ray(const vec3& pos, const vec3& dir, const float& distance = INFINITY);
	const vec3& GetOrigin() const;
	const vec3& GetDirection() const;
	const float& GetMaxRange() const;
	const vec3 PointOnLineAt(float magnitude) const;
	~Ray();
private:
	const vec3 direction;
	const vec3 origin;
	const float range;
};

