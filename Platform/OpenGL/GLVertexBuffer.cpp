#include "GLVertexBuffer.h"
#include <glad/glad.h>

GLVertexBuffer::GLVertexBuffer(void* data, unsigned int size) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void GLVertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void GLVertexBuffer::unBind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GLVertexBuffer::deleteBuffer() {
    glDeleteBuffers(1, &ID);
}

GLVertexBuffer::~GLVertexBuffer() {
    glDeleteBuffers(1, &ID);
}