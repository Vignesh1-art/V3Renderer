#include "RendererCommand.h"
#include <GLRendererCommand.h>

RendererCommand *RendererCommand::singleton = nullptr;

RendererCommand *RendererCommand::create() {
    if (singleton == nullptr) {
        singleton = new GLRendererCommand();
    }
    return singleton;
}

void RendererCommand::destroy() {
    delete singleton;
    singleton = nullptr;
}
