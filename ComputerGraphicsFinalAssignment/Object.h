#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Entity.h"
class Object : public Entity
{
private:
	std::string object_path;
public:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	Object() = default;
	Object(std::string, std::string, float, float, float);
	Object(std::string, std::string, float, float, float, float, float, float);
	Object(std::string, std::string, float, float, float, float, float, float, float, float, float, float);

	void LoadObject();
	// Inherited via Entity
	virtual void Buffer(glm::mat4, glm::mat4);
	virtual void Render(glm::mat4, glm::mat4);
};

