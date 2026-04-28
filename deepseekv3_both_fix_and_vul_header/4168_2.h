#include <stdint.h>

typedef struct {
    uint32_t u4_offset;
    uint32_t u4_max_offset;
    uint32_t u4_buf;
    uint32_t u4_buf_nxt;
    uint32_t* pu4_buf_aligned;
} stream_t;

#define FLUSH_BITS(offset, buf, buf_nxt, no_of_bits, buf_aligned) \
    do { \
        uint32_t tmp = (no_of_bits); \
        (offset) += tmp; \
        (buf) = (buf_nxt); \
        if ((offset) >= 32) { \
            (buf_aligned)++; \
            (buf_nxt) = *(buf_aligned); \
            (offset) -= 32; \
            (buf) = (buf_nxt) >> (offset); \
        } \
    } while (0);  // 注意这里添加了分号

typedef uint32_t UWORD32;
#define INLINE static inline