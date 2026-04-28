#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef unsigned int GLuint;
typedef int GLint;
typedef unsigned int GLenum;
typedef int GLsizei;

#define GL_FALSE 0
#define GL_LINK_STATUS 0x8B82
#define VIRGL_ERROR_CTX_ILLEGAL_SHADER 0

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct vrend_shader_info {
    uint32_t attrib_input_mask;
    uint32_t samplers_used_mask;
    uint32_t shadow_samp_mask;
    int num_outputs;
    int num_inputs;
    int num_consts;
    int num_ubos;
    int num_ucp;
};

struct vrend_shader_selector {
    struct vrend_shader_info sinfo;
};

struct vrend_shader {
    GLuint id;
    GLuint compiled_fs_id;
    char *glsl_prog;
    struct vrend_shader_selector *sel;
    struct list_head programs;
    struct {
        bool flatshade;
        bool pstipple_tex;
    } key;
};

struct vrend_sub_context {
    struct list_head programs;
    struct {
        bool dual_src;
    } blend_state;
};

struct vrend_context {
    struct vrend_sub_context *sub;
};

struct vrend_linked_shader_program {
    GLuint id;
    bool dual_src_linked;
    struct vrend_shader *ss[3];
    struct list_head sl[3];
    struct list_head head;
    int fs_stipple_loc;
    int vs_ws_adjust_loc;
    uint32_t *samp_locs[3];
    uint32_t *shadow_samp_mask_locs[3];
    uint32_t *shadow_samp_add_locs[3];
    uint32_t shadow_samp_mask[3];
    uint32_t samplers_used_mask[3];
    uint32_t *const_locs[3];
    uint32_t *attrib_locs;
    uint32_t *ubo_locs[3];
    int clip_locs[8];
};

enum pipe_shader_type {
    PIPE_SHADER_VERTEX,
    PIPE_SHADER_FRAGMENT,
    PIPE_SHADER_GEOMETRY
};

#define CALLOC_STRUCT(T) ((struct T *)calloc(1, sizeof(struct T)))

struct vrend_state {
    bool have_vertex_attrib_binding;
};

extern struct vrend_state vrend_state;

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

static inline void list_addtail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline int u_bit_scan(uint32_t *mask) {
    int i = __builtin_ffs(*mask) - 1;
    *mask &= ~(1 << i);
    return i;
}

static inline int util_bitcount(uint32_t n) {
    return __builtin_popcount(n);
}

static inline bool util_blend_state_is_dual(const void *blend_state, int index) {
    return false;
}

static inline const char *pipe_shader_to_prefix(int shader) {
    static const char *prefixes[] = {"vs", "fs", "gs"};
    return prefixes[shader];
}

static inline void set_stream_out_varyings(GLuint prog_id, const struct vrend_shader_info *sinfo) {
}

static inline bool vrend_compile_shader(struct vrend_context *ctx, struct vrend_shader *shader) {
    return false;
}

static inline void vrend_patch_vertex_shader_interpolants(char *glsl_prog,
                                                         const struct vrend_shader_info *src,
                                                         const struct vrend_shader_info *dst,
                                                         bool is_gs, bool flatshade) {
}

static inline void report_context_error(struct vrend_context *ctx, int error, int param) {
}

GLuint glCreateProgram(void);
void glAttachShader(GLuint program, GLuint shader);
void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const char *name);
void glBindAttribLocation(GLuint program, GLuint index, const char *name);
void glLinkProgram(GLuint program);
void glGetProgramiv(GLuint program, GLenum pname, GLint *params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, char *infoLog);
void glDeleteProgram(GLuint program);
GLint glGetUniformLocation(GLuint program, const char *name);
GLuint glGetUniformBlockIndex(GLuint program, const char *name);
GLint glGetAttribLocation(GLuint program, const char *name);
void glDeleteShader(GLuint shader);