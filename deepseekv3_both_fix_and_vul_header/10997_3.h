#include <sys/uio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>

#define GL_MAP_INVALIDATE_RANGE_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_TEXTURE_3D 0x806F
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_FRAMEBUFFER 0x8D40
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_BGRA 0x80E1
#define GL_UNSIGNED_BYTE 0x1401
#define GL_DEPTH_SCALE 0x0D1E
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_BLEND 0x0BE2
#define GL_DEPTH_TEST 0x0B71
#define GL_ALPHA_TEST 0x0BC0
#define GL_STENCIL_TEST 0x0B90
#define VR_MAX_TEXTURE_2D_LEVELS 16

typedef uint32_t GLuint;
typedef uint32_t GLenum;
typedef float GLfloat;
typedef unsigned char GLboolean;
typedef void* GLvoid;
typedef int32_t GLint;
typedef uint32_t GLbitfield;
typedef intptr_t GLintptr;
typedef size_t GLsizeiptr;
typedef int32_t GLsizei;

struct vrend_context;
struct vrend_resource;
struct vrend_transfer_info;

struct virgl_sub_upload_data {
    struct vrend_transfer_info_box *box;
    GLenum target;
};

enum pipe_format {
    VIRGL_FORMAT_Z24X8_UNORM
};

enum {
   VREND_RESOURCE_STORAGE_GUEST,
   VREND_RESOURCE_STORAGE_GUEST_ELSE_SYSTEM,
   VREND_RESOURCE_STORAGE_BUFFER
};

struct vrend_transfer_info_box {
   int x;
   int y;
   int z;
   int width;
   int height;
   int depth;
};

struct vrend_transfer_info {
   uint32_t offset;
   uint32_t stride;
   uint32_t layer_stride;
   int level;
   bool synchronized;
   struct vrend_transfer_info_box *box;
};

struct vrend_resource {
   int storage;
   struct iovec *iov;
   int num_iovs;
   void *ptr;
   GLuint id;
   GLenum target;
   struct {
      enum pipe_format format;
      uint32_t width0;
      uint32_t height0;
   } base;
   bool y_0_top;
   GLuint readback_fb_id;
   int readback_fb_level;
   int64_t mipmap_offsets[VR_MAX_TEXTURE_2D_LEVELS];
};

struct vrend_state {
   bool use_core_profile;
   bool use_gles;
};

struct tex_conv_entry {
   GLenum glformat;
   GLenum internalformat;
   GLenum gltype;
};

extern struct tex_conv_entry tex_conv_table[];
extern struct vrend_state vrend_state;

void iov_buffer_upload(void *data, uint32_t offset, void *arg);

int vrend_copy_iovec(struct iovec *dst_iov, int dst_num_iovs, uint32_t dst_offset,
                     struct iovec *src_iov, int src_num_iovs, uint32_t src_x,
                     uint32_t width, void *ptr);
void vrend_read_from_iovec(struct iovec *iov, int num_iovs, uint32_t offset,
                           void *data, uint32_t size);
void vrend_read_from_iovec_cb(struct iovec *iov, int num_iovs, uint32_t offset,
                              uint32_t size, void (*cb)(void *, uint32_t, void *),
                              void *arg);
void vrend_use_program(struct vrend_context *ctx, GLuint program);
void vrend_depth_test_enable(struct vrend_context *ctx, bool enable);
void vrend_alpha_test_enable(struct vrend_context *ctx, bool enable);
void vrend_stencil_test_enable(struct vrend_context *ctx, bool enable);
void vrend_fb_bind_texture(struct vrend_resource *res, int unit, int level, int layer);
void vrend_scale_depth(void *data, uint32_t size, float scale);
void report_gles_missing_func(struct vrend_context *ctx, const char *func);
void vrend_printf(const char *format, ...);
int read_transfer_data(struct iovec *iov, int num_iovs, void *data,
                       enum pipe_format format, uint32_t offset,
                       uint32_t stride, uint32_t layer_stride,
                       struct vrend_transfer_info_box *box, bool invert);
int util_format_get_blocksize(enum pipe_format format);
int util_format_get_nblocksx(enum pipe_format format, int width);
int util_format_get_2d_size(enum pipe_format format, int stride, int height);
bool util_format_is_compressed(enum pipe_format format);
int util_format_get_nblocks(enum pipe_format format, int width, int height);
int u_minify(int value, int level);

void glBindBufferARB(GLenum target, GLuint buffer);
void* glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLboolean glUnmapBuffer(GLenum target);
void glUseProgram(GLuint program);
void glPixelStorei(GLenum pname, GLint param);
void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers);
void glGenFramebuffers(GLsizei n, GLuint *framebuffers);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glDrawBuffers(GLsizei n, const GLenum *bufs);
void glDisable(GLenum cap);
void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
void glWindowPos2i(GLint x, GLint y);
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void glBindTexture(GLenum target, GLuint texture);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void glPixelTransferf(GLenum pname, GLfloat param);