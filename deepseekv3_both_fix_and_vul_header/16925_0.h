#include <stdint.h>
#include <stdio.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

#define READ16(p) (*(p) | (*((p)+1) << 8))
#define READ32(p) (*(p) | (*((p)+1) << 8) | (*((p)+2) << 16) | (*((p)+3) << 24))
#define READ64(p) ((uint64_t)READ32(p) | ((uint64_t)READ32((p)+4) << 32))

#define eprintf(...) fprintf(stderr, __VA_ARGS__)