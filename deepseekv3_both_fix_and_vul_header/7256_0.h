#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint32_t version;
    uint32_t cflags;
    uint32_t cpu;
    uint32_t fpu;
    uint32_t code_index;
    uint32_t stack_index;
    uint32_t heap_index;
    uint32_t argv_index;
    uint32_t code_offset;
    uint32_t stack_nbytes;
    uint32_t heap_nbytes;
    uint32_t image_base;
} lmf_header;

#define QNX_HEADER_ADDR 0
#define QNX_HDR_SIZE sizeof(lmf_header)

typedef struct RBuffer RBuffer;
typedef struct Sdb Sdb;

typedef uint8_t ut8;