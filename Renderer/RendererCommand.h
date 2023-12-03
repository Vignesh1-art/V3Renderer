#ifndef RENDERERCOMMAND
#define RENDERERCOMMAND

class RendererCommand {
    public:
    static RendererCommand* create();
    static void destroy();
    virtual void setViewPort(unsigned int posx, unsigned int posy, unsigned int length, unsigned int width) = 0;
    virtual void setClearColor(float r, float g, float b, float a) = 0;
    virtual void clearColor() = 0;
    virtual void drawIndexedElements(unsigned int count) = 0;
    virtual void drawArrays(unsigned int count) = 0;
    private:
    static RendererCommand *singleton;
};

#endif