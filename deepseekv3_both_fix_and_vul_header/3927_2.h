#include <stddef.h>
#include <string.h>

typedef struct gs_memory_s gs_memory_t;
typedef struct gs_lib_ctx_s gs_lib_ctx_t;
typedef struct gs_lib_ctx_core_s gs_lib_ctx_core_t;
typedef struct gs_path_control_set_s gs_path_control_set_t;

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

struct gs_path_control_entry_s {
    char *path;
    int flags;
};

struct gs_path_control_set_s {
    unsigned int num;
    struct gs_path_control_entry_s *entry;
};

struct gs_lib_ctx_core_s {
    void *memory;
    struct gs_path_control_set_s permit_reading;
    struct gs_path_control_set_s permit_writing;
    struct gs_path_control_set_s permit_control;
};

struct gs_lib_ctx_s {
    struct gs_lib_ctx_core_s *core;
};

struct gs_memory_s {
    struct gs_lib_ctx_s *gs_lib_ctx;
};

extern void *gs_alloc_bytes(void *memory, size_t size, const char *cname);
extern void gs_free_object(void *memory, void *ptr, const char *cname);
extern gp_combine_status_t gp_file_name_reduce(const char *path, uint len, char *buffer, uint *rlen);