#include "stdafx.h"
#include "BoundingSphere.h"
#include "IntersectionInfo.h"
#include "ShadingInfo.h"
#include "Ray.h"
#include "Material.h"

//BoundingSphere::BoundingSphere()
//{
	//pass along hitable objects to put inside the volumeContents array
//}


BoundingSphere::BoundingSphere(const glm::vec3 & pos, const float & rad, std::vector<Hitable*> elements)
{
	position = pos;
	radius = rad;
	volumeContents = elements;
}

bool BoundingSphere::GetIntersection(const Ray & ray, ShadingInfo & info) const
{
	info.hit = false;
	//The length on the ray to the point closest to the sphere
	float magnitude = dot(ray.GetDirection(), (position - ray.GetOrigin()));
	if (magnitude > 0)
	{
#pragma warning (push)
#pragma warning ( disable : 4244)
		//Get the distance between the point along the ray at length and the sphere center
		float distanceToSphere = (position - ray.PointOnLineAt(magnitude)).length();
#pragma warning (pop)
		if (distanceToSphere < radius)
		{
			//The ray has hit the bounding sphere

			const float centerToSurfaceDist = sqrtf(powf(radius, 2) - powf(distanceToSphere, 2));
			const float legnthToEdge = magnitude - centerToSurfaceDist;
			if (legnthToEdge < ray.GetMaxRange())
			{
				info.distance = legnthToEdge;
				info.hit = true;
				info.renderable = false;
			}
		}
	}

	return info.hit;
}

const std::vector<Hitable*> BoundingSphere::GetVolumeContent() const
{
	return volumeContents;
}