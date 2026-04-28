#include <stdlib.h>
#include <stddef.h>

typedef unsigned int mz_uint8;
typedef unsigned int mz_uint32;

typedef enum {
  TINFL_STATUS_DONE = 0,
  TINFL_STATUS_NEEDS_MORE_INPUT = -4
} tinfl_status;

typedef struct {
  mz_uint32 m_state;
} tinfl_decompressor;

#define TINFL_FLAG_HAS_MORE_INPUT (1)
#define TINFL_FLAG_USING_NON_WRAPPING_OUTPUT_BUF (2)

#define MZ_FREE free
#define MZ_REALLOC realloc

static void tinfl_init(tinfl_decompressor *decomp) {
  decomp->m_state = 0;
}

static tinfl_status tinfl_decompress(tinfl_decompressor *decomp,
                                    const mz_uint8 *pSrc_buf,
                                    size_t *pSrc_buf_len,
                                    mz_uint8 *pOut_buf,
                                    mz_uint8 *pOut_buf_next,
                                    size_t *pOut_buf_size,
                                    int flags) {
  return TINFL_STATUS_DONE;
}