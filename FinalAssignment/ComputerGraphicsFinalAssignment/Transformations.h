#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/// <summary>
/// Method to scale a Mat4 variable
/// </summary>
/// <param name="">Mat4</param>
/// <param name="">X</param>
/// <param name="">Y</param>
/// <param name="">Z</param>
/// <returns>Scaled Mat4</returns>
glm::mat4 ScaleEntity(glm::mat4, glm::vec3);

/// <summary>
/// Method to rotate a Mat4 variable
/// </summary>
/// <param name="">Mat4</param>
/// <param name="">X</param>
/// <param name="">Y</param>
/// <param name="">Z</param>
/// <returns>Scaled Mat4</returns>
glm::mat4 RotateEntity(glm::mat4, float radians, glm::vec3);

/// <summary>
/// Method to position a Mat4 variable
/// </summary>
/// <param name="">Mat4</param>
/// <param name="">X</param>
/// <param name="">Y</param>
/// <param name="">Z</param>
/// <returns>positioned Mat4</returns>
glm::mat4 TranslateEntity(glm::mat4, glm::vec3);
glm::mat4 translate(glm::mat4, float, float, float);