#pragma once
#include <glm/glm.hpp>
#include "shader.h"
#include "Animation.h"
#include <vector>
#include "Globals.h"
#include "Loaders.h"
#include "Material.h"
class Entity
{
public:

	/* An property which stores the Shader that is used for the Entity. */
	Shader shader = Shader();

	/* A property which stores all the animations of the Entity.*/
	std::vector<Animation*> animations = {};

	/// <summary>
	/// A method to add a single animation
	/// </summary>
	/// <param name="Animation">: Pointer to a Animation instance</param>
	virtual void AddAnimation(Animation*);

	/// <summary>
	/// A method to run the Animations. This method can be overridden by subclasses to implement a bit different approach.
	/// </summary>
	virtual void RunAnimations();

	/* A bool to check if the Animation is running */
	bool AnimationRunning = false;

	/* A bool to set the Animations in loop*/
	bool AnimationInLoop = false;

	/// <summary>
	/// Properties which will be used to buffer and render the entity.
	/// </summary>
	unsigned int texture_id = 0;
	unsigned int VAO = 0;
	unsigned int VBO = 0;
	
	std::string texture_path;
	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 mvp, mv;

	Entity() = default;

	/// <summary>
	/// Method to buffer the entity
	/// </summary>
	/// <param name="">projection</param>
	/// <param name="">view</param>
	virtual void Buffer(glm::mat4, glm::mat4) = 0;

	/// <summary>
	/// Method to render the entity
	/// </summary>
	/// <param name="">projection</param>
	/// <param name="">view</param>
	virtual void Render(glm::mat4, glm::mat4) = 0;

	/// <summary>
	/// Method to move the Entity
	/// </summary>
	/// <param name="position">: A vec3 with XYZ values to move the entity in those directions</param>
	virtual void Move(glm::vec3);

	/// <summary>
	/// Method to receive the Position of the entity.
	/// </summary>
	/// <returns>Current position of the entity</returns>
	glm::vec3 GetPosition();

	/// <summary>
	/// Method to rotate the entity
	/// </summary>
	/// <param name="rotation">: A vec3 that has the values in which direction the rotation will go.</param>
	/// <param name="rotAngle">: How many degrees the entity will rotate.</param>
	virtual void Rotate(glm::vec3 rotation, float rotAngle);

	/// <summary>
	/// Method to scale the entity
	/// </summary>
	/// <param name="scale">: A vec3 that will indicate it which axis the entity will scale</param>
	virtual void Scale(glm::vec3 scale);

	/// <summary>
	/// Methods to handle memory allocation.
	/// </summary>
	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}
	void operator delete(void* p)
	{
		_mm_free(p);
	}
};

