#pragma once
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "CameraMode.h"
enum class ViewMode {
	Walk,
	Drone
};
class Camera
{
public:
	ViewMode mode = ViewMode::Walk;

	CameraMode walkMode;
	CameraMode droneMode = CameraMode(glm::vec3(1.0, 1.0, 1.0), -90.0, 0.0);
	CameraMode currentMode = walkMode;

	Camera() = default;
	void CalculateViewMatrix();
	void CalculateProjectionMatrix();
	void updateCameraVectors();
};

