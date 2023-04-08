#include "CameraMode.h"

CameraMode::CameraMode()
{
	Position = glm::vec3(0.0, 0.0, 0.0);
	/* Set the camera modus as default on Walk */
	Mode = ModeType::Walk;
}
CameraMode::CameraMode(glm::vec3 Position, ModeType Mode, float MovementSpeed)
{
	this->Position = Position;
	this->Mode = Mode;
	this->MovementSpeed = MovementSpeed;
}

