#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Entity.h"

/// <summary>
/// Class to store an object.
/// </summary>
class Object : public Entity
{
private:
	std::string object_path;
public:
	/// <summary>
	/// Vector to store vertices
	/// </summary>
	std::vector<glm::vec3> vertices;

	/// <summary>
	/// Vector to store normals
	/// </summary>
	std::vector<glm::vec3> normals;

	/// <summary>
	/// Vector to store uvs
	/// </summary>
	std::vector<glm::vec2> uvs;

	glm::vec3 color = glm::vec3();

	Object() = default;
	Object(std::string, std::string texture_path);
	Object(std::string, glm::vec3 color);


	void LoadObject();
	// Inherited via Entity

	/// <summary>
	/// Method to buffer the object
	/// </summary>
	/// <param name="">view</param>
	/// <param name="">projection</param>
	virtual void Buffer(glm::mat4, glm::mat4);

	/// <summary>
	/// Method to render the object
	/// </summary>
	/// <param name="">view</param>
	/// <param name="">projection</param>
	virtual void Render(glm::mat4, glm::mat4);
};

