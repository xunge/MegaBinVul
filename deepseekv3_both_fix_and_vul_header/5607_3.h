#include <stdint.h>
#include <memory>

typedef uint32_t WGC3Duint;
typedef uint32_t WebGLId;
typedef uint32_t GLenum;
typedef int32_t GLint;
typedef int32_t GLsizei;
typedef char GLchar;

#define GL_INVALID_VALUE 0x0501
#define GL_OUT_OF_MEMORY 0x0505
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A

struct ActiveInfo {
    void* name;
    GLenum type;
    GLint size;
};

class WebGraphicsContext3DImpl {
public:
    bool getActiveAttrib(WebGLId program, WGC3Duint index, ActiveInfo& info);
    void synthesizeGLError(GLenum error);
    struct {
        void GetProgramiv(WebGLId program, GLenum pname, GLint* params);
        void GetActiveAttrib(WebGLId program, WGC3Duint index, GLsizei bufSize, 
                            GLsizei* length, GLint* size, GLenum* type, GLchar* name);
    } *gl_;
};

namespace blink {
    class WebString {
    public:
        static void* fromUTF8(const GLchar* str, GLsizei length);
    };
}

template<typename T> class scoped_ptr {
private:
    T* ptr_;
public:
    explicit scoped_ptr(T* ptr) : ptr_(ptr) {}
    ~scoped_ptr() { delete[] ptr_; }
    T* get() const { return ptr_; }
    operator bool() const { return ptr_ != nullptr; }
};

template<> class scoped_ptr<GLchar[]> {
private:
    GLchar* ptr_;
public:
    explicit scoped_ptr(GLchar* ptr) : ptr_(ptr) {}
    ~scoped_ptr() { delete[] ptr_; }
    GLchar* get() const { return ptr_; }
    operator bool() const { return ptr_ != nullptr; }
};