#include "stdafx.h"
#include "Sphere.h"
#include "Ray.h"
#include "ShadingInfo.h"
#include "IntersectionInfo.h"
#include "Material.h"
#include "Surface.h"
#include <cmath>

Sphere::Sphere()
	: Surface(1)
{
	position = glm::vec3();
	radius = 1;
}

Sphere::Sphere(const glm::vec3& pos, const float& rad, const int& id, const glm::vec3& ambient)
	: Surface(id)
{
	position = pos;
	radius = rad;
	material = Material();
	material.color = ambient;
}

Sphere::Sphere(const glm::vec3 & pos, const float & rad, const int& id, const Material & mat)
	: Surface(id)
{
	position = pos;
	radius = rad;
	material = mat;
}

bool Sphere::GetShadingInfo(const Ray & ray, ShadingInfo & info) const
{
	info.hit = false;
	//The length on the ray to the point closest to the sphere
	float magnitude = dot(ray.GetDirection(), position - ray.GetOrigin());
	if (magnitude > 0)
	{
#pragma warning (push)
#pragma warning ( disable : 4244)
		//Get the distance between the point along the ray at length and the sphere center
		float distanceToSphere = (position - ray.PointOnLineAt(magnitude)).length();
#pragma warning(pop)
		if (distanceToSphere < radius)
		{
			//The ray has hit this object
			const float centerToSurfaceDist = sqrtf(powf(radius, 2) - powf(distanceToSphere, 2));
			const float lengthToSurface = magnitude - centerToSurfaceDist;
			if (lengthToSurface < ray.GetMaxRange())
			{
				info.position = ray.PointOnLineAt(lengthToSurface);
				info.normal = normalize(ray.PointOnLineAt(lengthToSurface) - position);
				info.mirrorPosition = ray.PointOnLineAt(lengthToSurface);
				info.mirrorNormal = normalize(position - info.mirrorPosition);
				info.distance = lengthToSurface;
				info.material = GetMaterial();
				info.surface = this;
				info.hit = true;
				info.renderable = true;
			}
		}
	}

	return info.hit;
}

std::shared_ptr<IntersectionInfo> Sphere::GetIntersection(const Ray& ray) const
{
	//The length on the ray to the point closest to the sphere
	float magnitude = dot(ray.GetDirection(), (position - ray.GetOrigin()));	//goes wrong here
	if (magnitude > 0)
	{
#pragma warning (push)
#pragma warning ( disable : 4244)
		//Get the distance between the point along the ray at length and the sphere center
		float distanceToSphere = (position - ray.PointOnLineAt(magnitude)).length();
#pragma warning(pop)
		if (distanceToSphere < radius)
		{
			//The ray has hit this object
			const float centerToSurfaceDist = sqrtf(powf(radius, 2) - powf(distanceToSphere, 2));
			const float lengthToSurface = magnitude - centerToSurfaceDist;
			if (lengthToSurface < ray.GetMaxRange())
			{
				std::shared_ptr<IntersectionInfo> ii = std::make_shared<IntersectionInfo>();
				ii->pSurface = this;
				ii->distToRayOrigin = lengthToSurface;
				ii->intersectPos = ray.PointOnLineAt(lengthToSurface);
				return ii;
			}
		}
	}
	return nullptr;
}

const Material& Sphere::GetMaterial() const
{
	return material;
}

const int & Sphere::GetIdentifier() const
{
	return objID;
}

Sphere::~Sphere()
{
}

