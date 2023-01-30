#pragma once
#include "Entity.h"
#include <vector>
enum class ShadingType {
	Basic, BasicTexture, PhongShading, LambertShading
};
class Shape : public Entity
{
public:	
	glm::vec3 color = glm::vec3();

	GLfloat vertices[120] = {};
	unsigned int indices[72] = {};
	float uvs[72];
	float normals[120] = {};

	ShadingType shading_type = ShadingType::Basic;
	Shader shader = Shader();

	// Inherited via Entity
	void Buffer(glm::mat4, glm::mat4) override;
	void BufferBasic(glm::mat4, glm::mat4);
	void BufferBasicTexture(glm::mat4, glm::mat4);
	void BufferPhong(glm::mat4, glm::mat4);
	void BufferLambert(glm::mat4, glm::mat4);
	void Render(glm::mat4, glm::mat4) override;
	void RenderBasic(glm::mat4, glm::mat4);
	void RenderShading(glm::mat4, glm::mat4);

	/* After research found out Normals are a usefull piece for a model to build.
	 * I calculated it by following: https://www.khronos.org/opengl/wiki/Calculating_a_Surface_Normal
	 */
	void CalculateNormals(std::vector<GLfloat>);
	virtual void setData() = 0;
	virtual void setAnimations() = 0;
	
};

