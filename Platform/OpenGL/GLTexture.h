#ifndef GLTEXTURE
#define GLTEXTURE
#ifndef TEXTURE
#include<Texture.h>
#endif
class GLTexture: public Texture {
    public:
    GLTexture(std::string filename);
    virtual void bind(unsigned int unit) override;
    virtual void unBind() override;
    virtual void deleteTexture() override;
    ~GLTexture();
    private:
    unsigned int ID;
};
#endif