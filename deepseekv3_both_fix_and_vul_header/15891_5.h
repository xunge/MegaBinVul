#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define GL_DISPATCH_INDIRECT_BUFFER 0
#define VIRGL_ERROR_CTX_ILLEGAL_RESOURCE 0
#define UNUSED __attribute__((unused))

typedef unsigned int GLuint;

enum pipe_shader_type {
    PIPE_SHADER_VERTEX,
    PIPE_SHADER_COMPUTE
};

enum feature_flags {
    feat_compute_shader
};

struct vrend_resource {
    GLuint id;
};

struct vrend_linked_shader_program {
    GLuint id;
    void *ref_context;
};

struct vrend_shader {
    struct vrend_shader_variant *current;
};

struct vrend_shader_variant {
    GLuint id;
};

struct vrend_sub_context {
    bool cs_shader_dirty;
    bool shader_dirty;
    struct vrend_shader *shaders[2];
    struct vrend_linked_shader_program *prog;
    int prog_ids[2];
};

struct vrend_context {
    struct vrend_sub_context *sub;
    const char *debug_name;
};

bool has_feature(enum feature_flags feat);
void vrend_printf(const char *format, ...);
void vrend_shader_select(struct vrend_context *ctx, struct vrend_shader *shader, bool *dirty);
struct vrend_linked_shader_program *lookup_cs_shader_program(struct vrend_context *ctx, GLuint id);
struct vrend_linked_shader_program *add_cs_shader_program(struct vrend_context *ctx, struct vrend_shader_variant *variant);
void vrend_use_program(struct vrend_context *ctx, GLuint id);
void vrend_draw_bind_ubo_shader(struct vrend_context *ctx, enum pipe_shader_type type, int index);
void vrend_draw_bind_const_shader(struct vrend_context *ctx, enum pipe_shader_type type, bool new_program);
void vrend_draw_bind_samplers_shader(struct vrend_context *ctx, enum pipe_shader_type type, int index);
void vrend_draw_bind_images_shader(struct vrend_context *ctx, enum pipe_shader_type type);
void vrend_draw_bind_ssbo_shader(struct vrend_context *ctx, enum pipe_shader_type type);
void vrend_draw_bind_abo_shader(struct vrend_context *ctx);
struct vrend_resource *vrend_renderer_ctx_res_lookup(struct vrend_context *ctx, uint32_t handle);
void report_context_error(struct vrend_context *ctx, int error, uint32_t handle);
void glBindBuffer(int target, GLuint buffer);
void glDispatchComputeIndirect(uint32_t offset);
void glDispatchCompute(uint32_t x, uint32_t y, uint32_t z);