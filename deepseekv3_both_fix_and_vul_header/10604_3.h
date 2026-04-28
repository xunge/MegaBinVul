#include <stdint.h>
#include <string.h>

typedef struct grpc_error grpc_error;
typedef enum { GRPC_ERROR_TIME_CREATED } grpc_error_times;
typedef struct { int64_t tv_sec; int32_t tv_nsec; } gpr_timespec;

struct grpc_error {
    uint8_t times[1];
    uint8_t* arena;
};

enum { GPR_ERROR };

static uint8_t get_placement(grpc_error **err, size_t size);
static const char *fmt_time(gpr_timespec value);
static const char *error_time_name(grpc_error_times which);
static void gpr_log(int severity, const char *format, ...);
static void gpr_free(void* ptr);