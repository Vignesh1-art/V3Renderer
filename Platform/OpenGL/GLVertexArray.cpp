#include "GLVertexArray.h"
#include <glad/glad.h>

GLVertexArray::GLVertexArray() {
    glGenVertexArrays(1, &ID);
}

void GLVertexArray::addAttribute(unsigned int index, unsigned int componentCount, unsigned int strideLength, unsigned int offset) {
    attributeIndexes.push_back(index);
    glBindVertexArray(ID);
    glVertexAttribPointer(index, componentCount, GL_FLOAT, GL_FALSE, strideLength, (void*) offset);
}

std::vector<unsigned int> GLVertexArray::getAttributeIndexes() {
    return attributeIndexes;
}

void GLVertexArray::enableAttribute(unsigned int index) {
    glEnableVertexAttribArray(index);
}

void GLVertexArray::disableAttribute(unsigned int index) {
    glDisableVertexAttribArray(index);
}

void GLVertexArray::bind() {
    glBindVertexArray(ID);
}

void GLVertexArray::unBind() {
    glBindVertexArray(0);
}

void GLVertexArray::deleteBuffer() {
    glDeleteBuffers(1, &ID);
}

GLVertexArray::~GLVertexArray() {
    glDeleteBuffers(1, &ID);
}