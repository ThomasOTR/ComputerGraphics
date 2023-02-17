#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Entity.h"

/// <summary>
/// Class to create a Model of entities
/// </summary>
class Model : public Entity
{
public:
	/* A vector of all parts of this model */
	std::vector<Entity*> Parts = {};

	/// <summary>
	/// Methods to set the Position. 
	/// This method is needed to override the Entity SetPosition method to update each part.
	/// </summary>
	/// <param name="">X</param>
	/// <param name="">Y</param>
	/// <param name="">Z</param>
	void Move(glm::vec3) override;

	/// <summary>
	/// Methods to set the Rotation. 
	/// This method is needed to override the Entity SetRotation method to update each part.
	/// </summary>
	/// <param name="">X</param>
	/// <param name="">Y</param>
	/// <param name="">Z</param>
	void Rotate(glm::vec3, float);

	/// <summary>
	/// Methods to set the Scale. 
	/// This method is needed to override the Entity SetSacle method to update each part.
	/// </summary>
	/// <param name="">X</param>
	/// <param name="">Y</param>
	/// <param name="">Z</param>
	void Scale(glm::vec3);

	/// <summary>
	/// A method to run the animations. This will override the RunAnimations method of Entity.
	/// </summary>
	void RunAnimations();

	/// <summary>
	/// Method to add all components to initalise the model.
	/// </summary>
	virtual void AddComponents() = 0;

	void ResetComponents();
	// Inherited via Entity

	/// <summary>
	/// Method to buffer the Model
	/// </summary>
	/// <param name="">view</param>
	/// <param name="">projection</param>
	virtual void Buffer(glm::mat4, glm::mat4) override;

	/// <summary>
	/// Method to render the Model
	/// </summary>
	/// <param name="">view</param>
	/// <param name="">projection</param>
	virtual void Render(glm::mat4, glm::mat4) override;

};

