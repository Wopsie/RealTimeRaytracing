#pragma once
#include "glm/vec3.hpp"
#include "glm/geometric.hpp"

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
	LightSource(const glm::vec3& pos, const glm::vec3& dir, const glm::vec3& tint = glm::vec3(1,1,1), LightType t = LightType::Point);
	const glm::vec3& GetPosition() const;
	const glm::vec3 GetDirection(const glm::vec3& point) const;
	const LightType& GetType() const;
	const glm::vec3& GetColor() const;
	const float& GetRange() const;
	const glm::vec3& GetIntensity() const;
	~LightSource();

private:
	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 color = glm::vec3(1,1,1);	//white by default
	float range = 0;
	glm::vec3 intensity = glm::vec3(1,1,1);
	LightType type;
};

