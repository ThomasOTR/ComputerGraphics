#include "PrimitiveMesh.h"

void PrimitiveMesh::BufferBasic(glm::mat4 view, glm::mat4 projection)
{
	unsigned int position_id;

	position_id = shader.getAttribLocation("aPos");
	unsigned int vbo_vertices, ebo;

	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
		indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	// Bind cube elements.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Stop bind to vao
	glBindVertexArray(0);

	shader.use();
	shader.setVec3("color", color);
}

void PrimitiveMesh::BufferBasicTexture(glm::mat4 view, glm::mat4 projection)
{
	unsigned int position_id, uv_id;

	position_id = shader.getAttribLocation("aPos");
	uv_id = shader.getAttribLocation("aTexCoord");
	unsigned int vbo_vertices, vbo_uvs, ebo;

	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),
		indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(position_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
	glVertexAttribPointer(uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(uv_id);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Bind cube elements.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Stop bind to vao
	glBindVertexArray(0);

	shader.use();

	texture_id = setTexture(texture_path.c_str());
	glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);

}

void PrimitiveMesh::Buffer(glm::mat4 view, glm::mat4 projection) {

	switch (shading_type) {
	case ShadingType::Basic:
		shader = Shader(basicVertPath, basicFragPath);
		BufferBasic(view, projection);
		break;
	case ShadingType::BasicTexture:
		shader = Shader(textureVertPath, textureFragPath);
		BufferBasicTexture(view, projection);
		break;
	}
}
void PrimitiveMesh::Render(glm::mat4 view, glm::mat4 projection) {
	shader.use();

	RunAnimations();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Send mvp
	shader.setMat4("model", model);
	shader.setMat4("view", view);
	shader.setMat4("projection", projection);
	// Send vao
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, sizeof(vertices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
}
