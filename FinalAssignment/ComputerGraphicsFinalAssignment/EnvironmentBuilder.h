#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "object.h"

/// <summary>
/// An class which will buffer and render all entities.
/// </summary>
class EnvironmentBuilder
{
private:
	/* A property which will store all entities */
	std::vector<Entity*> entities = {};

	/* A method to load all entities. */
	void LoadAllEntities();
public:
	EnvironmentBuilder();

	/// <summary>
	/// Method to buffer all loaded entities.
	/// </summary>
	/// <param name="view">View matrix calculated in the Camera class</param>
	/// <param name="projection">Projection matrix calculated in the Camera class</param>
	void BufferAllEntities(glm::mat4 view, glm::mat4 projection);
	
	/// <summary>
	/// Method to render all loaded entities
	/// </summary>
	/// <param name="view">View matrix calculated in the Camera class</param>
	/// <param name="projection">Projection matrix calculated in the Camera class</param>
	void RenderAllEntities(glm::mat4 view, glm::mat4 projection);

};

