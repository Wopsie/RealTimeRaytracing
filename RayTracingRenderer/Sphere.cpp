#include "stdafx.h"
#include "Sphere.h"
#include "Ray.h"
#include "IntersectionInfo.h"
#include "Material.h"
#include <cmath>

Sphere::Sphere()
	: Surface(1)
{
	position = vec3();
	radius = 1;
}

Sphere::Sphere(const vec3& pos, const float& rad, const int& id, const vec3& ambient)
	: Surface(id)
{
	position = pos;
	radius = rad;
	material = Material();
	material.color = ambient;
}

Sphere::Sphere(const vec3 & pos, const float & rad, const int& id, const Material & mat)
	: Surface(id)
{
	position = pos;
	radius = rad;
	material = mat;
}

bool Sphere::GetIntersection(const Ray & ray, IntersectionInfo & info) const
{
	info.hit = false;
	//The length on the ray to the point closest to the sphere
	float magnitude = ray.GetDirection().dot(position - ray.GetOrigin());
	if (magnitude > 0)
	{
		//Get the distance between the point along the ray at length and the sphere center
		float distanceToSphere = (position - ray.PointOnLineAt(magnitude)).length();
		if (distanceToSphere < radius)
		{
			//The ray has hit this object
			const float centerToSurfaceDist = sqrtf(powf(radius, 2) - powf(distanceToSphere, 2));
			const float lengthToSurface = magnitude - centerToSurfaceDist;
			if (lengthToSurface < ray.GetMaxRange())
			{
				info.position = ray.PointOnLineAt(lengthToSurface);
				info.normal = (ray.PointOnLineAt(lengthToSurface) - position).normalize();
				info.mirrorPosition = ray.PointOnLineAt(lengthToSurface);
				info.mirrorNormal = (position - info.mirrorPosition).normalize();
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

