#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct RBuffer RBuffer;

typedef uint64_t ut64;
typedef uint32_t ut32;

#define WASM_IS_OK(orig, i, len) ((i) < (len) && (orig)[i] >= 0x20 && (orig)[i] <= 0x7e)

static bool consume_str_new(RBuffer *b, ut64 bound, ut32 *len_out, char **str_out);