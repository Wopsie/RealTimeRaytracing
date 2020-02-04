#pragma once
#include <memory>
class Transform;
class Ray;

class Primitive
{
public:
	std::shared_ptr<Transform> const GetTransform() { return transform; };
	virtual bool GetIntersection(const Ray& ray) const = 0;

private:
	std::shared_ptr<Transform> transform = std::make_shared<Transform>();
};

