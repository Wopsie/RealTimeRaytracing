#pragma once
#include "glm/vec3.hpp"

struct Material
{
	glm::vec3 color = glm::vec3(1,1,1);		//white by default
	bool opaque = true;				//opaque/solid/non-refractive by default
	bool reflective = false;		//not reflective by default
	float glossiness = 0.0f;		//diffuse by default
	float specular = 1.0f;			//brightest by default
	float refractIndex = 1.2f;		//roughly window glass by default
};

