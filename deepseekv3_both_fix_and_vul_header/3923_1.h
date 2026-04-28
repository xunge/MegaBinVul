#include <string.h>
#include <errno.h>
#include <stdint.h>

typedef uint32_t uint;

typedef struct gs_memory_s gs_memory_t;
typedef struct gs_lib_ctx_s gs_lib_ctx_t;
typedef struct gs_lib_ctx_core_s gs_lib_ctx_core_t;

struct gs_memory_s {
    gs_lib_ctx_t *gs_lib_ctx;
    gs_memory_t *thread_safe_memory;
};

struct gs_lib_ctx_s {
    gs_lib_ctx_core_t *core;
};

struct gs_lib_ctx_core_s {
    int path_control_active;
};

enum {
    gp_combine_success,
    gs_error_VMerror,
    gs_error_invalidfileaccess,
    gs_path_control_flag_is_scratch_file
};

enum {
    gs_permit_file_reading,
    gs_permit_file_writing,
    gs_permit_file_control
};

extern const char *gp_file_name_current(void);
extern const char *gp_file_name_separator(void);
extern int gp_file_name_is_absolute(const char *path, uint len);
extern int gp_file_name_reduce(const char *path, uint len, char *buffer, uint *rlen);
extern int validate(const gs_memory_t *mem, const char *buffer, int permit);
extern void errprintf(const gs_memory_t *mem, const char *fmt, ...);
extern int gs_note_error(int code);
extern int gs_remove_control_path_flags(const gs_memory_t *mem, int permit, const char *buffer, int flags);
extern void *gs_alloc_bytes(gs_memory_t *mem, uint size, const char *cname);
extern void gs_free_object(gs_memory_t *mem, void *ptr, const char *cname);