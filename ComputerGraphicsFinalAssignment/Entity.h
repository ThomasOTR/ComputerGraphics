#pragma once
#include <glm/glm.hpp>
#include "shader.h"
#include "Animation.h"
#include <vector>
#include "Globals.h"
#include "Loaders.h"
#include "Light.h"
class Entity
{
private:
	glm::vec3 Position = glm::vec3();
	glm::vec3 Scale = glm::vec3();
	glm::vec3 Rotation = glm::vec3();
	float RotAngle = 0;
public:
	Shader shader;
	Light light;
	/* Scaling, Rotating, Positioning and doing this in Animations */

	std::vector<Animation*> animations = {};

	/* Parts needed for making entity*/
	unsigned int texture_id, VAO, VBO;
	std::string texture_path;
	glm::mat4 model = glm::mat4(1.0);
	glm::mat4 mvp, mv;

	/* Methods */
	Entity() = default;
	virtual void Buffer(glm::mat4, glm::mat4) = 0;
	virtual void Render(glm::mat4, glm::mat4) = 0;
	
	virtual void Transform();
	
	virtual void SetPosition(float, float, float);
	glm::vec3 GetPosition();

	virtual void SetRotation(float, float, float,float);
	glm::vec3 GetRotation();

	virtual void SetScale(float, float, float);
	glm::vec3 GetScale();

	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}
	void operator delete(void* p)
	{
		_mm_free(p);
	}
};

