#pragma once
#include <GL/freeglut.h>
#include "Camera.h"


class InputHandler
{
private:
	/* Multiplier to move the camera smoothly when WASD is presssed. */
	float movementSpeed = 0.25f;

	/* Multiplier to move the camera smoothly when the mouse is moved. */
	float sensitivity = 0.1f;

	/* Boolean to position the mouse right when it has never moved before.*/
	bool firstMouseMovement = true;

	/// <summary>
	/// A method that calculates a value to move the Camera to left or right.
	/// </summary>
	/// <param name="camera"></param>
	/// <returns></returns>
	glm::vec3 CalculateLeftRightMovement(Camera camera);

	/// <summary>
	/// A method that calculates a value to move the camera forward and backward
	/// </summary>
	/// <param name="camera"></param>
	/// <returns></returns>
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

