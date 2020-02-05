//#pragma once
//#include "Surface.h"
//#include "glm/vec3.hpp"
//#include "glm/geometric.hpp"
//#include "Material.h"
//struct ShadingInfo;
//struct IntersectionInfo;
//
//class Plane : public Surface
//{
//public:
//	Plane();
//	Plane(const glm::vec3& pos, const glm::vec3& inclination, const int& id, const Material& mat);
//	Plane(const glm::vec3& pos, const glm::vec3& inclination, const int& id, const glm::vec3& ambient = glm::vec3(1,1,1));
//	bool GetShadingInfo(const Ray& ray, ShadingInfo& info) const;
//	std::shared_ptr<IntersectionInfo> GetIntersection(const Ray& ray) const;
//	const Material& GetMaterial() const;
//	const int& GetIdentifier() const;
//
//private:
//	glm::vec3 normal;
//};
