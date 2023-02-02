#include "Material.h"

Material::Material(glm::vec3 ambientColor, glm::vec3 diffuseColor, glm::vec3 specular, float power)
{
	AmbientColor = ambientColor;
	DiffuseColor = diffuseColor;
	Specular = specular;
	Power = power;
}
