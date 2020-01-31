#pragma once
#include "stdafx.h"
#include "Ray.h"
#include <assert.h>

Ray::Ray(const glm::vec3& pos, const glm::vec3& dir)
	:
	origin(pos),
	direction(dir),
	range(INFINITY)
{}

Ray::Ray(const glm::vec3 & pos, const glm::vec3 & dir, const float & distance)
	:
	origin(pos),
	direction(dir),
	range(distance)
{}


const float & Ray::GetMaxRange() const
{
	return range;
}

const glm::vec3& Ray::GetOrigin() const
{
	return origin;
}

const glm::vec3& Ray::GetDirection() const
{
	return direction;
}

const glm::vec3 Ray::PointOnLineAt(float magnitude) const
{
	const glm::vec3 point = origin + (direction * magnitude);
	return point;
}

Ray::~Ray()
{}
