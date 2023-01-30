#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Entity.h"
class Mesh : public Entity
{
public:
	std::vector<Entity*> Parts = {};
	void SetPosition(float, float, float);
	void SetRotation(float, float, float, float);
	void SetScale(float, float, float);
	void Transform();
	virtual void ResetComponents() = 0;

	virtual void AddComponents() = 0;
	// Inherited via Entity
	virtual void Buffer(glm::mat4, glm::mat4) override;
	virtual void Render(glm::mat4, glm::mat4) override;

};

