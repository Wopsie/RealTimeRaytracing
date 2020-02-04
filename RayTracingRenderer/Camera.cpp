#include "stdafx.h"
#include "Camera.h"
#include "Transform.h"

Camera::Camera(const glm::vec3& pos, const glm::vec3& dir) 
{
	transform = std::make_shared<Transform>();
	//dir;
	transform->Translate(pos);
	transform->Rotate(dir);
}

Camera::~Camera()
{}
