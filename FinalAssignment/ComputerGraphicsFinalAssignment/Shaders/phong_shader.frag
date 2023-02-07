#version 430 core

// Input from vertex shader
in VS_OUT
{
    vec3 N;
    vec3 L;
    vec3 V;
} fs_in;

in vec2 UV;

uniform sampler2D texsampler;
uniform bool texture_applied;
uniform vec3 objectColor;

// Material properties
uniform vec3 mat_ambient;
uniform vec3 mat_diffuse;
uniform vec3 mat_specular;
uniform float mat_power;

void main()
{
    // Normalize the incoming N, L and V vectors
    vec3 N = normalize(fs_in.N);
    vec3 L = normalize(fs_in.L);
    vec3 V = normalize(fs_in.V);

    // Calculate R locally
    vec3 R = reflect(-L, N);

    vec3 result;
	if (texture_applied) {
		vec3 diffuse = max(dot(N, L), 0.9) * texture2D(texsampler, UV).rgb;
        vec3 specular = pow(max(dot(R, V), 0.0), mat_power) * mat_specular;
        result = (mat_ambient + diffuse + specular);
	} 
    else {
		vec3 diffuse = max(dot(N, L), 0.1) * mat_diffuse;
        vec3 specular = pow(max(dot(R, V), 0.0), mat_power) * mat_specular;
        result = (mat_ambient + diffuse + specular) * objectColor;
	}
	
    gl_FragColor = vec4(result,1.0);
}