#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Entity.h"

/// <summary>
/// Class to create a Mesh of multiple entity.
/// </summary>
class Mesh : public Entity
{
public:
	/// <summary>
	/// A vector of all parts of this mesh
	/// </summary>
	std::vector<Entity*> Parts = {};

	/// <summary>
	/// Methods to set the Position. 
	/// This method is needed to override the Entity SetPosition method to update each part.
	/// </summary>
	/// <param name="">X</param>
	/// <param name="">Y</param>
	/// <param name="">Z</param>
	void SetPosition(float, float, float);

	/// <summary>
	/// Methods to set the Rotation. 
	/// This method is needed to override the Entity SetRotation method to update each part.
	/// </summary>
	/// <param name="">X</param>
	/// <param name="">Y</param>
	/// <param name="">Z</param>
	void SetRotation(float, float, float, float);

	/// <summary>
	/// Methods to set the Scale. 
	/// This method is needed to override the Entity SetSacle method to update each part.
	/// </summary>
	/// <param name="">X</param>
	/// <param name="">Y</param>
	/// <param name="">Z</param>
	void SetScale(float, float, float);

	/// <summary>
	/// A method to Transform the mesh. Only needed when Set Methods are called.
	/// This method is needed to override the Entity Transform to transform each part.
	/// </summary>
	void Transform();

	/// <summary>
	/// Method to reset all components after Transforming.
	/// </summary>
	virtual void ResetComponents() = 0;

	/// <summary>
	/// Method to add all components to initalise the mesh.
	/// </summary>
	virtual void AddComponents() = 0;
	// Inherited via Entity

	/// <summary>
	/// Method to buffer the Mesh
	/// </summary>
	/// <param name="">view</param>
	/// <param name="">projection</param>
	virtual void Buffer(glm::mat4, glm::mat4) override;

	/// <summary>
	/// Method to render the mesh
	/// </summary>
	/// <param name="">view</param>
	/// <param name="">projection</param>
	virtual void Render(glm::mat4, glm::mat4) override;

};

