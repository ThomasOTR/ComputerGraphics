#include "Transformations.h"

glm::mat4 scale(glm::mat4 model, float x, float y, float z)
{
    return glm::scale(model, glm::vec3(x, y, z));
}

glm::mat4 rotate(glm::mat4 model, float angle, float x, float y, float z)
{
    return glm::rotate(model, glm::radians(angle), glm::vec3(x, y, z));
}

glm::mat4 translate(glm::mat4 model, float x, float y, float z)
{
    return glm::translate(model, glm::vec3(x, y, z));;
}