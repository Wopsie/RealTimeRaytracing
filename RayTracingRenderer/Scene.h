#pragma once
#include "Camera.h"
#include <vector>
#include <iostream>
class Surface;
class LightSource;
class BoundingVolume;
struct Scene
{
	Scene() { std::cout << "New Scene" << std::endl; };
	std::vector<Surface*> surfaceList;
	std::vector<LightSource> lightsList;
	const float ambientLightIntensity = 0.03f;
	const float baseRefractiveIndex = 1.2f;
	Camera camera;
};

