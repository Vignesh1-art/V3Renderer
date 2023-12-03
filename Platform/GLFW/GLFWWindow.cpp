#include "GLFWWindow.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<windows.h>
#include<iostream>
using namespace std;

void errorCallback(int error, const char* description) {
    fprintf(stderr, "Error %d: %s\n", error, description);
}

GLFWWindow::GLFWWindow() {
    glfwSetErrorCallback(errorCallback);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
    glfwSetWindowUserPointer(window, reinterpret_cast<void *>(this));
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    if(window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { 
        cout << "Failed to initialize GLAD" <<endl;
        return;
    }
    listener = nullptr;
    delegate = nullptr;
}

void GLFWWindow::run() {
    if(!delegate) {
        //Nothing to process so return
        return;
    }
    delegate->init();
    while(!glfwWindowShouldClose(window)) {
        processInput(window);
        delegate->renderLoop((float)glfwGetTime());
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    delegate->deInit();
}

void GLFWWindow::setListener(EventInputListener *listener) {
    this->listener = listener;
}

void GLFWWindow::setDelegate(WindowDelegate *delegate) {
    this->delegate = delegate;
}

void GLFWWindow::exit() {
    glfwTerminate();
    listener = nullptr;
}

void GLFWWindow::processInput(GLFWwindow *window) {
    if(!listener) {
        return;
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        listener->onKeyPadInput(KEY_W);
    } else if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        listener->onKeyPadInput(KEY_A);
    } else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        listener->onKeyPadInput(KEY_S);
    } else if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        listener->onKeyPadInput(KEY_D);
    }  
}

void GLFWWindow::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    GLFWWindow* windowHandler = reinterpret_cast<GLFWWindow *>(glfwGetWindowUserPointer(window));
    if(windowHandler) {
        windowHandler->handleMouseCallBack(xpos, ypos);
    }
}

void GLFWWindow::handleMouseCallBack(double xpos, double ypos) {
    if(firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    xoffset = xpos - lastX;
    yoffset = lastY - ypos; 
}

void GLFWWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    GLFWWindow* windowHandler = reinterpret_cast<GLFWWindow *>(glfwGetWindowUserPointer(window));
    if(windowHandler) {
        windowHandler->handleButtonCallback(button, action, mods);
    }
}

void GLFWWindow::handleButtonCallback(int button, int action, int mods) {
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        firstMouse = true;
    } else if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        firstMouse = true;
        listener->onCursorMovement(xoffset, yoffset);
    }
}