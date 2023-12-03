#ifndef CAMERA
#define CAMERA
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum MoveType {
    FORWARD, BACKWARD, RIGHT, LEFT
};

class Camera {
    public:
    glm::mat4 getView() {
        return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);;
    }
    void moveCamera(MoveType type);
    void updateCameraFront(glm::vec3 cameraFront);
    void rotateCamera(float deltaX, float deltaY);
    private:
    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
    glm::mat4 view = glm::mat4(1.0f);
    const float cameraSpeed = 0.05f;
    float yaw = -90.0f;
    float pitch = 0.0f;
};


#endif