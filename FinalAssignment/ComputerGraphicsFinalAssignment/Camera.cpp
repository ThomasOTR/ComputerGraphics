#include "Camera.h"

void Camera::updateCameraVectors()
{
        // calculate the new Front vector
        glm::vec3 front;
        front.x = cos(glm::radians(currentMode.yaw)) * cos(glm::radians(currentMode.pitch));
        front.y = sin(glm::radians(currentMode.pitch));
        front.z = sin(glm::radians(currentMode.yaw)) * cos(glm::radians(currentMode.pitch));
        currentMode.Front = glm::normalize(front);
        // also re-calculate the Right and Up vector
        currentMode.Right = glm::normalize(glm::cross(currentMode.Front, currentMode.WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        currentMode.Up = glm::normalize(glm::cross(currentMode.Right, currentMode.Front));
}
void Camera::CalculateViewMatrix()
{
    currentMode.view = glm::lookAt(currentMode.Pos, currentMode.Pos + currentMode.Front, currentMode.Up);
}

void Camera::CalculateProjectionMatrix()
{
    currentMode.projection = glm::perspective(glm::radians(currentMode.FOV), 
                                             (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT), 
                                              0.1f, 100.0f);
}
