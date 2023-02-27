#include "Material.h"

Material::Material(glm::vec3 ambientColor, glm::vec3 diffuseColor, glm::vec3 specular, float power)
{
	Ambient = ambientColor;
	Diffuse = diffuseColor;
	Specular = specular;
	Power = power;
}
