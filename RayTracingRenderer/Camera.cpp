#include "stdafx.h"
#include "Camera.h"

Camera::Camera(const vec3& pos, const vec3& dir) 
{
	position = pos;
	direction = dir;
}

const vec3& Camera::GetPosition()
{
	return position;
}

void Camera::TranslatePosition(vec3 offset)
{
	position += offset;
}

void Camera::SetPosition(vec3 pos)
{
	position = pos;
}

const vec3& Camera::GetLookDirection()
{
	return direction;
}

Camera::~Camera()
{}
