#include <stdint.h>
#include <string.h>

typedef struct grpc_error {
    uint8_t first_err;
    uint8_t last_err;
    char* arena;
} grpc_error;

typedef struct grpc_linked_error {
    grpc_error* error;
    uint8_t next;
} grpc_linked_error;

#define GPR_ERROR 1
#define GRPC_ERROR_UNREF(error)

void gpr_log(int severity, const char* format, ...);
void GPR_ASSERT(int condition);
char* grpc_error_string(grpc_error* error);
uint8_t get_placement(grpc_error** err, size_t size);