#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;


void main()
{
	// set simple our texture
	 FragColor = texture(texture1, TexCoord);
}