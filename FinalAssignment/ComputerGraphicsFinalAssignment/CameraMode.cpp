#include "CameraMode.h"

CameraMode::CameraMode()
{
	Pos = glm::vec3(0.0, 0.0, 0.0);
	Mode = ModeType::Walk;
	OriginalPos = Pos;
}
CameraMode::CameraMode(glm::vec3 Pos, ModeType Mode)
{
	this->Pos = Pos;
	this->Mode = Mode;
	this->OriginalPos = Pos;
}

