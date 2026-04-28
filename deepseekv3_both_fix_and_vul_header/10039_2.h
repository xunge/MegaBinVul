#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define PIPE_MAX_ATTRIBS 32
#define CALLOC_STRUCT(type) (struct type *)calloc(1, sizeof(struct type))
#define FREE(ptr) free(ptr)

typedef unsigned int GLenum;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_FLOAT 0x1406
#define GL_DOUBLE 0x140A
#define GL_HALF_FLOAT 0x140B
#define GL_UNSIGNED_BYTE 0x1401
#define GL_BYTE 0x1400
#define GL_UNSIGNED_SHORT 0x1403
#define GL_SHORT 0x1402
#define GL_UNSIGNED_INT 0x1405
#define GL_INT 0x1404
#define GL_INT_2_10_10_10_REV 0x8D9F
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_BGRA 0x80E1

enum util_format_type {
    UTIL_FORMAT_TYPE_FLOAT,
    UTIL_FORMAT_TYPE_UNSIGNED,
    UTIL_FORMAT_TYPE_SIGNED
};

enum util_format_swizzle {
    UTIL_FORMAT_SWIZZLE_X,
    UTIL_FORMAT_SWIZZLE_Y,
    UTIL_FORMAT_SWIZZLE_Z,
    UTIL_FORMAT_SWIZZLE_W
};

enum pipe_format {
    PIPE_FORMAT_R10G10B10A2_SSCALED,
    PIPE_FORMAT_R10G10B10A2_SNORM,
    PIPE_FORMAT_B10G10R10A2_SNORM,
    PIPE_FORMAT_R10G10B10A2_USCALED,
    PIPE_FORMAT_R10G10B10A2_UNORM,
    PIPE_FORMAT_B10G10R10A2_UNORM,
    PIPE_FORMAT_R11G11B10_FLOAT
};

enum virgl_error {
    VIRGL_ERROR_CTX_ILLEGAL_VERTEX_FORMAT
};

enum virgl_object_type {
    VIRGL_OBJECT_VERTEX_ELEMENTS
};

struct pipe_vertex_element {
    unsigned src_format;
    unsigned src_offset;
    unsigned vertex_buffer_index;
    unsigned instance_divisor;
};

struct util_format_description {
    struct {
        enum util_format_type type;
        unsigned size;
        unsigned normalized;
    } channel[4];
    unsigned nr_channels;
    unsigned swizzle[4];
};

struct vrend_vertex_element {
    struct pipe_vertex_element base;
    GLenum type;
    GLboolean norm;
    unsigned nr_chan;
};

struct vrend_vertex_element_array {
    unsigned count;
    struct vrend_vertex_element elements[PIPE_MAX_ATTRIBS];
    GLuint id;
};

struct vrend_context;
struct vrend_state {
    int have_vertex_attrib_binding;
};

extern struct vrend_state vrend_state;

const struct util_format_description *util_format_description(enum pipe_format format);
int util_format_is_pure_integer(enum pipe_format format);
void report_context_error(struct vrend_context *ctx, enum virgl_error error, unsigned format);
uint32_t vrend_renderer_object_insert(struct vrend_context *ctx, void *obj, size_t size, uint32_t handle, enum virgl_object_type type);
void glGenVertexArrays(int n, GLuint *arrays);
void glBindVertexArray(GLuint array);
void glVertexAttribIFormat(GLuint attribindex, int size, GLenum type, GLuint relativeoffset);
void glVertexAttribFormat(GLuint attribindex, int size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
void glEnableVertexAttribArray(GLuint index);