#include <string>
#include <memory>

typedef unsigned int WebGLId;
typedef unsigned int WGC3Duint;
typedef unsigned int GLenum;
typedef int GLint;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef char GLchar;

#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_INVALID_VALUE 0x0501
#define GL_OUT_OF_MEMORY 0x0505

struct GLInterface {
    void GetProgramiv(WebGLId program, GLenum pname, GLint* params);
    void GetActiveUniform(WebGLId program, WGC3Duint index, GLsizei bufSize,
                         GLsizei* length, GLint* size, GLenum* type, GLchar* name);
};

struct ActiveInfo {
    std::string name;
    GLenum type;
    GLint size;
};

class WebGraphicsContext3DImpl {
private:
    GLInterface* gl_;
public:
    void synthesizeGLError(GLenum error);
    bool getActiveUniform(WebGLId program, WGC3Duint index, ActiveInfo& info);
};

template<typename T> class scoped_ptr {
private:
    T* ptr;
public:
    explicit scoped_ptr(T* p) : ptr(p) {}
    ~scoped_ptr() { delete[] ptr; }
    T* get() const { return ptr; }
    operator bool() const { return ptr != nullptr; }
};

namespace blink {
    class WebString {
    public:
        static std::string fromUTF8(const char* str, GLsizei length) {
            return std::string(str, length);
        }
    };
}

template<>
class scoped_ptr<GLchar[]> {
private:
    GLchar* ptr;
public:
    explicit scoped_ptr(GLchar* p) : ptr(p) {}
    ~scoped_ptr() { delete[] ptr; }
    GLchar* get() const { return ptr; }
    operator bool() const { return ptr != nullptr; }
};