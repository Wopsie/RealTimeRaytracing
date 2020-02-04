#pragma once
#include "glm/glm.hpp"
#include "glm/geometric.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/matrix.hpp"
#include "glm/gtc/matrix_transform.hpp"

//essentially just a wrapper for a couple of glm functions
struct Transform {
	
	Transform(glm::mat4 orientation = glm::mat4(1.0)) { modelMat = orientation; };
	/*Transform(glm::vec3 position = glm::vec3(), glm::vec4 lookDir = glm::vec4()) 
	{
		Translate(position);
		lookDir;
	}*/

	void Translate(glm::vec3 translationVector) {
		modelMat = glm::translate(modelMat, translationVector);

		/*modelMat *= glm::mat4(
			glm::vec4(1, 0, 0, 0),
			glm::vec4(0, 1, 0, 0),
			glm::vec4(0, 0, 1, 0),
			glm::vec4(translationVector, 1));*/
	};

	void Rotate(glm::vec3 rotationVector) {
		modelMat = glm::rotate(modelMat, static_cast<float>(rotationVector.length()), glm::normalize(rotationVector));
	}

	/*void SetPosition(glm::vec3 pos) 
	{
		modelMat = glm::mat4(
			glm::vec4(modelMat[0], modelMat[0]., modelMat[0], modelMat[0]),
			glm::vec4(0, 1, 0, 0),
			glm::vec4(0, 0, 1, 0),
			glm::vec4(translationVector, 1));
	}*/

	//void LookAtPoint(glm::vec3 rotationVector) 
	//{
	//	//glm::lookAt()
	//}
	
	glm::mat4 modelMat = glm::mat4(1.0);
};