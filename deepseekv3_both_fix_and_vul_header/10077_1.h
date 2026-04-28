#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define PIPE_MAX_COLOR_BUFS 8
#define GL_FRAMEBUFFER 0x8D40
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_EXT 0x8D40

typedef unsigned int GLenum;
typedef int GLint;

enum virgl_object_type {
    VIRGL_OBJECT_SURFACE
};

enum virgl_error {
    VIRGL_ERROR_CTX_ILLEGAL_SURFACE
};

struct pipe_resource {
    int height0;
};

struct vrend_texture {
    struct pipe_resource base;
    bool y_0_top;
};

struct vrend_surface {
    struct vrend_texture *texture;
    int val0;
};

struct vrend_sub_context {
    unsigned fb_id;
    struct vrend_surface *zsurf;
    struct vrend_surface *surf[PIPE_MAX_COLOR_BUFS];
    int nr_cbufs;
    int old_nr_cbufs;
    int fb_height;
    bool inverted_fbo_content;
    unsigned scissor_state_dirty;
    unsigned viewport_state_dirty;
    bool shader_dirty;
    void *object_hash;
};

struct vrend_context {
    struct vrend_sub_context *sub;
    char *debug_name;
};

static inline int u_minify(int value, int level) {
    return value >> level;
}

void glBindFramebufferEXT(GLenum target, unsigned int framebuffer);
GLenum glCheckFramebufferStatus(GLenum target);
void report_context_error(struct vrend_context *ctx, enum virgl_error error, uint32_t handle);
void vrend_surface_reference(struct vrend_surface **ptr, struct vrend_surface *surf);
void vrend_hw_set_zsurf_texture(struct vrend_context *ctx);
void vrend_hw_set_color_surface(struct vrend_context *ctx, int index);
void vrend_hw_emit_framebuffer_state(struct vrend_context *ctx);
struct vrend_surface *vrend_object_lookup(void *object_hash, uint32_t handle, enum virgl_object_type type);