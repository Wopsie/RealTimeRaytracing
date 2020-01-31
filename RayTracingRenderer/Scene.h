#pragma once
#include "Camera.h"
#include "glm/matrix.hpp"
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
	const glm::mat4 sceneIdentity = glm::mat4(1.0);
	Camera camera;
};

