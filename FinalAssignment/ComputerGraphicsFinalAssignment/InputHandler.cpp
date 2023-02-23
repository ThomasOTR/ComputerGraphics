#include "InputHandler.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <iostream>


glm::vec3 InputHandler::CalculateLeftRightMovement(Camera camera)
{
	return glm::normalize(glm::cross(camera.CurrentMode.Front, camera.CurrentMode.Up)) * movementSpeed;
}

glm::vec3 InputHandler::CalculateForwardBackwardMovement(Camera camera)
{
	return movementSpeed * camera.CurrentMode.Front;
}

Camera InputHandler::processKeyInput(Camera camera, unsigned char key)
{
	key = std::tolower(key);
	switch (key)
	{
	case 27: /* ESC */
		glutExit();
		break;
	case 'v':
		camera.SwitchMode();
		break;
	case 'w':
		// Move Forward
		camera.CurrentMode.Pos.x += CalculateForwardBackwardMovement(camera).x;
		camera.CurrentMode.Pos.z += CalculateForwardBackwardMovement(camera).z;

		std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	
	case 'a':
		// Move left
		camera.CurrentMode.Pos.x -= CalculateLeftRightMovement(camera).x;
		camera.CurrentMode.Pos.z -= CalculateLeftRightMovement(camera).z;
		std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	case 's':
		// Move Backwards
		camera.CurrentMode.Pos.x -= CalculateForwardBackwardMovement(camera).x;
		camera.CurrentMode.Pos.z -= CalculateForwardBackwardMovement(camera).z;
		std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	case 'd':
		// Move right
		camera.CurrentMode.Pos.x += CalculateLeftRightMovement(camera).x;
		camera.CurrentMode.Pos.z += CalculateLeftRightMovement(camera).z;
		std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	case 'q': 
		if(camera.CurrentMode.Mode == ModeType::Drone)
			camera.CurrentMode.Pos.y += movementSpeed;
		break;
	case 'e' :
		if (camera.CurrentMode.Mode == ModeType::Drone)
		{
			camera.CurrentMode.Pos.y -= movementSpeed;
			if (camera.CurrentMode.Pos.y < 0.5) camera.CurrentMode.Pos.y = 0.5;
		}
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

	camera.CurrentMode.yaw += offsetX;
	camera.CurrentMode.pitch += offsetY;

	if (camera.CurrentMode.pitch > 89.0f)
		camera.CurrentMode.pitch = 89.0f;
	if (camera.CurrentMode.pitch < -89.0f)
		camera.CurrentMode.pitch = -89.0f;

	camera.UpdateCameraVectors();
	glutWarpPointer(400, 300);
	return camera;
}
