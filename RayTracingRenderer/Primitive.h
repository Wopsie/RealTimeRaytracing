#pragma once
#include <memory>
#include "Transform.h"
//#include "IntersectionInfo.h"


//struct Transform;
class Ray;
struct IntersectionInfo;

class Primitive
{
public:
	std::shared_ptr<Transform> const GetTransform() { return transform; };
	virtual const bool GetIntersection(float& magnitude, const Ray& ray) const = 0;
	virtual void IntersectionDetails(const glm::vec3& collPos, IntersectionInfo& info) const = 0;

protected:
	std::shared_ptr<Transform> transform = std::make_shared<Transform>();
};

