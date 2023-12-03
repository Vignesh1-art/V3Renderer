#include "RendererApplication.h"
#include <Triangle.h>
#include <TriangleFragment.h>
#include <Shader.h>
#include <cmath>
#include<iostream>
void RendererApplication::init() {
    buffer = VertexBuffer::create(vertices, sizeof(vertices));
    vertexArray = VertexArray::create();
    texture1 = Texture::create(".\\assets\\container.jpg");
    shader = Shader::create();
    Renderer::init();
    Renderer::setClearColor(0.0f, 0.1f, 0.3f, 1.0f);
    Renderer::setViewPort(0, 0, 800, 800);
    shader->addShader(triangle, VERTEX_SHADER);
    shader->addShader(triangleFragment, FARGMENT_SHADER);
    shader->link();
    buffer->bind();
    vertexArray->bind();
    vertexArray->addAttribute(0, 3, 3*sizeof(float), 0);
    vertexArray->enableAttribute(0);
    shader->use();
    projection = glm::perspective(glm::radians(65.0f), 1.0f, 0.1f, 100.0f);
    shader->setMat4f("projection", glm::value_ptr(projection));
}

void RendererApplication::renderLoop(float delta) {
    glm::mat4 view = camera.getView();
    shader->setMat4f("view", glm::value_ptr(view));

    Renderer::clear();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.3f, -1.0f));
    shader->setMat4f("model", glm::value_ptr(model));
    Renderer::drawArray(36);
}

void RendererApplication::onKeyPadInput(KeyPadKeys key) {
    switch (key) {
        case KEY_W:
        camera.moveCamera(FORWARD);
        break;
        case KEY_S:
        camera.moveCamera(BACKWARD);
        break;
        case KEY_A:
        camera.moveCamera(LEFT);
        break;
        case KEY_D:
        camera.moveCamera(RIGHT);
    }
}

void RendererApplication::onCursorMovement(double deltaX, double deltaY) {
    camera.rotateCamera(deltaX, deltaY);
}

void RendererApplication::deInit() {
    delete buffer;
    delete vertexArray;
    delete shader;
    delete texture1;
    Renderer::deinit();
}