#pragma once
#include "Entity.h"
#include <vector>

/// <summary>
/// Enum to categorise the types of shading.
/// </summary>
enum class ShadingType {
	Basic, BasicTexture, PhongShading, LambertShading
};

/// <summary>
/// A class to create a shape.
/// </summary>
class PrimitiveMesh : public Entity
{
public:	

	/* Properties needed to buffer and render the shape */
	glm::vec3 color = glm::vec3();
	GLfloat vertices[120] = {};
	unsigned int indices[72] = {};
	float uvs[72];
	float normals[120] = {};

	/* Properties related to Shading. */
	ShadingType shading_type = ShadingType::Basic;
	Shader shader = Shader();

	/* Methods to buffer the shape based on the ShadingType */
	void Buffer(glm::mat4, glm::mat4) override;
	void BufferBasic(glm::mat4, glm::mat4);
	void BufferBasicTexture(glm::mat4, glm::mat4);

	/* Methods to render the shape based on the ShadingType*/
	void Render(glm::mat4, glm::mat4) override;

	/* After research found out Normals are a usefull piece for a model to build.
	* I calculated it by following: https://www.khronos.org/opengl/wiki/Calculating_a_Surface_Normal
	*/
	void CalculateNormals(std::vector<GLfloat>);

	/// <summary>
	/// Methods that will be inherited by subclasses to set multiple things that are different for each shape
	/// </summary>
	virtual void setData() = 0;

};

