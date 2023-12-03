#ifndef GLRENDERERCOMMAND
#define GLRENDERERCOMMAND
#ifndef RENDERERCOMMAND
#include <RendererCommand.h>
#endif
class GLRendererCommand: public RendererCommand {
    public:
    GLRendererCommand();
    virtual void setViewPort(unsigned int posx, unsigned int posy, unsigned int length, unsigned int width) override;
    virtual void setClearColor(float r, float g, float b, float a) override;
    virtual void clearColor() override;
    virtual void drawIndexedElements(unsigned int count) override;
    virtual void drawArrays(unsigned int count) override;
};
#endif