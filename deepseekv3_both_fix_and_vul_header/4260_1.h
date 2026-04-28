#include <stdint.h>
#include <string.h>

typedef int32_t WORD32;
typedef uint32_t UWORD32;
typedef int16_t WORD16;
typedef uint16_t UWORD16;
typedef uint8_t UWORD8;

typedef struct {
    UWORD32 *pu4_buffer;
    UWORD32 u4_ofst;
    void *pv_codec_handle;
} dec_bit_stream_t;

typedef struct {
    UWORD16 u2_sig_coeff_map;
    WORD16 ai2_level[16];
} tu_sblk4x4_coeff_data_t;

typedef struct {
    void *pv_parse_tu_coeff_data;
} dec_struct_t;

extern WORD16 gai2_ih264d_trailing_one_level[][3];
extern UWORD8 gau1_ih264d_table_total_zero_11to15[][16];
extern UWORD8 gau1_ih264d_table_run_before[];

#define GETBITS(var, offset, buf, numbits) \
    do { \
        var = (*(buf + (offset >> 5)) >> (offset & 0x1F)); \
        if(((offset & 0x1F) + numbits) > 32) \
            var |= (*(buf + (offset >> 5) + 1) << (32 - (offset & 0x1F))); \
        var &= ((1 << numbits) - 1); \
        offset += numbits; \
    } while(0)

#define NEXTBITS(var, offset, buf, numbits) \
    do { \
        var = (*(buf + (offset >> 5)) >> (offset & 0x1F)); \
        if(((offset & 0x1F) + numbits) > 32) \
            var |= (*(buf + (offset >> 5) + 1) << (32 - (offset & 0x1F))); \
        var &= ((1 << numbits) - 1); \
    } while(0)

#define FLUSHBITS(offset, numbits) \
    do { \
        offset += numbits; \
    } while(0)

#define FIND_ONE_IN_STREAM_32(var, offset, buf) \
    do { \
        UWORD32 tmp = *(buf + (offset >> 5)) >> (offset & 0x1F); \
        if(tmp == 0) { \
            offset += 32 - (offset & 0x1F); \
            var = 31; \
            while(*(++buf + (offset >> 5)) == 0) { \
                offset += 32; \
                var += 32; \
            } \
            tmp = *(buf + (offset >> 5)); \
        } \
        var += __builtin_clz(tmp); \
        offset += var + 1; \
    } while(0)

#define SET_BIT(map, pos) \
    do { \
        map |= (1 << pos); \
    } while(0)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ALIGN4(x) (((x) + 3) & ~3)