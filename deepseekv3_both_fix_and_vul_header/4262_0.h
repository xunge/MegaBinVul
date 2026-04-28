#include <stdint.h>
#include <stdlib.h>

typedef uint32_t UWORD32;
typedef int32_t WORD32;
typedef int16_t WORD16;
typedef uint8_t UWORD8;

typedef struct dec_bit_stream_t {
    uint32_t *pu4_buffer;
    uint32_t u4_ofst;
    void *pv_codec_handle;
} dec_bit_stream_t;

typedef struct dec_struct_t {
    void *pv_parse_tu_coeff_data;
} dec_struct_t;

typedef struct tu_sblk4x4_coeff_data_t {
    uint16_t u2_sig_coeff_map;
    int16_t ai2_level[16];
} tu_sblk4x4_coeff_data_t;

extern WORD16 gai2_ih264d_trailing_one_level[][3];
extern UWORD8 gau1_ih264d_table_total_zero_2to10[][64];
extern UWORD8 gau1_ih264d_table_run_before[];

#define GETBITS(bits, offset, buf, num_bits) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        bits = tmp & ((1 << num_bits) - 1); \
        offset += num_bits; \
    } while(0)

#define NEXTBITS(bits, offset, buf, num_bits) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        bits = tmp & ((1 << num_bits) - 1); \
    } while(0)

#define FLUSHBITS(offset, num_bits) \
    do { \
        offset += num_bits; \
    } while(0)

#define FIND_ONE_IN_STREAM_32(prefix, offset, buf) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        prefix = __builtin_clz(tmp); \
        offset += prefix + 1; \
    } while(0)

#define FIND_ONE_IN_STREAM_LEN(code, offset, buf, max_len) \
    do { \
        uint32_t tmp = *(buf + (offset >> 5)); \
        tmp >>= (offset & 0x1F); \
        code = __builtin_clz(tmp); \
        if (code > max_len) code = max_len; \
        offset += code + 1; \
    } while(0)

#define SET_BIT(map, pos) \
    do { \
        map |= (1 << pos); \
    } while(0)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ALIGN4(x) (((x) + 3) & ~3)