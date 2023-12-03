#ifndef GLVERTEXARRAY
#define GLVERTEXARRAY
#ifndef VERTEXARRAY
#include <VertexArray.h>
#endif
class GLVertexArray: public VertexArray {
    public:
    GLVertexArray();
    virtual void addAttribute(unsigned int index, unsigned int componentCount, unsigned int strideLength, unsigned int offset) override;
    virtual std::vector<unsigned int> getAttributeIndexes() override;
    virtual void enableAttribute(unsigned int index) override;
    virtual void disableAttribute(unsigned int index) override;
    virtual void bind() override;
    virtual void unBind() override;
    virtual void deleteBuffer() override;
    ~GLVertexArray();
    private:
    unsigned int ID;
    std::vector<unsigned int> attributeIndexes;
};

#endif

