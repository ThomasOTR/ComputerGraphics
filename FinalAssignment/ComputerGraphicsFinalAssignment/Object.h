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
	/* Vector to store vertices. */
	std::vector<glm::vec3> vertices;

	/* Vector to store normals. */
	std::vector<glm::vec3> normals;

	/* Vector to store uvs */
	std::vector<glm::vec2> uvs;

	/* A vec3 where the color of this object is stored.*/
	glm::vec3 color = glm::vec3();

	/* An property which stores a lightsource that is used with Phong Shaders*/
	Material material;

	Object() = default;
	Object(std::string, std::string texture_path);
	Object(std::string, glm::vec3 color);

	/// <summary>
	/// A method to load the object
	/// </summary>
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

