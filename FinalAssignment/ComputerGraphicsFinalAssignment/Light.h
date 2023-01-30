#pragma once
#include <glm/glm.hpp>

class Light
{
public:
	glm::vec3 position = glm::vec3(4, 4, 4);
	glm::vec3 ambient_color = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 diffuse_color = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 specular = glm::vec3(0.7, 0.7, 0.7);
	float power = 1024;
};

