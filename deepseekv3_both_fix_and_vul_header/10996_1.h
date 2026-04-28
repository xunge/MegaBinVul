#include <stdint.h>
#include <stdbool.h>

struct pipe_box {
    int x, y, z;
    int width, height, depth;
};

struct pipe_blit_info {
    struct {
        int format;
        struct pipe_box box;
        int level;
    } src, dst;
    bool render_condition_enable;
    bool scissor_enable;
    int filter;
    bool alpha_blend;
    int mask;
};

struct vrend_resource_base {
    int format;
    int nr_samples;
};

struct vrend_resource {
    struct vrend_resource_base base;
};

struct vrend_sub_context {
    bool cond_render_gl_mode;
};

struct vrend_context {
    bool in_error;
    struct vrend_sub_context *sub;
};

enum virgl_formats {
    VIRGL_FORMAT_MAX
};

enum virgl_error {
    VIRGL_ERROR_CTX_ILLEGAL_RESOURCE,
    VIRGL_ERROR_CTX_ILLEGAL_FORMAT
};

enum pipe_tex_filter {
    PIPE_TEX_FILTER_NEAREST
};

enum pipe_mask {
    PIPE_MASK_RGBA
};

#define VREND_DEBUG(flag, ctx, ...) 

extern int dbg_blit;
extern int feat_copy_image;

const char* util_format_name(int format);
void report_context_error(struct vrend_context *ctx, enum virgl_error error, uint32_t handle);
void vrend_pause_render_condition(struct vrend_context *ctx, bool pause);
void vrend_copy_sub_image(struct vrend_resource *src, struct vrend_resource *dst, int src_level, struct pipe_box *src_box, int dst_level, int x, int y, int z);
void vrend_renderer_blit_int(struct vrend_context *ctx, struct vrend_resource *src, struct vrend_resource *dst, const struct pipe_blit_info *info);
struct vrend_resource *vrend_renderer_ctx_res_lookup(struct vrend_context *ctx, uint32_t handle);
bool has_feature(int feat);
bool format_is_copy_compatible(int src_format, int dst_format, bool strict);