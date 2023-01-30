#pragma once
#include <glm/glm.hpp>

class CameraMode
{
public:
	glm::vec3 Pos = glm::vec3(2.0, 1.0, 7.0);
	glm::vec3 Front = glm::vec3(-4.0, 0.0, -14.0);
	glm::vec3 Up = glm::vec3(0.0, 1.0, 0.0);
	glm::vec3 Right;
	glm::vec3 WorldUp = Up;
	// yaw and pitch
	float yaw = -90.0f;
	float pitch = 0.0f;
	float FOV = 45.0f;
	glm::mat4 view;
	glm::mat4 projection;
	
	CameraMode() = default;
	CameraMode(glm::vec3, float, float);
};

