#include "GLShader.h"
#include <glad/glad.h>
#include <iostream>
#include<vector>
GLShader::GLShader() {
    ID = glCreateProgram();    
}

void GLShader::addShader(const char *shaderSource, ShaderType type) {
    unsigned int shader;
    switch(type) {
        case VERTEX_SHADER:
        shader = glCreateShader(GL_VERTEX_SHADER);
        break;
        case FARGMENT_SHADER:
        shader = glCreateShader(GL_FRAGMENT_SHADER);
    }
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    glAttachShader(ID, shader);
}

void GLShader::link() {
    glLinkProgram(ID);
    int success;
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout<<infoLog<<std::endl;
    } else {
        std::cout<<"OpenGL::Shader compiled successfully"<<std::endl;
    }
}

void GLShader::use() {
    glUseProgram(ID);
}

void GLShader::setBool(const std::string &name, bool value) {         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void GLShader::setInt(const std::string &name, int value) { 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void GLShader::setFloat(const std::string &name, float value) { 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}

void GLShader::setMat4f(const std::string &name, float *values) {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, values);
}

void GLShader::deleteShader() {
    glDeleteProgram(ID);
}

GLShader::~GLShader() {
    glDeleteProgram(ID);
}
