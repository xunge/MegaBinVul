#include <string.h>
#include <errno.h>
#include <stdint.h>

typedef uint32_t uint;

typedef struct core_s {
    int path_control_active;
} core_t;

typedef struct gs_lib_ctx_s {
    core_t *core;
} gs_lib_ctx_t;

typedef struct gs_memory_s {
    void *thread_safe_memory;
    gs_lib_ctx_t *gs_lib_ctx;
} gs_memory_t;

enum {
    gs_error_VMerror,
    gs_error_invalidfileaccess
};

enum {
    gs_permit_file_reading,
    gs_permit_file_writing,
    gs_permit_file_control,
    gs_path_control_flag_is_scratch_file
};

typedef enum {
    gp_combine_success
} gp_combine_result;

extern const char *gp_file_name_current(void);
extern const char *gp_file_name_separator(void);
extern int gp_file_name_is_absolute(const char *path, uint len);
extern gp_combine_result gp_file_name_reduce(const char *path, uint len, char *buffer, uint *rlen);
extern int validate(const gs_memory_t *mem, const char *buffer, int permit);
extern void errprintf(const gs_memory_t *mem, const char *format, ...);
extern int gs_note_error(int code);
extern int gs_remove_control_path_flags(const gs_memory_t *mem, int permit, const char *buffer, int flags);
extern void *gs_alloc_bytes(void *mem, size_t size, const char *cname);
extern void gs_free_object(void *mem, void *ptr, const char *cname);