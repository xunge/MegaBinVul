#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

typedef unsigned int GLenum;
typedef unsigned int GLuint;
typedef int GLint;
typedef unsigned int GLbitfield;
typedef void* GLeglImageOES;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef unsigned int uint;

#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_TEXTURE_3D 0x806F
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_TEXTURE_RECTANGLE_NV 0x84F5
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_TRUE 1
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D

#define EINVAL 22

enum virgl_formats {
    VIRGL_FORMAT_R8_UNORM,
    VIRGL_FORMAT_RG8_UNORM,
    VIRGL_FORMAT_RGBA8_UNORM
};

#define VIRGL_TEXTURE_CAN_TEXTURE_STORAGE (1 << 0)
#define VIRGL_BIND_PREFER_EMULATED_BGRA (1 << 0)

#define VREND_STORAGE_GL_IMMUTABLE (1 << 0)
#define VREND_STORAGE_EGL_IMAGE (1 << 1)
#define VREND_STORAGE_GL_TEXTURE (1 << 2)

#define feat_texture_storage 0
#define feat_egl_image_storage 1
#define feat_egl_image_external 2

#define GLES_WARN_TEXTURE_RECT 0
#define dbg_tex 0

static inline bool has_bit(unsigned int bits, unsigned int bit)
{
    return (bits & bit) != 0;
}

#define VREND_DEBUG(type, ctx, fmt) do {} while(0)
#define FREE(ptr) free(ptr)

struct virgl_texture_format_desc {
    GLenum internalformat;
    GLenum glformat;
    GLenum gltype;
    unsigned int flags;
};

struct pipe_resource {
    unsigned int width0;
    unsigned int height0;
    unsigned int depth0;
    unsigned int array_size;
    unsigned int nr_samples;
    unsigned int last_level;
    unsigned int target;
    unsigned int bind;
    enum virgl_formats format;
};

struct vrend_resource {
    struct pipe_resource base;
    GLuint id;
    GLenum target;
    unsigned int storage_bits;
    void* gbm_bo;
    void* egl_image;
    void* aux_plane_egl_image[4];
};

struct vrend_texture {
    struct vrend_resource base;
    struct {
        int max_lod;
    } state;
    int cur_swizzle_r;
    int cur_swizzle_g;
    int cur_swizzle_b;
    int cur_swizzle_a;
    int cur_base;
    int cur_max;
};

struct vrend_state {
    bool use_gles;
};

extern struct vrend_state vrend_state;
extern const struct virgl_texture_format_desc tex_conv_table[];
extern bool has_feature(unsigned feat);
extern unsigned u_minify(unsigned value, unsigned level);
extern GLenum tgsitargettogltarget(unsigned target, unsigned nr_samples);
extern void debug_texture(const char *func, struct vrend_resource *gr);
extern void vrend_printf(const char *fmt, ...);
extern void report_gles_warn(void *ctx, unsigned warn);
extern void report_gles_missing_func(void *ctx, const char *func);
extern void vrend_resource_gbm_init(struct vrend_resource *gr, enum virgl_formats format);
extern enum virgl_formats vrend_format_replace_emulated(unsigned bind, enum virgl_formats format);

void glGenTextures(GLsizei n, GLuint *textures);
void glBindTexture(GLenum target, GLuint texture);
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glEGLImageTargetTexStorageEXT(GLenum target, GLeglImageOES image, const GLint* attrib_list);
void glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image);