#ifndef GLFWWINDOW
#define GLFWWINDOW
#ifndef WINDOW
#include <Window.h>
#endif
class GLFWwindow;
class EventInputListener;
class WindowDelegate;
class GLFWWindow: public Window {
    public:
    GLFWWindow();
    virtual void setListener(EventInputListener *listener) override;
    virtual void setDelegate(WindowDelegate *delegate) override;
    virtual void run() override;
    virtual void exit() override;
    private:
    GLFWwindow* window;
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    void handleMouseCallBack(double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    void handleButtonCallback(int button, int action, int mods);
    void processInput(GLFWwindow *window);
    EventInputListener *listener;
    WindowDelegate *delegate;
    float lastX = 400, lastY = 400;
    bool firstMouse = false;
    float xoffset;
    float yoffset;
};

#endif