#ifndef TEXTURE
#define TEXTURE
#include <string>
class Texture {
    public:
    static Texture* create(std::string filename);
    virtual void bind(unsigned int unit) = 0;
    virtual void unBind() = 0;
    virtual void deleteTexture() = 0;
    static Texture create();
};

#endif