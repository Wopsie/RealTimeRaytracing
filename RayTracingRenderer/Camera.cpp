#include "stdafx.h"
#include "Camera.h"

Camera::Camera(const glm::vec3& pos, const glm::vec3& dir) 
{
	//transform = Transform();
	position = pos;
	direction = dir;
}

const glm::vec3& Camera::GetPosition()
{
	return position;
}

void Camera::TranslatePosition(glm::vec3 offset)
{
	position += (offset * 100.f);
}

void Camera::SetPosition(glm::vec3 pos)
{
	position = pos;
}

const glm::vec3& Camera::GetLookDirection()
{
	//glm::mat4 mat;
	return direction;
}

Camera::~Camera()
{}
