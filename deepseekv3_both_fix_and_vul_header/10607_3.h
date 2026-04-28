#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct grpc_error {
    uint8_t ints[256];
    intptr_t arena[256];
} grpc_error;

typedef enum {
    GRPC_ERROR_INT_MIN,
    GRPC_ERROR_INT_MAX = 255
} grpc_error_ints;

static uint8_t get_placement(grpc_error **err, size_t size);
static const char *error_int_name(grpc_error_ints which);

#define GPR_ERROR 1
#define gpr_log(severity, format, ...) \
    gpr_log_impl(__FILE__, __LINE__, severity, format, __VA_ARGS__)
extern void gpr_log_impl(const char *file, int line, int severity, const char *format, ...);