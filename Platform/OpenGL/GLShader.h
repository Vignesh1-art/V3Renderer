#ifndef GLSHADER
#define GLSHADER
#include <string>
#ifndef SHADERS
#include <Shader.h>
#endif
class GLShader: public Shader {
    public:
    GLShader();
    void addShader(const char *shaderSource, ShaderType type) override;
    virtual void link() override;
    // use activate the shader
    virtual void use() override;
    // utility uniform functions
    virtual void setBool(const std::string &name, bool value) override;  
    virtual void setInt(const std::string &name, int value) override;   
    virtual void setFloat(const std::string &name, float value) override;
    virtual void setMat4f(const std::string &name, float *values) override;
    virtual void deleteShader() override;
    ~GLShader();
    unsigned int getID() const {
        return ID;
    }
    private:
    // the program ID
    unsigned int ID;
};
#endif