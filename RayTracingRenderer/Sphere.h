//#pragma once
//#include "glm/vec3.hpp"
//#include "glm/geometric.hpp"
//#include "Surface.h"
//#include "Material.h"
//struct ShadingInfo;
//struct IntersectionInfo;
//
//class Sphere : public Surface
//{
//public:
//	Sphere();
//	Sphere(const glm::vec3& pos, const float& rad, const int& id, const glm::vec3& ambient = glm::vec3(1, 1, 1));
//	Sphere(const glm::vec3& pos, const float& rad, const int& id, const Material& mat);
//	bool GetShadingInfo(const Ray& ray, ShadingInfo& info) const;
//	std::shared_ptr<IntersectionInfo> GetIntersection(const Ray& ray) const;
//	const Material& GetMaterial() const;
//	const int& GetIdentifier() const;
//	~Sphere();
//private:
//	float radius;
//};

#pragma once
#include "Primitive.h"
#include "glm/glm.hpp"
#include <memory>

class Sphere : public Primitive
{
public:
    Sphere(glm::vec3 a_Position, float a_Radius);
    Sphere(glm::vec3 a_Position, float a_Radius, glm::vec3 a_Color);
    virtual ~Sphere() = default;

    float m_Radius2;
    glm::vec3 m_Position;

    const bool GetIntersection(float& a_T, const Ray& ray) const;
    void IntersectionDetails(const glm::vec3& collPos, IntersectionInfo& info) const;
    glm::vec3 matColor = glm::vec3(1, 1, 1);

protected:
};
