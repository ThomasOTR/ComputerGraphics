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
	/// Method to set the Rotation. 
	/// This method is needed to override the Entity Rotate method to update each part.
	/// </summary>
	/// <param name="rotation">: A vec3 that has the values in which direction the rotation will go.</param>
	/// <param name="rotAngle">: How many degrees the entity will rotate.</param>
	void Rotate(glm::vec3 rotation , float rotAngle);

	/// <summary>
	/// Method to set the Scale. 
	/// This method is needed to override the Entity Scale method to update each part.
	/// </summary>
	/// <param name="scale">: A vec3 that will indicate it which axis the entity will scale</param>
	void Scale(glm::vec3);

	/// <summary>
	/// A method to run the animations. This will override the RunAnimations method of Entity.
	/// </summary>
	void RunAnimations();

	/// <summary>
	/// Method to add all components to setup the model.
	/// </summary>
	virtual void AddComponents() = 0;


	/// <summary>
	/// Method to buffer the Model.
	/// This method overrides the Buffer method of Entity.
	/// <param name="view">: Calculated View Matrix</param>
	/// <param name="projection">: Calculated Projection Matrix</param>
	void Buffer(glm::mat4 view, glm::mat4 projection) override;

	/// <summary>
	/// Method to render the Model
	/// This method overrides the Render method of Entity	
	/// </summary>
	/// <param name="view">: Calculated View Matrix</param>
	/// <param name="projection">: Calculated Projection Matrix</param>
	void Render(glm::mat4 view, glm::mat4 projection) override;

};

