#pragma once
#include <memory>
#include "glm/vec3.hpp"
#include "glm/matrix.hpp"
//#include "Transform.h"

struct Transform;

class Camera
{
public:
	Camera() {};
	Camera(const glm::vec3& pos, const glm::vec3& dir);
	/*const glm::vec3& GetPosition();
	void TranslatePosition(glm::vec3 offset);
	void SetPosition(glm::vec3 pos);*/

	std::shared_ptr<Transform> GetTransform() { return transform; };
	//inline const bool& GetIsMoving() { return isMoving; };
	bool isMoving = false;

	//const glm::vec3& GetLookDirection();
	~Camera();
private:
	//Transform transform;
	std::shared_ptr<Transform> transform;
};

