#ifndef SHADERS
#define SHADERS
#include<string>

enum ShaderType {
    VERTEX_SHADER, FARGMENT_SHADER
};

class Shader {
public:  
    // Builds Shader object
    static Shader* create();
    virtual void addShader(const char *shaderSource, ShaderType type) = 0;
    virtual void link() = 0;
    // use activate the shader
    virtual void use() = 0;
    // utility uniform functions
    virtual void setBool(const std::string &name, bool value) = 0;  
    virtual void setInt(const std::string &name, int value) = 0;   
    virtual void setFloat(const std::string &name, float value) = 0;
    virtual void setMat4f(const std::string &name, float *values) = 0;
    virtual void deleteShader() = 0;
    unsigned int getID() const {
        return ID;
    }
    private:
    // the program ID
    unsigned int ID;
};

#endif
