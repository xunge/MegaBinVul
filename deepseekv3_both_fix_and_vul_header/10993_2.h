#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct pipe_reference {
    int count;
};

struct vrend_renderer_resource_create_args {
    uint32_t flags;
    uint32_t bind;
    uint32_t target;
    uint32_t width;
    uint32_t handle;
};

struct vrend_resource {
    struct {
        struct pipe_reference reference;
    } base;
    void *ptr;
    uint32_t storage;
    uint32_t target;
    bool y_0_top;
    struct iovec *iov;
    uint32_t num_iovs;
};

struct vrend_texture {
    struct vrend_resource base;
};

#define CALLOC_STRUCT(type) calloc(1, sizeof(struct type))
#define FREE(ptr) free(ptr)

#define VIRGL_RESOURCE_Y_0_TOP (1 << 0)
#define VIRGL_BIND_CUSTOM 0
#define VIRGL_BIND_STAGING 1
#define VIRGL_BIND_INDEX_BUFFER 2
#define VIRGL_BIND_STREAM_OUTPUT 3
#define VIRGL_BIND_VERTEX_BUFFER 4
#define VIRGL_BIND_CONSTANT_BUFFER 5
#define VIRGL_BIND_QUERY_BUFFER 6
#define VIRGL_BIND_COMMAND_ARGS 7
#define VIRGL_BIND_SHADER_BUFFER 8
#define VIRGL_BIND_SAMPLER_VIEW 9

#define PIPE_BUFFER 0

#define VREND_RESOURCE_STORAGE_GUEST 0
#define VREND_RESOURCE_STORAGE_GUEST_ELSE_SYSTEM 1

#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_QUERY_BUFFER 0x9192
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB

#define EINVAL 22
#define ENOMEM 12

static inline void pipe_reference_init(struct pipe_reference *ref, int count) {
    ref->count = count;
}

#define feat_arb_or_gles_ext_texture_buffer 1

int check_resource_valid(struct vrend_renderer_resource_create_args *args);
void vrend_renderer_resource_copy_args(struct vrend_renderer_resource_create_args *args, struct vrend_resource *gr);
void vrend_create_buffer(struct vrend_resource *gr, uint32_t width);
int vrend_renderer_resource_allocate_texture(struct vrend_resource *gr, void *image_oes);
int vrend_resource_insert(struct vrend_resource *gr, uint32_t handle);
void vrend_renderer_resource_destroy(struct vrend_resource *gr);
bool has_feature(int feat);