#pragma once
#include "MathLibrary.h"
#include "Material.h"
#include "Surface.h"

struct IntersectionInfo
{
	//false if no intersection was found
	bool hit;
	//The normal at the intersection
	vec3 normal;
	//The position of the intersection
	vec3 position;
	//The position at which ray exits the surface
	vec3 mirrorPosition;
	//The inverse normal at which ray exits the surface (inwards facing)
	vec3 mirrorNormal;
	//The distance between point and the ray that intersected
	float distance = -1.0f;
	//base color at intersection
	Material material;
	//const reference to surface that this info relates to
	const Surface* surface = nullptr;
	//false if surface is invisible like a bounding volume
	bool renderable;
};
