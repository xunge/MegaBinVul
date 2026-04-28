#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct stream stream;
typedef struct gx_io_device gx_io_device;
typedef struct i_ctx_s i_ctx_t;
typedef struct gs_memory_s gs_memory_t;

typedef struct ref_s {
    struct {
        const uint8_t *const_bytes;
    } value;
} ref;

typedef ref *os_ptr;
extern os_ptr osp;

struct gx_io_device_procs {
    int (*delete_file)(gx_io_device *, const char *);
};

struct gx_io_device {
    struct gx_io_device_procs procs;
};

#define r_has_type(op, type) (0)
#define r_size(op) (0)
#define check_read_type(op, type) 
#define check_file_permissions(ctx, str, len, ptr, str2) (0)
#define prefix_is_simple(str) (0)
#define file_alloc_stream(mem, str) (NULL)
#define file_default_buffer_size (0)
#define file_init_stream(s, file, mode, buf, size) 
#define ssetfilename(s, name, len) (0)
#define sclose(s) 
#define ifree_string(ptr, len, str) 
#define make_string(op, flags, len, ptr) 
#define make_stream_file(op, s, mode) 
#define ialloc_string(len, str) (NULL)
#define gp_file_name_sizeof (0)
#define gp_fmode_binary_suffix ""
#define gp_scratch_file_name_prefix ""
#define gp_file_name_is_absolute(str, len) (0)
#define gp_open_scratch_file(mem, prefix, fname, mode) (NULL)
#define gs_alloc_bytes(mem, size, str) (NULL)
#define gs_free_object(mem, ptr, str) 
#define gs_note_error(code) (code)
#define imemory (NULL)
#define icurrent_space (0)
#define a_readonly (0)
#define t_null (0)
#define t_string (0)
#define gs_error_VMerror (0)
#define gs_error_rangecheck (0)
#define gs_error_invalidfileaccess (0)

typedef uint8_t byte;
typedef unsigned int uint;

static int parse_file_access_string(ref *op, char *fmode);
static gx_io_device *iodev_default(gs_memory_t *mem);