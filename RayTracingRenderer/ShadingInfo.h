#pragma once
#include "glm/vec3.hpp"
#include "Material.h"
#include "Surface.h"

struct ShadingInfo
{
	//false if no intersection was found
	bool hit = false;
	//The normal at the intersection
	glm::vec3 normal = glm::vec3();
	//The position of the intersection
	glm::vec3 position = glm::vec3();
	//The position at which ray exits the surface
	glm::vec3 mirrorPosition = glm::vec3();
	//The inverse normal at which ray exits the surface (inwards facing)
	glm::vec3 mirrorNormal = glm::vec3();
	//The distance between point and the ray that intersected
	float distance = -1.0f;
	//base color at intersection
	Material material;
	//const reference to surface that this info relates to
	const Surface* surface = nullptr;
	//false if surface is invisible like a bounding volume
	bool renderable = true;
};
