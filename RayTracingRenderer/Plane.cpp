#include "stdafx.h"
#include "Plane.h"
#include "IntersectionInfo.h"
#include "Ray.h"
#include "Surface.h"
#include "Material.h"
#include <cmath>

Plane::Plane()
	: Surface(1)
{
	position = vec3();
	normal = vec3(0, -1, 0);
}

Plane::Plane(const vec3 & pos, const vec3 & inclination, const int& id, const Material & mat)
	: Surface(id)
{
	position = pos;
	normal = inclination;
	material = mat;
}

Plane::Plane(const vec3 & pos, const vec3 & inclination, const int& id, const vec3& ambient)
	: Surface(id)
{
	position = pos;
	normal = inclination;
	material = Material();
	material.color = ambient;
}

bool Plane::GetIntersection(const Ray & ray, IntersectionInfo & info) const
{
	info.hit = false;
	//check if intersection is happening at all
	float f = normal.dot(ray.GetDirection());
	if (f <= 0) 
	{
		float planeDot = normal.dot(position);
		float magnitude = (planeDot - normal.dot(ray.GetOrigin())) / normal.dot(ray.GetDirection());
		if (magnitude < ray.GetMaxRange())
		{
			info.normal = normal;
			info.position = ray.PointOnLineAt(magnitude);
			info.distance = (ray.GetOrigin() - ray.PointOnLineAt(magnitude)).length();
			info.material = GetMaterial();
			info.surface = this;
			info.hit = true;
			info.renderable = true;
		}
	}
	return info.hit;
}

const Material & Plane::GetMaterial() const
{
	return material;
}

const int & Plane::GetIdentifier() const
{
	return objID;
}
