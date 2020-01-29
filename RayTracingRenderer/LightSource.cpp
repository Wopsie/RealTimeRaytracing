#include "stdafx.h"
#include "LightSource.h"

LightSource::LightSource()
{
	position = vec3();
	direction = vec3();
	type = LightType::Point;
}

LightSource::LightSource(const vec3 & pos, const vec3 & dir, const vec3& tint, LightType t)
{
	position = pos;
	direction = dir;
	color = tint;
	type = t;
}

const vec3& LightSource::GetPosition() const
{
	return position;
}

const vec3 LightSource::GetDirection(const vec3& point) const
{
	switch (GetType())
	{
	case LightType::Directional:
		return direction.invert();
		break;
	case LightType::Point:
		return (position - point).normalize();
		break;
	case LightType::Spot:
		return (position - point).normalize();//place holder
		break;
	case LightType::Ambient:
		return vec3();
		break;
	default:
		return (position - point).normalize();
		break;
	}
}

const LightType & LightSource::GetType() const
{
	return type;
}

const vec3 & LightSource::GetColor() const
{
	return color;
}

const float & LightSource::GetRange() const
{
	return range;
}

const vec3 & LightSource::GetIntensity() const
{
	return intensity;
}

LightSource::~LightSource()
{
}
