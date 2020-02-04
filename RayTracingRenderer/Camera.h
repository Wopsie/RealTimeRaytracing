#pragma once
#include "Transform.h"
#include "glm/vec3.hpp"
#include "glm/matrix.hpp"

class Camera
{
public:
	Camera() {};
	Camera(const glm::vec3& pos, const glm::vec3& dir);
	const glm::vec3& GetPosition();
	void TranslatePosition(glm::vec3 offset);
	void SetPosition(glm::vec3 pos);

	Transform& GetTransform() { return transform; };

	const glm::vec3& GetLookDirection();
	~Camera();

private:
	glm::vec3 position = glm::vec3();
	glm::vec3 direction = glm::vec3();
	glm::mat4 frustum;
	Transform transform;
};

