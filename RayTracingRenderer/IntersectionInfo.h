#pragma once
#include "glm/vec3.hpp"
#include <memory>

class Primitive;

struct IntersectionInfo 
{
	IntersectionInfo(std::shared_ptr<Primitive> a_pPrimitive, float a_Magnitude) :
		pPrimitive(a_pPrimitive),
		intersectMagnitude(a_Magnitude)
	{}
	const std::shared_ptr<Primitive> pPrimitive;
	const float intersectMagnitude;
};