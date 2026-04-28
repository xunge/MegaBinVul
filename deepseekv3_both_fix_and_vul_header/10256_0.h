#include <stdint.h>

typedef uint32_t UWORD32;
typedef int32_t WORD32;

typedef struct cab_ctxt_t cab_ctxt_t;
typedef struct bitstrm_t bitstrm_t;

#define ASSERT(cond) ((void)0)
#define CLIP3(x, min, max) (((x) < (min)) ? (min) : (((x) > (max)) ? (max) : (x)))

#define IHEVCD_CABAC_DECODE_BYPASS_BIN(bin, ps_cabac, ps_bitstrm) /* implementation dependent */
#define IHEVCD_CABAC_DECODE_BYPASS_BINS(u4_suffix, ps_cabac, ps_bitstrm, numones) /* implementation dependent */