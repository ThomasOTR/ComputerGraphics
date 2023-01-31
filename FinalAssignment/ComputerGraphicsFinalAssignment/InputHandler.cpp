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
		camera.SwitchMode();
		break;
	case 'w':
		// Move Forward
		camera.CurrentMode.Pos += movementSpeed * camera.CurrentMode.Front;
		std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	
	case 'a':
		// Move left
		camera.CurrentMode.Pos -= glm::normalize(glm::cross(camera.CurrentMode.Front, camera.CurrentMode.Up)) * movementSpeed;
		 std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	case 's':
		// Move Backwards
		 camera.CurrentMode.Pos -= movementSpeed * camera.CurrentMode.Front;
		 std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	case 'd':
		// Move right
		camera.CurrentMode.Pos += glm::normalize(glm::cross(camera.CurrentMode.Front, camera.CurrentMode.Up)) * movementSpeed;
		 std::cout << glm::to_string(camera.CurrentMode.Pos) << std::endl;
		break;
	case 'q': 
		if(camera.CurrentMode.Mode == ModeType::Drone)
			camera.CurrentMode.Pos.y += movementSpeed;
		break;
	case 'e' :
		if (camera.CurrentMode.Mode == ModeType::Drone)
			camera.CurrentMode.Pos.y -= movementSpeed;
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
