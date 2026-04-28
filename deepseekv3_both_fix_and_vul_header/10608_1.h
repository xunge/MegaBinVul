#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t strs[3];
    uint8_t* arena;
} grpc_error;

typedef struct {
    size_t refcount;
    uint8_t* data;
    size_t length;
} grpc_slice;

typedef enum {
    GRPC_ERROR_STR_DESCRIPTION,
    GRPC_ERROR_STR_FILE,
    GRPC_ERROR_STR_LINE,
    GRPC_ERROR_STR_COUNT
} grpc_error_strs;

extern const char* error_str_name(grpc_error_strs which);
extern uint8_t get_placement(grpc_error** err, size_t size);
extern void unref_slice(grpc_slice slice);
extern char* grpc_slice_to_c_string(grpc_slice value);
extern void gpr_free(void* p);
extern void gpr_log(int severity, const char* format, ...);
#define GPR_ERROR 1