#include "GLElementArray.h"
#include <glad/glad.h>

GLElementArray::GLElementArray(unsigned int *data, unsigned int size) {
    count = size;
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
unsigned int GLElementArray::getArrayCount() {
    return count;
}

void GLElementArray::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void GLElementArray::unBind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void GLElementArray::deleteArray() {
    glDeleteBuffers(1, &ID);
}