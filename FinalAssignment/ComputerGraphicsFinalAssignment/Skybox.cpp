#include "Skybox.h"

Skybox::Skybox()
{
    std::copy(skyboxVertices.begin(), skyboxVertices.end(), vertices);
    std::copy(skyboxIndices.begin(), skyboxIndices.end(), indices);

    Scale(glm::vec3(10, 10, 10));
}

void Skybox::Buffer(glm::mat4, glm::mat4)
{
    shader = Shader(skyboxVertPath, skyboxFragPath);
    shader.use();
    shader.setInt("skybox", 0);

    unsigned int EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    texture_id = loadCubemap(sides);
}

void Skybox::Render(glm::mat4 view, glm::mat4 projection)
{
    glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
    
    shader.use();
    shader.setMat4("view", glm::mat4(glm::mat3(view)));
    shader.setMat4("projection", projection);

    glBindVertexArray(VAO);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS);
}
