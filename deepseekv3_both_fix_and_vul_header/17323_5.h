#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef unsigned int mz_uint;
typedef uint8_t mz_uint8;
typedef uint32_t mz_uint32;
typedef int16_t mz_int16;

typedef enum {
    TINFL_STATUS_FAILED = -3,
    TINFL_STATUS_BAD_PARAM = -2,
    TINFL_STATUS_ADLER32_MISMATCH = -1,
    TINFL_STATUS_DONE = 0,
    TINFL_STATUS_NEEDS_MORE_INPUT = 1,
    TINFL_STATUS_HAS_MORE_OUTPUT = 2
} tinfl_status;

#define TINFL_FLAG_PARSE_ZLIB_HEADER 1
#define TINFL_FLAG_HAS_MORE_INPUT 2
#define TINFL_FLAG_USING_NON_WRAPPING_OUTPUT_BUF 4
#define TINFL_FLAG_COMPUTE_ADLER32 8

#define TINFL_FAST_LOOKUP_BITS 10
#define TINFL_FAST_LOOKUP_SIZE (1 << TINFL_FAST_LOOKUP_BITS)

typedef uint32_t tinfl_bit_buf_t;

typedef struct {
    mz_uint8 m_code_size[TINFL_FAST_LOOKUP_SIZE];
    mz_int16 m_look_up[TINFL_FAST_LOOKUP_SIZE];
    mz_int16 m_tree[2 * TINFL_FAST_LOOKUP_SIZE];
} tinfl_huff_table;

typedef struct {
    tinfl_bit_buf_t m_bit_buf;
    mz_uint m_num_bits;
    mz_uint m_dist;
    mz_uint m_counter;
    mz_uint m_num_extra;
    mz_uint m_dist_from_out_buf_start;
    mz_uint8 m_raw_header[4];
    mz_uint m_table_sizes[3];
    tinfl_huff_table m_tables[3];
    mz_uint8 m_len_codes[288 + 32];
    mz_uint m_final;
    mz_uint m_type;
    mz_uint m_check_adler32;
    mz_uint m_z_adler32;
    mz_uint m_zhdr0;
    mz_uint m_zhdr1;
    mz_uint m_state;
} tinfl_decompressor;

#define MZ_MIN(a, b) ((a) < (b) ? (a) : (b))
#define MZ_MAX(a, b) ((a) > (b) ? (a) : (b))
#define MZ_CLEAR_OBJ(obj) memset(&(obj), 0, sizeof(obj))
#define MZ_READ_LE16(p) ((mz_uint32)(((const mz_uint8 *)(p))[0]) | ((mz_uint32)(((const mz_uint8 *)(p))[1]) << 8))
#define MZ_READ_LE32(p) ((mz_uint32)(((const mz_uint8 *)(p))[0]) | ((mz_uint32)(((const mz_uint8 *)(p))[1]) << 8) | ((mz_uint32)(((const mz_uint8 *)(p))[2]) << 16) | ((mz_uint32)(((const mz_uint8 *)(p))[3]) << 24))
#define TINFL_MEMCPY(d, s, l) memcpy(d, s, l)
#define TINFL_MEMSET(p, c, l) memset(p, c, l)
#define TINFL_CR_BEGIN switch(r->m_state) { case 0:
#define TINFL_CR_RETURN(state, result) do { r->m_state = state; return result; } while (0)
#define TINFL_CR_RETURN_FOREVER(state, result) do { r->m_state = state; goto common_exit; } while (0)
#define TINFL_CR_FINISH }
#define TINFL_GET_BYTE(state, c) do { \
    if (pIn_buf_cur >= pIn_buf_end) { \
        if (decomp_flags & TINFL_FLAG_HAS_MORE_INPUT) { \
            TINFL_CR_RETURN(state, TINFL_STATUS_NEEDS_MORE_INPUT); \
        } else { \
            c = 0; \
        } \
    } else c = *pIn_buf_cur++; } while (0)
#define TINFL_GET_BITS(state, b, n) do { \
    mz_uint bits; \
    while (num_bits < (n)) { \
        if (pIn_buf_cur >= pIn_buf_end) { \
            if (decomp_flags & TINFL_FLAG_HAS_MORE_INPUT) { \
                TINFL_CR_RETURN(state, TINFL_STATUS_NEEDS_MORE_INPUT); \
            } else { \
                bits = 0; \
                break; \
            } \
        } \
        bits |= ((mz_uint)*pIn_buf_cur++) << num_bits; \
        num_bits += 8; \
    } \
    b = bits & ((1 << (n)) - 1); \
    bits >>= (n); \
    num_bits -= (n); \
} while (0)
#define TINFL_SKIP_BITS(state, n) do { \
    while (num_bits < (n)) { \
        if (pIn_buf_cur >= pIn_buf_end) { \
            if (decomp_flags & TINFL_FLAG_HAS_MORE_INPUT) { \
                TINFL_CR_RETURN(state, TINFL_STATUS_NEEDS_MORE_INPUT); \
            } else { \
                TINFL_CR_RETURN(state, TINFL_STATUS_FAILED); \
            } \
        } \
        num_bits += 8; \
        pIn_buf_cur++; \
    } \
    num_bits -= (n); \
} while (0)
#define TINFL_HUFF_DECODE(state, sym, pHuff) do { \
    int temp; \
    if (num_bits < 15) { \
        if ((pIn_buf_cur + 2) > pIn_buf_end) { \
            if (decomp_flags & TINFL_FLAG_HAS_MORE_INPUT) { \
                TINFL_CR_RETURN(state, TINFL_STATUS_NEEDS_MORE_INPUT); \
            } else { \
                TINFL_CR_RETURN(state, TINFL_STATUS_FAILED); \
            } \
        } \
        bit_buf |= (((tinfl_bit_buf_t)MZ_READ_LE16(pIn_buf_cur)) << num_bits); \
        pIn_buf_cur += 2; \
        num_bits += 16; \
    } \
    if ((temp = (pHuff)->m_look_up[bit_buf & (TINFL_FAST_LOOKUP_SIZE - 1)]) >= 0) { \
        sym = temp >> 9; \
        num_bits -= temp & 511; \
    } else { \
        int code_len = TINFL_FAST_LOOKUP_BITS; \
        do { \
            temp = (pHuff)->m_tree[~temp + ((bit_buf >> code_len++) & 1)]; \
        } while (temp < 0); \
        sym = temp; \
        num_bits -= code_len; \
    } \
    bit_buf >>= (num_bits & 31); \
} while (0)