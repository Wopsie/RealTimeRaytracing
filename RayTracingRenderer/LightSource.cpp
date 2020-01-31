#include "stdafx.h"
#include "LightSource.h"

LightSource::LightSource()
{
	position = glm::vec3();
	direction = glm::vec3();
	type = LightType::Point;
}

LightSource::LightSource(const glm::vec3 & pos, const glm::vec3 & dir, const glm::vec3& tint, LightType t)
{
	position = pos;
	direction = dir;
	color = tint;
	type = t;
}

const glm::vec3& LightSource::GetPosition() const
{
	return position;
}

const glm::vec3 LightSource::GetDirection(const glm::vec3& point) const
{
	switch (GetType())
	{
	case LightType::Directional:
		return -direction;
		break;
	case LightType::Point:
		return normalize(position - point);
		break;
	case LightType::Spot:
		return normalize(position - point);//place holder
		break;
	case LightType::Ambient:
		return glm::vec3();
		break;
	default:
		return normalize(position - point);
		break;
	}
}

const LightType & LightSource::GetType() const
{
	return type;
}

const glm::vec3 & LightSource::GetColor() const
{
	return color;
}

const float & LightSource::GetRange() const
{
	return range;
}

const glm::vec3 & LightSource::GetIntensity() const
{
	return intensity;
}

LightSource::~LightSource()
{
}
