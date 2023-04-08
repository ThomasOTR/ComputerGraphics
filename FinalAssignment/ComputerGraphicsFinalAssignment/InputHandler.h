#pragma once
#include <GL/freeglut.h>
#include "Camera.h"


class InputHandler
{
private:

	/* Multiplier to move the camera smoothly when the mouse is moved. */
	float sensitivity = 0.1f;

	/* Boolean to position the mouse right when it has never moved before.*/
	bool firstMouseMovement = true;

	/// <summary>
	/// A method that calculates a value to move the Camera to left or right.
	/// </summary>
	/// <param name="camera">: Camera instance, which new position needs to be calculated.</param>
	/// <returns>new position of the camera</returns>
	glm::vec3 CalculateLeftRightMovement(Camera camera);

	/// <summary>
	/// A method that calculates a value to move the camera forward and backward
	/// </summary>
	/// <param name="camera">: Camera instance, which new position needs to be calculated.</param>
	/// <returns>new position of the camera.</returns>
	glm::vec3 CalculateForwardBackwardMovement(Camera camera);

public:
	/// <summary>
	/// Method to process key input
	/// </summary>
	/// <param name="camera">: Camera instance that will be updated.</param>
	/// <param name="keyNumber">: Number of the key that is pressed.</param>
	/// <returns>An updated Camera instance</returns>
	Camera processKeyInput(Camera camera, unsigned char keyNumber);

	/// <summary>
	/// Method to process mouse input
	/// </summary>
	/// <param name="camera">: Camera instance that will be updated.</param>
	/// <param name="x">: The X position of the mouse.</param>
	/// <param name="y">: The Y position of the mouse.</param>
	/// <returns>An updated Camera instance</returns>
	Camera processMouseInput(Camera camera, int x, int y);

};

