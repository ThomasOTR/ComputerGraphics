#pragma once
#include <glm/glm.hpp>

/// <summary>
/// An enum to seperate different modes of the Camera.
/// </summary>
enum class ModeType {
	Walk,
	Drone
};

/// <summary>
/// A class to store everything related to a CameraMode which can be switched out in the camera
/// </summary>
class CameraMode
{
public:
	/* Properties to calculate the view and projection */
	glm::vec3 Pos;
	glm::vec3 Front = glm::vec3(-4.0, 0.0, -14.0);
	glm::vec3 Up = glm::vec3(0.0, 1.0, 0.0);
	glm::vec3 Right;
	glm::vec3 WorldUp = Up;
	float yaw = -90.0f;
	float pitch = 0.0f;
	float FOV = 45.0f;

	
	glm::mat4 view;
	glm::mat4 projection;

	/* The mode of the Camera */
	ModeType Mode;
	
	CameraMode();
	CameraMode(glm::vec3,ModeType);
};

