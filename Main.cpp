#include<Window.h>
#include<RendererApplication.h>
int main() {
    Window *window = Window::create();
    RendererApplication application;
    window->setDelegate(&application);
    window->setListener(&application);
    window->run();
    window->exit();
    delete window;
    return 0;
}