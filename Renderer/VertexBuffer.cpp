#include "VertexBuffer.h"
#include <GLVertexBuffer.h>
VertexBuffer* VertexBuffer::create(void* data, unsigned int size) {
    return new GLVertexBuffer(data, size);
}