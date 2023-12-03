#ifndef GLELEMENTARRAY
#define GLELEMENTARRAY
#ifndef ELEMENTARRAY
#include <ElementArray.h>
#endif
class GLElementArray: public ElementArray {
    public:
    GLElementArray(unsigned int *data, unsigned int size);
    virtual unsigned int getArrayCount() override;
    virtual void bind() override;
    virtual void unBind() override;
    virtual void deleteArray() override;
    ~GLElementArray();
    private:
    unsigned int ID;
    unsigned int count;
};

#endif