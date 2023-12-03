#include "Camera.h"

void Camera::moveCamera(MoveType type) {
    switch (type) {
    case FORWARD:
    cameraPos += cameraSpeed * cameraFront;
    break;
    case BACKWARD:
    cameraPos -= cameraSpeed * cameraFront;
    break;
    case LEFT:
    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    break;
    case RIGHT:
    cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    break;
    }
}

void Camera::updateCameraFront(glm::vec3 cameraFront) {
    this->cameraFront = cameraFront;
}

void Camera::rotateCamera(float deltaX, float deltaY) {
    float sensitivity = 0.1f;
    deltaX *= sensitivity;
    deltaY *= sensitivity;
    yaw += deltaX;
    pitch += deltaY;
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->cameraFront = glm::normalize(direction);
}