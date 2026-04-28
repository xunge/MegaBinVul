#include <stdint.h>

typedef uint32_t UWORD32;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;
typedef int16_t WORD16;
typedef int32_t WORD32;

typedef struct dec_bit_stream_t {
    uint32_t *pu4_buffer;
    uint32_t u4_ofst;
    void *pv_codec_handle;
} dec_bit_stream_t;

typedef struct tu_sblk4x4_coeff_data_t {
    uint16_t u2_sig_coeff_map;
    int16_t ai2_level[16];
} tu_sblk4x4_coeff_data_t;

typedef struct dec_struct_t {
    void *pv_parse_tu_coeff_data;
} dec_struct_t;

extern WORD16 gai2_ih264d_trailing_one_level[][3];
extern UWORD8 gau1_ih264d_table_run_before[];

#define GETBITS(var, offset, buf, numbits) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        (var) = tmp & ((1 << (numbits)) - 1); \
        (offset) += (numbits); \
    } while(0)

#define NEXTBITS(var, offset, buf, numbits) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        (var) = tmp & ((1 << (numbits)) - 1); \
    } while(0)

#define FLUSHBITS(offset, numbits) \
    do { \
        (offset) += (numbits); \
    } while(0)

#define FIND_ONE_IN_STREAM_32(var, offset, buf) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        (var) = __builtin_clz(tmp); \
        (offset) += (var) + 1; \
    } while(0)

#define FIND_ONE_IN_STREAM_LEN(var, offset, buf, max_len) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        (var) = __builtin_clz(tmp); \
        if ((var) > (max_len)) (var) = (max_len); \
        (offset) += (var) + 1; \
    } while(0)

#define SET_BIT(map, pos) \
    do { \
        (map) |= (1 << (pos)); \
    } while(0)

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define ALIGN4(x) (((x) + 3) & ~3)