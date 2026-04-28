#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef int8_t s8;
typedef uint8_t u8;

#define BZIP3_API
#define BZ3_ERR_MALFORMED_HEADER 1
#define BZ3_ERR_CRC 2
#define BZ3_ERR_BWT 3
#define BZ3_OK 0

struct cm_state {
    u8 *in_queue;
    s32 input_ptr;
    s32 input_max;
};

struct bz3_state {
    s32 block_size;
    s32 last_error;
    u8 *swap_buffer;
    struct cm_state *cm_state;
    s32 *sais_array;
    u32 *lzp_lut;
};

static inline s32 read_neutral_s32(const u8 *buffer) {
    return (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
}

static inline u32 crc32sum(int unused, const u8 *data, s32 len) {
    (void)unused;
    (void)data;
    (void)len;
    return 0;
}

static inline s32 bz3_bound(s32 size) {
    return size;
}

static inline void begin(struct cm_state *cm_state) {
    (void)cm_state;
}

static inline void decode_bytes(struct cm_state *cm_state, u8 *buffer, s32 size) {
    (void)cm_state;
    (void)buffer;
    (void)size;
}

static inline void swap(u8 **a, u8 **b) {
    u8 *tmp = *a;
    *a = *b;
    *b = tmp;
}

static inline int libsais_unbwt(const u8 *src, u8 *dst, s32 *sais_array, s32 size, void *unused, s32 bwt_idx) {
    (void)src;
    (void)dst;
    (void)sais_array;
    (void)size;
    (void)unused;
    (void)bwt_idx;
    return 0;
}

static inline s32 lzp_decompress(const u8 *src, u8 *dst, s32 src_size, s32 dst_size, u32 *lzp_lut) {
    (void)src;
    (void)dst;
    (void)src_size;
    (void)dst_size;
    (void)lzp_lut;
    return 0;
}

static inline int mrled(const u8 *src, u8 *dst, s32 orig_size, ...) {
    (void)src;
    (void)dst;
    (void)orig_size;
    return 0;
}