#include <stddef.h>
#include <stdint.h>

#define GL_RGBA 0x1908
#define GL_UNSIGNED_BYTE 0x1401
#define GL_TEXTURE_2D 0x0DE1
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_NO_ERROR 0
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803

#define SDL_FALSE 0

typedef unsigned int GLenum;
typedef unsigned int GLuint;
typedef int GLint;
typedef float GLfloat;
typedef size_t GLsizei;

typedef enum {
    SDL_PIXELFORMAT_ABGR8888,
    SDL_TEXTUREACCESS_STREAMING,
    SDL_TEXTUREACCESS_TARGET
} SDL_EnumDefs;

typedef enum {
    SDL_ScaleModeNearest
} SDL_ScaleMode;

typedef struct SDL_Renderer {
    void *driverdata;
} SDL_Renderer;

typedef struct SDL_Texture {
    int format;
    int access;
    int w;
    int h;
    SDL_ScaleMode scaleMode;
    void *driverdata;
} SDL_Texture;

typedef struct {
    SDL_Texture *texture;
    int texturing;
} GLES_DrawState;

typedef struct GLES_RenderData {
    void *driverdata;
    GLES_DrawState drawstate;
    int GL_OES_framebuffer_object_supported;
    GLenum (*glGetError)(void);
    void (*glEnable)(GLenum);
    void (*glGenTextures)(GLsizei, GLuint*);
    void (*glBindTexture)(GLenum, GLuint);
    void (*glTexParameteri)(GLenum, GLenum, GLint);
    void (*glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*);
    void (*glDisable)(GLenum);
} GLES_RenderData;

typedef struct GLES_TextureData {
    GLuint texture;
    GLenum type;
    GLenum format;
    GLenum formattype;
    GLfloat texw;
    GLfloat texh;
    int pitch;
    void *pixels;
    void *fbo;
} GLES_TextureData;

void* SDL_calloc(size_t, size_t);
void SDL_free(void*);
int SDL_SetError(const char*);
int SDL_OutOfMemory();
int GLES_SetError(const char*, GLenum);
int SDL_powerof2(int);
int GLES_ActivateRenderer(SDL_Renderer*);
void* GLES_GetFBO(void*, int, int);
#define SDL_BYTESPERPIXEL(x) 4