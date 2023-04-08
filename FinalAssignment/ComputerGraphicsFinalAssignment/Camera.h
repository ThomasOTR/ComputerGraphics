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

	/* A property which hold the current Mode; */
	CameraMode CurrentMode;

	/* A property which holds the values of the walk mode; */
	CameraMode WalkMode = CameraMode(glm::vec3(2.0, 0.7, 7.0),ModeType::Walk, 0.1);
	
	/* A property which holds the values of the DroneMode; */
	CameraMode DroneMode = CameraMode(glm::vec3(0.0, 8.0, 15.0), ModeType::Drone, 0.25);

	Camera();
	
	/// <summary>
	/// A method to calculate the view matrix based on Position, Front and Up of the CurrentMode
	/// </summary>
	void CalculateViewMatrix();

	/// <summary>
	/// A method to calculate the projection matrix based on FOV and screen size
	/// </summary>
	void CalculateProjectionMatrix();

	/// <summary>
	/// A method to update the camera vectors based on movement
	/// </summary>
	void UpdateCameraVectors();

	/// <summary>
	/// A method to switch the Camera Mode. This method will only be triggered by the InputHandler
	/// </summary>
	void SwitchMode();
};

