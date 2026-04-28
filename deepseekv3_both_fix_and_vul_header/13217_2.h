#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef int8_t s8;
typedef uint8_t u8;

struct cm_state {
    u8* in_queue;
    s32 input_ptr;
    s32 input_max;
};

struct bz3_state {
    s32 block_size;
    s32 last_error;
    u8 *swap_buffer;
    struct cm_state *cm_state;
    void *sais_array;
    void *lzp_lut;
};

enum {
    BZ3_OK,
    BZ3_ERR_MALFORMED_HEADER,
    BZ3_ERR_CRC,
    BZ3_ERR_BWT
};

#define BZ3_API
#define BZIP3_API BZ3_API
#define read_neutral_s32(ptr) (*(s32*)(ptr))
#define crc32sum(a, b, c) 0
#define bz3_bound(size) ((size) * 2)
#define begin(state)
#define decode_bytes(state, buf, size)
#define swap(a, b)
#define lzp_decompress(a, b, c, d, e) 0
#define mrled(a, b, c, d) 0
#define libsais_unbwt(a, b, c, d, e, f) 0