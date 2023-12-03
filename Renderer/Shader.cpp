#include "Shader.h"
#include <GLShader.h>

Shader* Shader::create() {
    return new GLShader();
}
