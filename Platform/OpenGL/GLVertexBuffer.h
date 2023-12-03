#ifndef GLVERTETBUFFER
#define GLVERTETBUFFER
#ifndef VERTEXBUFFER
#include<VertexBuffer.h>
#endif
class GLVertexBuffer: public VertexBuffer {
    public:
    GLVertexBuffer(void* data, unsigned int size);
    virtual void bind() override;
    virtual void unBind() override;
    virtual void deleteBuffer() override;
    ~GLVertexBuffer();
    private:
    unsigned int ID;
};
#endif