#include "Shape.h"

void Shape::BufferBasic(glm::mat4 view, glm::mat4 projection)
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
	shader.setMat4("model", model);
	shader.setMat4("view", view);
	shader.setMat4("projection", projection);
}

void Shape::BufferBasicTexture(glm::mat4 view, glm::mat4 projection)
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

void Shape::BufferPhong(glm::mat4, glm::mat4)
{
}

void Shape::Buffer(glm::mat4 view, glm::mat4 projection) {
	Transform();

	switch (shading_type) {
	case ShadingType::Basic:
		shader = Shader(basicVertPath, basicFragPath);
		BufferBasic(view, projection);
		break;
	case ShadingType::BasicTexture:
		shader = Shader(textureVertPath, textureFragPath);
		BufferBasicTexture(view, projection);

		break;
	case ShadingType::PhongShading:
		shader = Shader(phongVertPath, phongFragPath);
		BufferPhong(view, projection);
		break;
	case ShadingType::LambertShading:
		shader = Shader(lambertVertPath, lambertFragPath);
		BufferLambert(view, projection);
		break;
	}
}
void Shape::RenderBasic(glm::mat4 view, glm::mat4 projection)
{
	shader.use();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//std::cout << "animation size" << animations.size() << std::endl;
	// Animations
	if (animations.size() > 0) {
		for (auto& ani : animations) {
			model = ani->Animate(model);
		}
	}
	// Send mvp
	shader.setMat4("model", model);
	shader.setMat4("view", view);
	shader.setMat4("projection", projection);
	// Send vao
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, sizeof(vertices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
}
void Shape::RenderShading(glm::mat4, glm::mat4)
{
}


// TODO: make 2 methods for it. 
void Shape::CalculateNormals(std::vector<GLfloat> vertices)
{
	glm::vec3 N, U, V;
	std::vector<GLfloat> newNormals;

	for (int i = 0; i < sizeof(vertices); i += 9) {
		glm::vec3 p1, p2, p3;

		int j = i;
		p1 = glm::vec3(vertices[j], vertices[j + 1], vertices[j + 2]);
		j += 3;
		p2 = glm::vec3(vertices[j], vertices[j + 1], vertices[j + 2]);
		j += 3;
		p3 = glm::vec3(vertices[j], vertices[j + 1], vertices[j + 2]);

		U = p2 - p1;
		V = p3 - p1;

		N.x = (U.y * V.z) - (U.z * V.y);
		N.y = (U.z * V.x) - (U.x * V.z);
		N.z = (U.x * V.y) - (U.y * V.x);

		// Normalize (divide by root of dot product)
		N = glm::normalize(N);

		for (int p = 0; p < 3; p++) {
			newNormals.push_back(N.x);
			newNormals.push_back(N.y);
			newNormals.push_back(N.z);
		}
	}
	std::copy(newNormals.begin(), newNormals.end(), normals);
}
void Shape::BufferLambert(glm::mat4, glm::mat4)
{
}
void Shape::Render(glm::mat4 view, glm::mat4 projection) {
	if (shading_type == ShadingType::Basic || shading_type == ShadingType::BasicTexture)RenderBasic(view, projection);
	else RenderShading(view, projection);
}
