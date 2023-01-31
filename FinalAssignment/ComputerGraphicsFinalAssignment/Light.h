#pragma once
#include <glm/glm.hpp>

/// <summary>
/// A class which stores everything related to a light source.
/// </summary>
class Light
{
public:
	glm::vec3 Position = glm::vec3(4, 4, 4);
	glm::vec3 AmbientColor = glm::vec3(0.2, 0.2, 0.1);
	glm::vec3 DiffuseColor = glm::vec3(0.5, 0.5, 0.3);
	glm::vec3 Specular = glm::vec3(0.7, 0.7, 0.7);
	float Power = 1024;
};

