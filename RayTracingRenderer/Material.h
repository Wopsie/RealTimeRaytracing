#pragma once
#include "glm/vec3.hpp"

struct Material
{
	glm::vec3 albedo = glm::vec3(1,1,1);		//white by default
	glm::vec3 emittance = albedo;
	bool isLight = false;
	bool isMirror = false;
	float glossiness = 0.0f;
	
};

