#ifndef VERTEXARRAY
#define VERTEXARRAY
#include <vector>
class VertexArray {
    public:
    static VertexArray* create();
    virtual void addAttribute(unsigned int index, unsigned int componentCount, unsigned int strideLength, unsigned int offset) = 0;
    virtual std::vector<unsigned int> getAttributeIndexes() = 0;
    virtual void enableAttribute(unsigned int index) = 0;
    virtual void disableAttribute(unsigned int index) = 0;
    virtual void bind() = 0;
    virtual void unBind() = 0;
    virtual void deleteBuffer() = 0;
};
#endif