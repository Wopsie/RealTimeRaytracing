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
#include "glm/glm.hpp"

class Sphere
{
public:
    Sphere(glm::vec3 a_Position, float a_Radius);
    virtual ~Sphere() = default;

    float m_Radius2;
    glm::vec3 m_Position;

    void IntersectSphere(float& a_T, const glm::vec3& a_Origin, const glm::vec3& a_Direction)
    {
        glm::vec3 C = m_Position - a_Origin;
        float t = glm::dot(C, a_Direction);
        glm::vec3 Q = C - t * a_Direction;
        float p2 = glm::dot(Q, Q);
        if (p2 > m_Radius2) return; // r2 = r * r
        t -= sqrt(m_Radius2 - p2);
        if ((t < a_T) && (t > 0)) a_T = t;
    }
};

inline Sphere::Sphere(glm::vec3 a_Position, float a_Radius)
{
    m_Position = a_Position;
    m_Radius2 = a_Radius * a_Radius;
}