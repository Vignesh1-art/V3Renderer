#include <glad/glad.h>
#include "GLRendererCommand.h"

GLRendererCommand::GLRendererCommand() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GLRendererCommand::setViewPort(unsigned int posx, unsigned int posy, unsigned int length, unsigned int width) {
    glViewport(posx, posy, length, width);
}

void GLRendererCommand::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void GLRendererCommand::clearColor() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLRendererCommand::drawIndexedElements(unsigned int count) {
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}

void GLRendererCommand::drawArrays(unsigned int count) {
    glDrawArrays(GL_TRIANGLES, 0, count);
}
