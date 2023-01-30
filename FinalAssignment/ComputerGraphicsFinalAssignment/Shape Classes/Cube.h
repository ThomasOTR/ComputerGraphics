#pragma once
#include "../Shape.h"
class Cube :
	public Shape
{
private:
	std::vector<GLushort> Cube_Elements = {

		2,6,1,1,7,2, // Front
		7,1,5,5,3,7, // Top
		4,0,3,3,5,4, // back
		0,4,6,6,2,0, // bottom
		6,4,5,5,1,6, // left
		2,0,3,3,7,2,  // right


	};
	std::vector<GLfloat> Cube_Vertices = {

		-1.0, -1.0, -1.0, // 0 ---
		 1.0,  1.0,  1.0, // 1 +++
		-1.0, -1.0,  1.0, // 2 --+
		-1.0,  1.0, -1.0, // 3 -+-
		 1.0, -1.0, -1.0, // 4 +--

		 1.0,  1.0, -1.0, // 5 ++-
		 1.0, -1.0,  1.0, // 6 +-+
		-1.0,  1.0,  1.0, // 7 -++
	};

	std::vector<GLfloat> Cube_uvs = {
		0.0f, 0.0f, // bottom left
		1.0f, 0.0f, // bottom right
		1.0f, 1.0f, // top right
		0.0f, 1.0f, // top left
	};
public:
	Cube();
	Cube(std::string, float, float, float);
	Cube(glm::vec3, float, float, float);
	// Inherited via Shape
	virtual void setData();
	virtual void setAnimations();
};