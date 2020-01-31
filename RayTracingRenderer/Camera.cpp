#include "stdafx.h"
#include "Camera.h"

Camera::Camera(const glm::vec3& pos, const glm::vec3& dir) 
{
	position = pos;
	direction = dir;
}

const glm::vec3& Camera::GetPosition()
{
	return position;
}

void Camera::TranslatePosition(glm::vec3 offset)
{
	position += offset;
}

void Camera::SetPosition(glm::vec3 pos)
{
	position = pos;
}

const glm::vec3& Camera::GetLookDirection()
{
	return direction;
}

Camera::~Camera()
{}
