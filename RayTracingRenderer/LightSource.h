#pragma once
#include "MathLibrary.h"

enum class LightType
{
	Spot,
	Point,
	Directional,
	Ambient,
};

class LightSource
{
public:
	LightSource();
	LightSource(const vec3& pos, const vec3& dir, const vec3& tint = vec3(1,1,1), LightType t = LightType::Point);
	const vec3& GetPosition() const;
	const vec3 GetDirection(const vec3& point) const;
	const LightType& GetType() const;
	const vec3& GetColor() const;
	const float& GetRange() const;
	const vec3& GetIntensity() const;
	~LightSource();

private:
	vec3 position;
	vec3 direction;
	vec3 color = vec3(1,1,1);	//white by default
	float range;
	vec3 intensity = vec3(1,1,1);
	LightType type;
};

