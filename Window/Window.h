#ifndef WINDOW
#define WINDOW
#include "InputConstant.h"

class EventInputListener {
public:
    virtual void onKeyPadInput(KeyPadKeys key) = 0;
    virtual void onCursorMovement(double deltaX, double deltaY) = 0;
};

class WindowDelegate {
    public:
    virtual void init() = 0;
    virtual void renderLoop(float delta) = 0;
    virtual void deInit() = 0;
};

class Window {
    public:
    static Window *create();
    virtual void setListener(EventInputListener *listener) = 0;
    virtual void setDelegate(WindowDelegate *delegate) = 0;
    virtual void run() = 0;
    virtual void exit() = 0;
};
#endif