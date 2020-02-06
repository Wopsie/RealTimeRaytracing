#include "stdafx.h"
#include "Plane.h"
#include "IntersectionInfo.h"
#include "Ray.h"


Plane::Plane(glm::vec3 a_Origin, glm::vec3 a_Normal)
{
	origin = a_Origin;
	normal = glm::normalize(a_Normal);

	//temporary
	white->albedo = glm::vec3(0.5f, 0.5f, 0.5f);
	black->albedo = glm::vec3(0.1f, 0.1f, 0.1f);
}

const bool Plane::GetIntersection(float& magnitude, const Ray& ray) const
{
	const float denominator = glm::dot(ray.GetDirection(), normal);
	if (const float t = glm::dot((origin - ray.GetOrigin()), normal) / denominator; t < magnitude && t > 0) {
		magnitude = t;
	}
	return (magnitude > FLT_EPSILON);
}

void Plane::IntersectionDetails(const glm::vec3& collPos, IntersectionInfo& info) const
{
	info.normal = normal;
	//collPos;
	//round collpos to interger. Check with modulo if int is even or not. just alternate the colors based on that

	//checkerboard business. Doesnt really work well when rotating plane. should use local coordinates
	int x = static_cast<int>(roundf(collPos.x));
	int z = static_cast<int>(roundf(collPos.z));

	if (!(x % 2) == !(z % 2)) {
		info.mat = *black;
	}
	else {
		info.mat = *white;
	}
}
