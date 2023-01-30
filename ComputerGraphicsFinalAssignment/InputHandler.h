#pragma once
#include <GL/freeglut.h>
#include "Camera.h"


class InputHandler
{
private:
	float movementSpeed = 0.25f;
	float firstMouseMovement = true;
	float sensitivity = 0.1f;

public:
	Camera processKeyInput(Camera, unsigned char);
	Camera processMouseInput(Camera, int, int);

};

