#include <stdint.h>

typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef int GLint;
typedef float GLfloat;
typedef int GLboolean;
#define GL_FRAMEBUFFER_EXT 0
#define GL_COLOR 0
#define GL_COLOR_BUFFER_BIT 0
#define GL_DEPTH_BUFFER_BIT 0
#define GL_STENCIL_BUFFER_BIT 0
#define GL_TRUE 1
#define GL_FALSE 0

struct vrend_context {
    int in_error;
    int ctx_switch_pending;
    struct {
        GLuint fb_id;
        int nr_cbufs;
        struct {
            unsigned format;
        } *surf[8];
        int stencil_state_dirty;
        int scissor_state_dirty;
        int viewport_state_dirty;
        struct {
            struct {
                GLboolean writemask;
            } depth;
        } dsa_state;
    } *sub;
};

union pipe_color_union {
    float f[4];
    uint32_t ui[4];
    int32_t i[4];
};

#define PIPE_CLEAR_COLOR 0x1
#define PIPE_CLEAR_DEPTH 0x2
#define PIPE_CLEAR_STENCIL 0x4
#define PIPE_MAX_COLOR_BUFS 8

static inline int u_bit_scan(uint32_t *mask) {
    int i = __builtin_ffs(*mask) - 1;
    *mask ^= (1 << i);
    return i;
}

static int vrend_format_is_emulated_alpha(unsigned format) {
    return 0;
}

static int util_format_is_pure_uint(unsigned format) {
    return 0;
}

static int util_format_is_pure_sint(unsigned format) {
    return 0;
}

void glBindFramebufferEXT(int, GLuint);
void glClearColor(GLfloat, GLfloat, GLfloat, GLfloat);
void glDepthMask(GLboolean);
void glClearDepth(double);
void glClearStencil(unsigned);
void glClearBufferuiv(int, int, GLuint*);
void glClearBufferiv(int, int, GLint*);
void glClearBufferfv(int, int, GLfloat*);
void glClear(GLbitfield);

void vrend_finish_context_switch(struct vrend_context *ctx);
void vrend_update_frontface_state(struct vrend_context *ctx);
void vrend_update_stencil_state(struct vrend_context *ctx);
void vrend_update_scissor_state(struct vrend_context *ctx);
void vrend_update_viewport_state(struct vrend_context *ctx);
void vrend_use_program(struct vrend_context *ctx, int program);