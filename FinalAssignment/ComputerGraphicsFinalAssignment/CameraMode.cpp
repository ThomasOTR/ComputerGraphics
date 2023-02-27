#include "CameraMode.h"

CameraMode::CameraMode()
{
	Position = glm::vec3(0.0, 0.0, 0.0);
	Mode = ModeType::Walk;
}
CameraMode::CameraMode(glm::vec3 Position, ModeType Mode)
{
	this->Position = Position;
	this->Mode = Mode;
}

