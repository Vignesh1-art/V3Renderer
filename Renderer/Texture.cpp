#include "Texture.h"
#include <GLTexture.h>
#include <string>

Texture* Texture::create(std::string filename) {
    return new GLTexture(filename);
}

