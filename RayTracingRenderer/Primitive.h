#pragma once
#include <memory>
#include "Transform.h"


//struct Transform;
class Ray;

class Primitive
{
public:
	std::shared_ptr<Transform> const GetTransform() { return transform; };
	virtual bool GetIntersection(float& magnitude, const Ray& ray) = 0;

protected:
	std::shared_ptr<Transform> transform = std::make_shared<Transform>();
};

