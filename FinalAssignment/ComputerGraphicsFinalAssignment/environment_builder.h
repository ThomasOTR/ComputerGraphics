#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "object.h"
class EnvironmentBuilder
{
public:
	EnvironmentBuilder();
	void BufferAllEntities(glm::mat4 view, glm::mat4 projection);
	void RenderAllEntities(glm::mat4 view, glm::mat4 projection);
private:
	std::vector<Entity*> entities = {};
	void LoadAllEntities();
};

