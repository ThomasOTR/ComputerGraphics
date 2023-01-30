#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 scale(glm::mat4, float, float, float);
glm::mat4 rotate(glm::mat4, float radians, float, float, float);
glm::mat4 translate(glm::mat4, float, float, float);
