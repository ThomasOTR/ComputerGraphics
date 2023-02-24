#pragma once
#include "Entity.h"
#include <vector>


/// <summary>
/// A class to create a shape.
/// </summary>
class PrimitiveMesh : public Entity
{
public:	

	/* Property to store the color, which will be retrieved during buffering the PrimitiveMesh */
	glm::vec3 color = glm::vec3();

	/* Property which stores the vertices of the PrimitiveMesh. This will be set by the setData method in the subclasses */
	GLfloat vertices[120] = {};

	/* Property which stores the indices/elements of the PrimitiveMesh. This will be set by the setData method in the subclasses */
	unsigned int indices[72] = {};

	/* Property which stores the shader, that is always used during buffering and rendering PrimitiveMeshes */
	Shader shader = Shader();

	/// <summary>
	/// Method to buffer the PrimitiveMesh.
	/// This method overrides the Buffer method of Entity.
	/// <param name="view">: Calculated View Matrix</param>
	/// <param name="projection">: Calculated Projection Matrix</param>
	void Buffer(glm::mat4 view, glm::mat4 projection) override;

	/// <summary>
	/// Method to render the PrimitiveMesh
	/// This method overrides the Render method of Entity	
	/// </summary>
	/// <param name="view">: Calculated View Matrix</param>
	/// <param name="projection">: Calculated Projection Matrix</param>
	void Render(glm::mat4 view, glm::mat4 projection) override;

	/// <summary>
	/// Method that will be inherited by subclasses of the PrimitiveMesh to set the specific data.
	/// </summary>
	virtual void setData() = 0;

};

