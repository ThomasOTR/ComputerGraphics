#include "PrimitiveMesh.h"

void PrimitiveMesh::Buffer(glm::mat4 view, glm::mat4 projection)
{
	/* Loading in Shader*/
	shader = Shader(basicVertPath, basicFragPath);
	unsigned int position_id;

	position_id = shader.getAttribLocation("aPos");
	unsigned int vbo_vertices, ebo;

	/* Generating and buffering the vertices */
	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	/* Generating and Buffering the indices */
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind cube elements.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Stop binding
	glBindVertexArray(0);

	/* Set Color of the Mesh */
	shader.use();
	shader.setVec3("color", color);
}
void PrimitiveMesh::Render(glm::mat4 view, glm::mat4 projection) {
	/* Enable this shader*/
	shader.use();

	/* Run the animations if it has any. */
	RunAnimations();

	/* Bind the texture */
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set MVP for the shader.
	shader.setMat4("model", model);
	shader.setMat4("view", view);
	shader.setMat4("projection", projection);

	/* Draw the Mesh */
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, sizeof(vertices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
}
