#include "Window.h"
#include <GLFWWindow.h>

Window* Window::create() {
    GLFWWindow *window = new GLFWWindow();
    return window;
}