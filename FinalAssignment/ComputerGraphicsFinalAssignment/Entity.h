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

	/// <summary>
	/// An property which stores the Shader that is used for this Entity.
	/// </summary>
	Shader shader;

	/// <summary>
	/// An property which stores a lightsource that is used with Phong Shaders.
	/// </summary>
	Material material;
	/* Scaling, Rotating, Positioning and doing this in Animations */

	/// <summary>
	/// Properties about the animations.
	/// </summary>

	std::vector<Animation*> animations = {};
	void AddAnimation(Animation*);
	void AddAnimations(std::vector<Animation*>);
	virtual void RunAnimations();
	bool AnimationRunning = false;
	bool AnimationInLoop = false;

	/// <summary>
	/// Properties which will be used to buffer and render the entity.
	/// </summary>
	unsigned int texture_id, VAO, VBO;
	std::string texture_path;
	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 mvp, mv;


	Entity() = default;

	/// <summary>
	/// Methods to buffer and render each entity
	/// </summary>
	/// <param name="">projection</param>
	/// <param name="">view</param>
	virtual void Buffer(glm::mat4, glm::mat4) = 0;
	virtual void Render(glm::mat4, glm::mat4) = 0;

	virtual void Move(glm::vec3);
	glm::vec3 GetPosition();

	virtual void Rotate(glm::vec3, float);
	virtual void Scale(glm::vec3);

	/// <summary>
	/// Methods to handle memory allocation 
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

