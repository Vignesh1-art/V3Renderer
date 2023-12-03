#ifndef ELEMENTARRAY
#define ELEMENTARRAY

class ElementArray {
    public:
    static ElementArray* create(unsigned int *data, unsigned int size);
    virtual void bind() = 0;
    virtual void unBind() = 0;
    virtual unsigned int getArrayCount() = 0;
    virtual void deleteArray() = 0;
};
#endif