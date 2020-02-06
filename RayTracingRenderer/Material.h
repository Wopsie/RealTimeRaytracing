#pragma once
#include "glm/vec3.hpp"

struct Material
{
	glm::vec3 color = glm::vec3(1,1,1);		//white by default
	bool isLight = false;
	float glossiness = 0.0f;

};

