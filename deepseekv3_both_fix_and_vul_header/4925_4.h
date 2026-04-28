#include <stdbool.h>

typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef int GLint;
typedef float GLfloat;
typedef unsigned char GLboolean;
typedef int GLsizei;

#define GL_TRUE 1
#define GL_FALSE 0
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_SCISSOR_TEST 0x0C11
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_NONE 0
#define GL_BACK 0x0405
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506

struct GLES2Util {
    static unsigned int GetChannelsForFormat(GLenum format);
};

struct State {
    void SetDeviceColorMask(GLboolean r, GLboolean g, GLboolean b, GLboolean a);
    void SetDeviceStencilMaskSeparate(GLenum face, GLuint mask);
    void SetDeviceDepthMask(GLboolean flag);
    void SetDeviceCapabilityState(GLenum cap, GLboolean enabled);
};

class TextureManager {
public:
    bool HaveUnclearedMips() const;
};

struct Framebuffer {
    GLenum IsPossiblyComplete();
    bool IsCleared();
    GLenum GetStatus(TextureManager* texture_manager, GLenum target);
};

class GLES2DecoderImpl {
public:
    unsigned int backbuffer_needs_clear_bits_;
    State state_;
    class Group {
    public:
        GLenum draw_buffer() const;
    };
    Group* group_;
    GLenum offscreen_target_color_format_;

    GLuint GetBackbufferServiceId() const;
    void RestoreClearState();
    void ClearUnclearedAttachments(GLenum target, Framebuffer* framebuffer);
    class FramebufferManager {
    public:
        bool IsComplete(Framebuffer* framebuffer) const;
        void MarkAsComplete(Framebuffer* framebuffer);
    };
    FramebufferManager* framebuffer_manager();
    class RenderbufferManager {
    public:
        bool HaveUnclearedRenderbuffers() const;
    };
    RenderbufferManager* renderbuffer_manager();
    TextureManager* texture_manager();

    void LOCAL_SET_GL_ERROR(GLenum error, const char* function_name, const char* description);
    bool CheckFramebufferValid(Framebuffer* framebuffer, GLenum target, const char* func_name);
};

void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearStencil(GLint s);
void glClearDepth(GLfloat depth);
void glClear(GLbitfield mask);
void glDrawBuffersARB(GLsizei n, const GLenum* bufs);