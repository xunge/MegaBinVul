#include <stdbool.h>
#include <stdint.h>

#define VREND_GL_VER_MAJOR 0
#define VREND_GL_VER_MINOR 0
#define GL_ARRAY_BUFFER 0x8892

typedef uint32_t GLuint;
typedef uint32_t GLenum;

struct virgl_gl_ctx_param {
    bool shared;
    int major_ver;
    int minor_ver;
};

struct vrend_blitter_ctx {
    bool initialised;
    void *gl_context;
    GLuint vaoid;
    GLuint fb_id;
    GLuint vbo_id;
    float vertices[4][1][4];
};

extern struct {
    void *(*create_gl_context)(int, struct virgl_gl_ctx_param *);
    void (*make_current)(int, void *);
} *vrend_clicbs;

void glGenVertexArrays(int, GLuint *);
void glGenFramebuffers(int, GLuint *);
void glGenBuffers(int, GLuint *);
void glBindVertexArray(GLuint);
void glBindBuffer(GLenum, GLuint);

void blit_build_vs_passthrough(struct vrend_blitter_ctx *blit_ctx);