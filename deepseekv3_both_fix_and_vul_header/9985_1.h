#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define PIPE_SHADER_GEOMETRY 2
#define VIRGL_OBJ_SHADER_OFFSET_CONT 0x80000000
#define VIRGL_OBJECT_SHADER 0
#define EINVAL 22
#define ENOMEM 12

struct pipe_stream_output_info;

struct tgsi_token {
    uint32_t data[4];
};

struct vrend_sub_context {
    uint32_t long_shader_in_progress_handle[3];
    void *object_hash;
};

struct vrend_shader_selector {
    uint32_t buf_len;
    uint32_t buf_offset;
    char *tmp_buf;
};

struct vrend_context {
    struct vrend_sub_context *sub;
};

extern bool vrend_dump_shaders;
extern bool tgsi_text_translate(const char *text, struct tgsi_token *tokens, uint32_t num_tokens);
extern struct vrend_shader_selector *vrend_create_shader_state(struct vrend_context *ctx, const struct pipe_stream_output_info *so_info, uint32_t type);
extern struct vrend_shader_selector *vrend_object_lookup(struct vrend_sub_context *sub, uint32_t handle, uint32_t type);
extern int vrend_renderer_object_insert(struct vrend_context *ctx, void *data, size_t size, uint32_t handle, uint32_t type);
extern void vrend_renderer_object_destroy(struct vrend_context *ctx, uint32_t handle);
extern void vrend_destroy_shader_selector(struct vrend_shader_selector *sel);
extern bool vrend_finish_shader(struct vrend_context *ctx, struct vrend_shader_selector *sel, struct tgsi_token *tokens);