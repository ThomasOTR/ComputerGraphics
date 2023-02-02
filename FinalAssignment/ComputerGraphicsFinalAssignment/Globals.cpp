#include "Globals.h"

const char* basicFragPath = "Shaders/basic_shader.frag";
const char* basicVertPath = "Shaders/basic_shader.vert";
const char* textureFragPath = "Shaders/texture_shader.frag";
const char* textureVertPath = "Shaders/texture_shader.vert";
const char* phongFragPath = "Shaders/phong_shader.frag";
const char* phongVertPath = "Shaders/phong_shader.vert";
const char* lambertFragPath = "Shaders/lambert_shader.frag";
const char* lambertVertPath = "Shaders/lambert_shader.vert";
const char* skyboxFragPath = "Shaders/skybox_shader.frag";
const char* skyboxVertPath = "Shaders/skybox_shader.vert";

const Material defaultMaterial = Material(glm::vec3(0.2, 0.2, 0.1), glm::vec3(0.5, 0.5, 0.3), glm::vec3(0.7, 0.7, 0.7), 1024);
const Light defaultLight = Light(glm::vec3(4, 4, 4));