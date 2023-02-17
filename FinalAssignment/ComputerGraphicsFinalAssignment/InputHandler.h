#pragma once
#include <GL/freeglut.h>
#include "Camera.h"


class InputHandler
{
private:
	/// <summary>
	/// Multiplier to move the camera smoothly when WASD is presssed.
	/// </summary>
	float movementSpeed = 0.25f;

	/// <summary>
	/// Multiplier to move the camera smoothly when the mouse is moved.
	/// </summary>
	float sensitivity = 0.1f;

	/// <summary>
	/// Boolean to position the mouse right when it has never moved before.
	/// </summary>
	bool firstMouseMovement = true;

	glm::vec3 CalculateLeftRightMovement(Camera camera);
	glm::vec3 CalculateForwardBackwardMovement(Camera camera);

public:
	/// <summary>
	/// Method to process key input
	/// </summary>
	/// <param name="">Camera input to update the camera easily.</param>
	/// <param name="">Number which represents a key</param>
	/// <returns>An updated Camera instance</returns>
	Camera processKeyInput(Camera, unsigned char);

	/// <summary>
	/// Method to process mouse input
	/// </summary>
	/// <param name="">Camera input to update the camera easily</param>
	/// <param name="">X position of the mouse</param>
	/// <param name="">Y position of the mouse</param>
	/// <returns>An updated Camera instance</returns>
	Camera processMouseInput(Camera, int, int);

};

