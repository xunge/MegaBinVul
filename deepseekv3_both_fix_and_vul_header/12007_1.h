#include <string.h>

typedef struct gx_device_s gx_device;
typedef struct gs_memory_s {
    struct {
        struct {
            struct {
                int path_control_active;
            } *core;
        } *gs_lib_ctx;
    };
} gs_memory;

typedef struct gx_device_ijs_s {
    gs_memory *memory;
    char *ColorSpace;
    size_t ColorSpace_size;
} gx_device_ijs;

enum {
    gs_error_invalidaccess,
    gs_error_VMerror
};

static inline int return_error(int error) { return error; }
static inline int gs_note_error(int error) { return error; }
void *gs_malloc(gs_memory *mem, size_t size, size_t num, const char *cname);