#include <stdlib.h>
#include <stdint.h>

typedef struct RzBuffer RzBuffer;
typedef uint64_t ut64;
typedef int64_t st64;
typedef uint8_t ut8;

typedef struct {
    ut64 size;
    ut64 offset;
    char *data;
} DexString;

#define RZ_NEW0(x) calloc(1, sizeof(x))