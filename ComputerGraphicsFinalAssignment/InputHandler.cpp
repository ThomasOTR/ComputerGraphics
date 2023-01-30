#include "InputHandler.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <iostream>


Camera InputHandler::processKeyInput(Camera camera, unsigned char key)
{
	switch (key)
	{
	case 27:
		glutExit();
		break;
	case 'v':
		if (camera.mode == ViewMode::Walk) {
			camera.mode = ViewMode::Drone;
			camera.walkMode = camera.currentMode;
			camera.droneMode.projection = camera.walkMode.projection;
			camera.currentMode = camera.droneMode;
		}
		else if (camera.mode == ViewMode::Drone) {
			
			camera.mode = ViewMode::Walk;
			camera.droneMode = camera.currentMode;
			camera.currentMode = camera.walkMode;
		}
		break;
	case 'w':
		// Move Forward
		camera.currentMode.Pos += movementSpeed * camera.currentMode.Front;
		std::cout << glm::to_string(camera.currentMode.Pos) << std::endl;
		break;
	
	case 'a':
		// Move left
		camera.currentMode.Pos -= glm::normalize(glm::cross(camera.currentMode.Front, camera.currentMode.Up)) * movementSpeed;
		 std::cout << glm::to_string(camera.currentMode.Pos) << std::endl;
		break;
	case 's':
		// Move Backwards
		 camera.currentMode.Pos -= movementSpeed * camera.currentMode.Front;
		 std::cout << glm::to_string(camera.currentMode.Pos) << std::endl;
		break;
	case 'd':
		// Move right
		camera.currentMode.Pos += glm::normalize(glm::cross(camera.currentMode.Front, camera.currentMode.Up)) * movementSpeed;
		 std::cout << glm::to_string(camera.currentMode.Pos) << std::endl;

		break;
	case 'q': 
		if(camera.mode == ViewMode::Drone)
			camera.currentMode.Pos.y += movementSpeed;

		break;
	case 'e' :
		if (camera.mode == ViewMode::Drone)
			camera.currentMode.Pos.y -= movementSpeed;
		break;

	}
	return camera;
}

Camera InputHandler::processMouseInput(Camera camera, int x, int y)
{
	int lastMouseX = 400;
	int lastMouseY = 300;
	if (firstMouseMovement)
	{
		lastMouseX = x;
		lastMouseX = y;
		firstMouseMovement = false;
	}
	int offsetX = x - lastMouseX;
	int offsetY = y - lastMouseY;

	lastMouseX = x;
	lastMouseY = y;

	offsetX *= sensitivity;
	offsetY *= sensitivity;

	camera.currentMode.yaw += offsetX;
	camera.currentMode.pitch += offsetY;

	if (camera.currentMode.pitch > 89.0f)
		camera.currentMode.pitch = 89.0f;
	if (camera.currentMode.pitch < -89.0f)
		camera.currentMode.pitch = -89.0f;

	camera.updateCameraVectors();
	glutWarpPointer(400, 300);
	return camera;
}
