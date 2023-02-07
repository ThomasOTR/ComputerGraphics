#include "Object.h"
Object::Object(std::string object_path, std::string texture_path, float posX, float posY, float posZ)
{
    this->object_path = object_path;
    this->texture_path = texture_path;

    SetPosition(posX, posY, posZ);

    LoadObject();
}

Object::Object(std::string object_path, glm::vec3 color, float posX, float posY, float posZ)
{
    this->object_path = object_path;
    this->color = color;

    SetPosition(posX, posY, posZ);

    LoadObject();

}

void Object::LoadObject()
{
    LoadOBJ(object_path.c_str(), vertices, uvs, normals);
}

void Object::Buffer(glm::mat4 view, glm::mat4 projection)
{
    Transform();

    shader = Shader(phongVertPath, phongFragPath);
    unsigned int position_id, normal_id, uv_id;
    unsigned int vbo_vertices, vbo_normals, vbo_uvs;

    // vbo for normals
    glGenBuffers(1, &vbo_normals);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
    glBufferData(GL_ARRAY_BUFFER,
        normals.size() * sizeof(glm::vec3),
        &normals[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for vertices
    glGenBuffers(1, &vbo_vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
    glBufferData(GL_ARRAY_BUFFER,
        vertices.size() * sizeof(glm::vec3), &vertices[0],
        GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vbo for uvs
    glGenBuffers(1, &vbo_uvs);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2),
        &uvs[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Get vertex attributes
    position_id = shader.getAttribLocation("position");
    normal_id = shader.getAttribLocation("normal");
    uv_id = shader.getAttribLocation("uv");

    // Allocate memory for vao
    glGenVertexArrays(1, &VAO);

    // Bind to vao
    glBindVertexArray(VAO);

    // Bind vertices to vao
    glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
    glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Bind normals to vao
    glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
    glVertexAttribPointer(normal_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(normal_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
    glVertexAttribPointer(uv_id, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(uv_id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Stop bind to vao
    glBindVertexArray(0);

    // Define model
    mv = view * model;
    shader.use();

    shader.setMat4("mv", mv);
    shader.setMat4("projection", projection);
    shader.setVec3("light_pos", defaultLight.Position);

    shader.setVec3("mat_ambient", material.AmbientColor);
    shader.setVec3("mat_diffuse", material.DiffuseColor);
    shader.setVec3("mat_specular", material.Specular);
    shader.setFloat("mat_power", material.Power);

    if (!texture_path.empty())
    {
        texture_id = setTexture(texture_path.c_str());
        shader.setTexture("texture1", "texture_applied");
    }
    else {
        shader.setNoTexture("texture_applied");
        shader.setVec3("objectColor", color);
    }
}

void Object::Render(glm::mat4 view, glm::mat4 projection)
{
    shader.use();

    RunAnimations();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    mv = view * model;
    shader.setMat4("mv", mv);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
