#pragma once
#include "glm/vec3.hpp"
#include <memory>

class Primitive;

struct IntersectionInfo 
{
	//IntersectionInfo(/*std::shared_ptr<Primitive> a_pPrimitive, */float a_Magnitude, glm::vec3 a_Normal) :
	//	//pPrimitive(a_pPrimitive),
	//	intersectMagnitude(a_Magnitude),
	//	normal(a_Normal)
	//{}
	//const std::shared_ptr<Primitive> pPrimitive;
	float intersectMagnitude;
	glm::vec3 normal;
	glm::vec3 color;
};