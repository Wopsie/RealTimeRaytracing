#pragma once
#include "MathLibrary.h"


//enum class something to look up
enum class CamType
{
	Orthographic,
	Perspective,
};

class Camera
{
public:
	Camera() {};
	Camera(const vec3& pos, const vec3& dir);
	const vec3& GetPosition();
	const vec3& GetLookDirection();
	~Camera();

private:
	vec3 position;
	vec3 direction;
};
