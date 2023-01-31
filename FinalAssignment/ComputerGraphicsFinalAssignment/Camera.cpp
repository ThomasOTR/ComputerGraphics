#include "Camera.h"


Camera::Camera()
{
    CurrentMode = WalkMode;
}

void Camera::UpdateCameraVectors()
{
        glm::vec3 front;
        front.x = cos(glm::radians(CurrentMode.yaw)) * cos(glm::radians(CurrentMode.pitch));
        front.y = sin(glm::radians(CurrentMode.pitch));
        front.z = sin(glm::radians(CurrentMode.yaw)) * cos(glm::radians(CurrentMode.pitch));
        CurrentMode.Front = glm::normalize(front);
        CurrentMode.Right = glm::normalize(glm::cross(CurrentMode.Front, CurrentMode.WorldUp));
        CurrentMode.Up = glm::normalize(glm::cross(CurrentMode.Right, CurrentMode.Front));
}
void Camera::SwitchMode()
{
    if (CurrentMode.Mode == ModeType::Walk)
    {
        WalkMode = CurrentMode;
        DroneMode.projection = WalkMode.projection;
        CurrentMode = DroneMode;
    }
    else if (CurrentMode.Mode == ModeType::Drone)
    {
        DroneMode = CurrentMode;
        CurrentMode = WalkMode;
    }
}
void Camera::CalculateViewMatrix()
{
    CurrentMode.view = glm::lookAt(CurrentMode.Pos, CurrentMode.Pos + CurrentMode.Front, CurrentMode.Up);
}

void Camera::CalculateProjectionMatrix()
{
    CurrentMode.projection = glm::perspective(glm::radians(CurrentMode.FOV),
                                             (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT), 
                                              0.1f, 100.0f);
}
