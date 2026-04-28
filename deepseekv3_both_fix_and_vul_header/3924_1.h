#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef struct gs_memory_s gs_memory_t;
typedef struct gs_lib_ctx_core_s gs_lib_ctx_core_t;

typedef enum {
    gs_permit_file_reading,
    gs_permit_file_writing,
    gs_permit_file_control
} gs_path_control_t;

typedef struct {
    char *path;
    int flags;
} gs_path_control_entry_t;

typedef struct {
    gs_path_control_entry_t *entry;
    unsigned int num;
} gs_path_control_set_t;

typedef enum {
    gs_error_unknownerror,
    gs_error_rangecheck,
    gs_error_VMerror,
    gs_error_invalidfileaccess
} gs_error_code_t;

typedef enum {
    gp_combine_success
} gp_combine_code_t;

extern gp_combine_code_t gp_file_name_reduce(const char *path, uint32_t len, char *buffer, uint32_t *rlen);
extern void *gs_alloc_bytes(gs_memory_t *mem, uint32_t size, const char *cname);
extern void gs_free_object(gs_memory_t *mem, void *ptr, const char *cname);

struct gs_lib_ctx_core_s {
    gs_memory_t *memory;
    gs_path_control_set_t permit_reading;
    gs_path_control_set_t permit_writing;
    gs_path_control_set_t permit_control;
};

struct gs_memory_s {
    struct gs_lib_ctx_s *gs_lib_ctx;
};

struct gs_lib_ctx_s {
    gs_lib_ctx_core_t *core;
};

typedef uint32_t uint;