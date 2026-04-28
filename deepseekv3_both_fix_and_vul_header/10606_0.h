#include <stdint.h>
#include <stdlib.h>

typedef struct grpc_error {
  uint8_t arena_size;
  uint8_t arena_capacity;
} grpc_error;

#define GPR_ASSERT(expr) ((void)0)

void* gpr_realloc(void* p, size_t size);