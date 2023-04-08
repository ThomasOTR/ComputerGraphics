#include "Globals.h"
#include <string>

const char* basicFragPath = "Shaders/basic_shader.frag";
const char* basicVertPath = "Shaders/basic_shader.vert";
const char* phongFragPath = "Shaders/phong_shader.frag";
const char* phongVertPath = "Shaders/phong_shader.vert";
const char* skyboxFragPath = "Shaders/skybox_shader.frag";
const char* skyboxVertPath = "Shaders/skybox_shader.vert";

Material defaultMaterial = Material(glm::vec3(.1, .1 , .1), glm::vec3(0.5, 0.5, 0.5), glm::vec3(0.7, 0.7, 0.7), 64);

extern std::string objectPath = "Objects/";
extern std::string blenderObjectPath = "Objects/MadeInBlender/";
extern std::string resourcePath = "Textures/";

glm::vec3 LightSource = glm::vec3(-30, 15, 0);