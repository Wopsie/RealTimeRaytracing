#include "stdafx.h"
#include "Plane.h"
#include "IntersectionInfo.h"
#include "ShadingInfo.h"
#include "Ray.h"
#include "Surface.h"
#include "Material.h"
#include <cmath>

Plane::Plane()
	: Surface(1)
{
	position = glm::vec3();
	normal = glm::vec3(0, -1, 0);
}

Plane::Plane(const glm::vec3 & pos, const glm::vec3 & inclination, const int& id, const Material & mat)
	: Surface(id)
{
	position = pos;
	normal = inclination;
	material = mat;
}

Plane::Plane(const glm::vec3 & pos, const glm::vec3 & inclination, const int& id, const glm::vec3& ambient)
	: Surface(id)
{
	position = pos;
	normal = inclination;
	material = Material();
	material.color = ambient;
}

bool Plane::GetShadingInfo(const Ray & ray, ShadingInfo & info) const
{
	info.hit = false;
	//check if intersection is happening at all
	float f = dot(normal, ray.GetDirection());
	if (f <= 0) 
	{
#pragma warning (push)
#pragma warning ( disable : 4244)
		float planeDot = dot(normal, position);
		float magnitude = dot(planeDot - normal, ray.GetOrigin()) / dot(normal, ray.GetDirection());
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
#pragma warning (pop)
	return info.hit;
}

std::shared_ptr<IntersectionInfo> Plane::GetIntersection(const Ray& ray) const
{
	//check if intersection is happening at all
	float f = dot(normal, ray.GetDirection());
	if (f <= 0) 
	{
#pragma warning (push)
#pragma warning ( disable : 4244)
		float planeDot = dot(normal, position);
		float magnitude = dot(planeDot - normal, ray.GetOrigin()) / dot(normal, ray.GetDirection());
		if (magnitude < ray.GetMaxRange())
		{
			std::shared_ptr<IntersectionInfo> ii = std::make_shared<IntersectionInfo>();
			ii->pSurface = this;
			ii->distToRayOrigin = (ray.GetOrigin() - ray.PointOnLineAt(magnitude)).length();
			ii->intersectPos = ray.PointOnLineAt(magnitude);
			return ii;
		}
	}
#pragma warning (pop)
	return nullptr;
}

const Material & Plane::GetMaterial() const
{
	return material;
}

const int & Plane::GetIdentifier() const
{
	return objID;
}
