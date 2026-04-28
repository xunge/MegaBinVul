#include <stdint.h>

#define BITS_IN_INT 32
#define INLINE static inline

typedef uint8_t UWORD8;
typedef uint32_t UWORD32;

typedef struct {
    UWORD32 u4_offset;
    UWORD32 u4_buf;
    UWORD32 u4_buf_nxt;
    UWORD32 u4_max_offset;
    UWORD32 *pu4_buf_aligned;
} stream_t;

#define CONV_LE_TO_BE(dest, src) \
    do { \
        UWORD32 __tmp = (src); \
        (dest) = ((__tmp >> 24) & 0xFF) | ((__tmp >> 8) & 0xFF00) | \
                ((__tmp << 8) & 0xFF0000) | ((__tmp << 24) & 0xFF000000); \
    } while (0);