#include <stdbool.h>
#include <math.h>

#define PIPE_MAX_TEXTURE_TYPES 16
#define VIRGL_FORMAT_MAX 256
#define VIRGL_TEXTURE_CAN_TEXTURE_STORAGE 0x1
#define VIRGL_RESOURCE_Y_0_TOP 0x1
#define PIPE_BUFFER 0
#define PIPE_TEXTURE_RECT 1
#define PIPE_TEXTURE_1D 2
#define PIPE_TEXTURE_2D 3
#define PIPE_TEXTURE_3D 4
#define PIPE_TEXTURE_CUBE 5
#define PIPE_TEXTURE_1D_ARRAY 6
#define PIPE_TEXTURE_2D_ARRAY 7
#define PIPE_TEXTURE_CUBE_ARRAY 8

#define VIRGL_BIND_CUSTOM 0x1
#define VIRGL_BIND_STAGING 0x2
#define VIRGL_BIND_INDEX_BUFFER 0x4
#define VIRGL_BIND_STREAM_OUTPUT 0x8
#define VIRGL_BIND_VERTEX_BUFFER 0x10
#define VIRGL_BIND_CONSTANT_BUFFER 0x20
#define VIRGL_BIND_QUERY_BUFFER 0x40
#define VIRGL_BIND_COMMAND_ARGS 0x80
#define VIRGL_BIND_SHADER_BUFFER 0x100
#define VIRGL_BIND_SAMPLER_VIEW 0x200
#define VIRGL_BIND_DEPTH_STENCIL 0x400
#define VIRGL_BIND_RENDER_TARGET 0x800
#define VIRGL_BIND_CURSOR 0x1000
#define VIRGL_BIND_SHARED 0x2000
#define VIRGL_BIND_LINEAR 0x4000

struct vrend_renderer_resource_create_args {
   unsigned handle;
   unsigned target;
   unsigned format;
   unsigned nr_samples;
   unsigned last_level;
   unsigned width;
   unsigned height;
   unsigned depth;
   unsigned array_size;
   unsigned bind;
   unsigned flags;
};

struct vrend_state {
   unsigned max_texture_2d_size;
   unsigned max_texture_3d_size;
   unsigned max_texture_cube_size;
};

struct tex_conv_table_entry {
   unsigned flags;
};

extern struct vrend_state vrend_state;
extern struct tex_conv_table_entry tex_conv_table[];
extern bool has_feature(unsigned feat);

#define MAX2(a, b) ((a) > (b) ? (a) : (b))

enum {
   feat_texture_storage,
   feat_texture_multisample,
   feat_cube_map_array,
   feat_texture_array,
   feat_qbo,
   feat_indirect_draw
};