#pragma once
#include "stdafx.h"
#include "Ray.h"
#include <assert.h>

Ray::Ray(glm::vec3 pos, glm::vec3 dir)
	:
	origin(pos),
	direction(dir),
	range(INFINITY)
{}

Ray::Ray(glm::vec3 pos, glm::vec3 dir, const float & distance)
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

void Ray::SetOrigin(glm::vec3 o)
{
	origin = o;
}

void Ray::SetDirection(glm::vec3 d)
{
	direction = d;
}

Ray::~Ray()
{}
