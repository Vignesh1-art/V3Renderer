#include "Renderer.h"
#include "RendererCommand.h"
#include <vector>


RendererCommand* Renderer::command = nullptr;

void Renderer::init() {
    command = RendererCommand::create();
}

void Renderer::setClearColor(float r, float g, float b, float a) {
    command->setClearColor(r, g, b, a);
}

void Renderer::setViewPort(unsigned int pox, unsigned int poy, unsigned int heigth, unsigned int width) {
    command->setViewPort(pox, poy, heigth, width);
}

void Renderer::clear() {
    command->clearColor();
}

void Renderer::drawIndexed(unsigned int count) {
    command->drawIndexedElements(count);
}

void Renderer::drawArray(unsigned int count) {
    command->drawArrays(count);
}

void Renderer::deinit() {
    RendererCommand::destroy();
}