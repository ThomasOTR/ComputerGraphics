#include "Skybox.h"

Skybox::Skybox()
{
    std::copy(skyboxVertices.begin(), skyboxVertices.end(), vertices);
    std::copy(skyboxIndices.begin(), skyboxIndices.end(), indices);

    Scale(glm::vec3(10, 10, 10));
}

void Skybox::Buffer(glm::mat4, glm::mat4)
{
    /* Set the Shader*/
    shader = Shader(skyboxVertPath, skyboxFragPath);

    unsigned int EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    /* Buffer the Vertices*/
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    /* Buffer the Indices*/
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    /* Load the Cubemap with all the images for each side */
    texture_id = loadCubemap(sides);
}

void Skybox::Render(glm::mat4 view, glm::mat4 projection)
{
    /* Changes the depth, This is needed for displaying the Skybox */
    glDepthFunc(GL_LEQUAL);
    
    /* Enable the shader for the skybox and set the view and projection that the shader needs*/
    shader.use();
    shader.setMat4("view", glm::mat4(glm::mat3(view)));
    shader.setMat4("projection", projection);


    glBindVertexArray(VAO);

    /* Set the Texture that is loaded in the buffer.*/
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id);

    /* Draw the Skybox*/
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    /* Changes the Depth back as it was before. */
    glDepthFunc(GL_LESS);
}
