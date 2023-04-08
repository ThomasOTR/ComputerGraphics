#include "InputHandler.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

glm::vec3 InputHandler::CalculateLeftRightMovement(Camera camera)
{
	return glm::normalize(glm::cross(camera.CurrentMode.Front, camera.CurrentMode.Up)) * camera.CurrentMode.MovementSpeed;
}

glm::vec3 InputHandler::CalculateForwardBackwardMovement(Camera camera)
{
	return camera.CurrentMode.MovementSpeed * camera.CurrentMode.Front;
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
		camera.CurrentMode.Position.x += CalculateForwardBackwardMovement(camera).x;
		camera.CurrentMode.Position.z += CalculateForwardBackwardMovement(camera).z;
		break;
	
	case 'a':
		// Move left
		camera.CurrentMode.Position.x -= CalculateLeftRightMovement(camera).x;
		camera.CurrentMode.Position.z -= CalculateLeftRightMovement(camera).z;
		break;
	case 's':
		// Move Backwards
		camera.CurrentMode.Position.x -= CalculateForwardBackwardMovement(camera).x;
		camera.CurrentMode.Position.z -= CalculateForwardBackwardMovement(camera).z;
		break;
	case 'd':
		// Move right
		camera.CurrentMode.Position.x += CalculateLeftRightMovement(camera).x;
		camera.CurrentMode.Position.z += CalculateLeftRightMovement(camera).z;
		break;
	case 'q': 
		if(camera.CurrentMode.Mode == ModeType::Drone)
			camera.CurrentMode.Position.y += camera.CurrentMode.MovementSpeed;
		break;
	case 'e' :
		if (camera.CurrentMode.Mode == ModeType::Drone)
		{
			camera.CurrentMode.Position.y -= camera.CurrentMode.MovementSpeed;
			if (camera.CurrentMode.Position.y < 0.5) camera.CurrentMode.Position.y = 0.5;
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
