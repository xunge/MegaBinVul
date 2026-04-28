#include <stdint.h>

#define INLINE inline

typedef uint32_t UWORD32;

typedef struct {
    UWORD32 u4_offset;
    UWORD32 u4_max_offset;
    UWORD32 u4_buf;
    UWORD32 u4_buf_nxt;
    UWORD32 *pu4_buf_aligned;
} stream_t;

#define FLUSH_BITS(offset, buf, buf_nxt, no_of_bits, buf_aligned) \
    do { \
        (void)(offset); \
        (void)(buf); \
        (void)(buf_nxt); \
        (void)(no_of_bits); \
        (void)(buf_aligned); \
    } while(0);