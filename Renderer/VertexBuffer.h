#ifndef VERTEXBUFFER
#define VERTEXBUFFER

class VertexBuffer {
    public:
    static VertexBuffer* create(void* data, unsigned int size);
    virtual void bind() = 0;
    virtual void unBind() = 0;
    virtual void deleteBuffer() = 0;
};
#endif