#pragma once
#include <glm/glm.hpp>

/// <summary>
/// A class which stores everything related to a Material.
/// </summary>
class Material
{
public:
	/* Color that will be seen when there is almost no light.*/
	glm::vec3 Ambient = glm::vec3(0.2, 0.2, 0.1);

	/* Color what simulates the impact the light has.*/
	glm::vec3 Diffuse = glm::vec3(0.5, 0.5, 0.3);

	/* The bright spot of a light that appears on shiny objects */
	glm::vec3 Specular = glm::vec3(0.7, 0.7, 0.7);

	/* The shinyness of the material */
	float Power;
	Material() = default;
	Material(glm::vec3 Ambient, glm::vec3 Diffuse, glm::vec3 Specular, float Power);
};

