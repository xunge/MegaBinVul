#include <stddef.h>
#include <stdlib.h>

typedef unsigned int mz_uint;
typedef unsigned char mz_uint8;

typedef int (*tinfl_put_buf_func_ptr)(const void *pBuf, int len, void *pUser);

typedef enum {
    TINFL_STATUS_FAILED = -3,
    TINFL_STATUS_BAD_PARAM = -2,
    TINFL_STATUS_ADLER32_MISMATCH = -1,
    TINFL_STATUS_DONE = 0,
    TINFL_STATUS_NEEDS_MORE_INPUT = 1,
    TINFL_STATUS_HAS_MORE_OUTPUT = 2
} tinfl_status;

#define TINFL_MAX_HUFF_SYMBOLS_0 288
#define TINFL_MAX_HUFF_SYMBOLS_1 32
#define TINFL_LZ_DICT_SIZE (32 * 1024)
#define TINFL_FLAG_HAS_MORE_INPUT 1
#define TINFL_FLAG_USING_NON_WRAPPING_OUTPUT_BUF 2

typedef struct {
    mz_uint m_state, m_num_bits, m_zhdr0, m_zhdr1, m_z_adler32, m_final, m_type, m_check_adler32, m_dist, m_counter, m_num_extra, m_table_sizes[3];
    mz_uint8 m_raw_header[4], m_len_codes[TINFL_MAX_HUFF_SYMBOLS_0 + TINFL_MAX_HUFF_SYMBOLS_1 + 137];
} tinfl_decompressor;

#define MZ_MALLOC malloc
#define MZ_FREE free

void tinfl_init(tinfl_decompressor *pDecomp);
tinfl_status tinfl_decompress(tinfl_decompressor *r, const mz_uint8 *pIn_buf_next, size_t *pIn_buf_size, mz_uint8 *pOut_buf_start, mz_uint8 *pOut_buf_next, size_t *pOut_buf_size, int flags);