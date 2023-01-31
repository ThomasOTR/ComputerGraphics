#pragma once
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "CameraMode.h"

/// <summary>
/// A class to handle everything about the view and projection
/// </summary>
class Camera
{
public:
	/// <summary>
	/// A property which hold the current Mode;
	/// </summary>
	CameraMode CurrentMode;

	/// <summary>
	/// A property which holds the values of the walk mode.
	/// </summary>
	CameraMode WalkMode = CameraMode(glm::vec3(2.0, 1.0, 7.0),ModeType::Walk);
	
	/// <summary>
	/// A property which holds the values of the DroneMode;
	/// </summary>
	CameraMode DroneMode = CameraMode(glm::vec3(1.0, 1.0, 1.0), ModeType::Drone);

	Camera();
	
	/// <summary>
	/// A method to calculate the view matrix based on Position, Front and Up of the CurrentMode
	/// </summary>
	void CalculateViewMatrix();

	/// <summary>
	/// A method to calculate the projection matrix based on FOV and screen size;
	/// </summary>
	void CalculateProjectionMatrix();

	/// <summary>
	/// A method to update the camera vectors based on movement.
	/// </summary>
	void UpdateCameraVectors();
	void SwitchMode();
};

