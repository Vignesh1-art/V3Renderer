#include "ElementArray.h"
#include <GLElementArray.h>

ElementArray* ElementArray::create(unsigned int *data, unsigned int size) {
    return new GLElementArray(data, size);
}