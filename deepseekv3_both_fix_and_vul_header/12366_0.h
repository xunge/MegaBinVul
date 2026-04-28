#include <stdint.h>
#include <stddef.h>

typedef uint32_t ut32;
typedef uint8_t ut8;
#define UT32_MAX UINT32_MAX

static inline ut32 r_read_le32(const void *src);