#include "VertexArray.h"
#include <GLVertexArray.h>

VertexArray* VertexArray::create() {
    return new GLVertexArray();
}