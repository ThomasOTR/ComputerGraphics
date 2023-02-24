#include "Transformations.h"

glm::mat4 ScaleEntity(glm::mat4 model, glm::vec3 scale)
{
    return glm::scale(model, scale);
}

glm::mat4 RotateEntity(glm::mat4 model, float angle, glm::vec3 rotation)
{
    return glm::rotate(model, glm::radians(angle), rotation);
}

glm::mat4 TranslateEntity(glm::mat4 model, glm::vec3 position)
{
    return glm::translate(model, position);;
}