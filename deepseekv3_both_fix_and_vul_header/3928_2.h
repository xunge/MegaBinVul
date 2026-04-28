#include <stddef.h>
#include <string.h>

typedef struct gs_path_control_entry {
    char *path;
    int flags;
} gs_path_control_entry_t;

typedef struct gs_path_control_set {
    gs_path_control_entry_t *entry;
    unsigned int num;
    unsigned int max;
} gs_path_control_set_t;

typedef struct gs_lib_ctx_core {
    struct gs_memory_s *memory;
    gs_path_control_set_t permit_reading;
    gs_path_control_set_t permit_writing;
    gs_path_control_set_t permit_control;
} gs_lib_ctx_core_t;

typedef struct gs_lib_ctx {
    gs_lib_ctx_core_t *core;
} gs_lib_ctx_t;

typedef struct gs_memory_s {
    gs_lib_ctx_t *gs_lib_ctx;
} gs_memory_t;

typedef enum {
    gs_permit_file_reading,
    gs_permit_file_writing,
    gs_permit_file_control
} gs_path_control_t;

typedef enum {
    gs_error_unknownerror,
    gs_error_rangecheck,
    gs_error_VMerror,
    gs_error_invalidfileaccess
} gs_error_code_t;

typedef enum {
    gp_combine_success
} gp_combine_status_t;

typedef unsigned int uint;

extern int gp_file_name_reduce(const char *path, uint len, char *buffer, uint *rlen);
extern void *gs_alloc_bytes(gs_memory_t *mem, size_t size, const char *cname);
extern void *gs_resize_object(gs_memory_t *mem, void *obj, size_t size, const char *cname);
extern void gs_free_object(gs_memory_t *mem, void *obj, const char *cname);