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

	void Translate(glm::vec3 translationVector) {
		modelMat = glm::translate(modelMat, translationVector);
	};

	void Rotate(glm::vec3 rotationVector) {
		modelMat = glm::rotate(modelMat, static_cast<float>(rotationVector.length()), glm::normalize(rotationVector));
	}
	
	glm::mat4 modelMat = glm::mat4(1.0);
};