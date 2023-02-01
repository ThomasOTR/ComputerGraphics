#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 uv;

// Outputs
out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 mvp;

void main()
{
    // Output position of the vertex, in clip space : MVP * vertexPosition
    gl_Position = mvp * vec4(aPos, 1);

    UV = uv;
}