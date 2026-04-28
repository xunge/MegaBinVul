typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef int GLint;
typedef unsigned char GLboolean;
typedef float GLfloat;

#define GL_READ_FRAMEBUFFER_EXT 0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_SCISSOR_TEST 0x0C11
#define GL_TRUE 1

class Framebuffer;
class RenderbufferManager;
class TextureManager;

class GLES2Util {
public:
    static int GetChannelsForFormat(GLenum format);
};

class FramebufferManager {
public:
    void MarkAttachmentsAsCleared(Framebuffer* framebuffer,
                                 RenderbufferManager* renderbuffer_manager,
                                 TextureManager* texture_manager);
};

class GLES2DecoderImpl {
public:
    struct State {
        void SetDeviceColorMask(GLboolean, GLboolean, GLboolean, GLboolean);
        void SetDeviceStencilMaskSeparate(GLenum, GLint);
        void SetDeviceDepthMask(GLboolean);
        void SetDeviceCapabilityState(GLenum, bool);
    };
    
    State state_;
    
    Framebuffer* GetFramebufferInfoForTarget(GLenum target);
    GLuint GetBackbufferServiceId();
    void RestoreClearState();
    
    FramebufferManager* framebuffer_manager();
    RenderbufferManager* renderbuffer_manager();
    TextureManager* texture_manager();

    void ClearUnclearedAttachments(GLenum target, Framebuffer* framebuffer);
};

class Framebuffer {
public:
    GLuint service_id();
    bool HasUnclearedColorAttachments();
    bool HasUnclearedAttachment(GLenum attachment);
    GLenum GetColorAttachmentFormat();
    void PrepareDrawBuffersForClear();
    void RestoreDrawBuffersAfterClear();
};

void glBindFramebufferEXT(GLenum target, GLuint framebuffer);
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearStencil(GLint s);
void glClearDepth(GLfloat depth);
void glClear(GLbitfield mask);