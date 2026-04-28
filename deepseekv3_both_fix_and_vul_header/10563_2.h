#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef unsigned int uint;

typedef struct gs_memory_s gs_memory_t;
typedef struct gx_io_device_s gx_io_device;
typedef struct gs_main_instance_s {
    bool search_here_first;
} gs_main_instance;
typedef struct i_ctx_s {
    bool starting_arg_file;
} i_ctx_t;
typedef struct ref_s ref;
typedef struct gs_file_path_s gs_file_path;
typedef gs_file_path *gs_file_path_ptr;

#define gs_error_undefinedfilename 1

extern gx_io_device *iodev_default(const gs_memory_t *mem);
extern gs_main_instance *get_minst_from_memory(const gs_memory_t *mem);
extern bool gp_file_name_is_absolute(const char *fname, uint flen);
extern int lib_file_open_search_with_no_combine(gs_file_path_ptr lib_path, const gs_memory_t *mem, i_ctx_t *i_ctx_p, const char *fname, uint flen, char *buffer, int blen, uint *pclen, ref *pfile, gx_io_device *iodev, bool starting_arg_file, char fmode[2]);
extern int lib_file_open_search_with_combine(gs_file_path_ptr lib_path, const gs_memory_t *mem, i_ctx_t *i_ctx_p, const char *fname, uint flen, char *buffer, int blen, uint *pclen, ref *pfile, gx_io_device *iodev, bool starting_arg_file, char fmode[2]);
extern int return_error(int code);

extern gx_io_device *gx_io_device_table[];