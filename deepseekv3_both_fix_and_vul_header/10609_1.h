#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <limits.h>

#define GRPC_ERROR_INT_MAX 16
#define GPR_ERROR 1

typedef struct grpc_error {
  uint8_t ints[GRPC_ERROR_INT_MAX];
  intptr_t *arena;
} grpc_error;

typedef enum grpc_error_ints {
  GRPC_ERROR_INT_MIN = 0,
  GRPC_ERROR_INT_MAX_VALUE = GRPC_ERROR_INT_MAX - 1
} grpc_error_ints;

extern uint8_t get_placement(grpc_error **err, size_t size);
extern const char* error_int_name(grpc_error_ints which);
extern void gpr_log(int severity, const char *format, ...);