#ifndef RENDERER
#define RENDERER
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "ElementArray.h"
#include "Texture.h"
#include "RendererCommand.h"

class Renderer {
    public:
    static void init();
    static void deinit();
    static void setViewPort(unsigned int pox, unsigned int poy, unsigned int heigth, unsigned int width);
    static void setClearColor(float r, float g, float b, float a);
    static void clear();
    static void drawIndexed(unsigned int count);
    static void drawArray(unsigned int count);
    private:
    static RendererCommand *command;
};

#endif