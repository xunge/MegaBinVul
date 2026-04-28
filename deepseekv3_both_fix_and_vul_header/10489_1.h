#include <stdint.h>
#include <string.h>

typedef int32_t WORD32;
typedef uint8_t UWORD8;
typedef uint32_t UWORD32;

typedef enum {
    IHEVCD_SUCCESS,
    IHEVCD_FAIL
} IHEVCD_ERROR_T;

#define IHEVC_CAB_CTXT_END 1024

typedef struct {
    UWORD32 u4_range;
    UWORD32 u4_ofst;
    UWORD8 au1_ctxt_models[IHEVC_CAB_CTXT_END];
} cab_ctxt_t;

typedef struct {
    UWORD32 *pu4_buf;
    UWORD32 u4_bit_ofst;
    UWORD32 u4_cur_word;
    UWORD32 u4_nxt_word;
} bitstrm_t;

#define ASSERT(cond) ((void)0)
#define UNUSED(x) ((void)(x))
#define FULLRANGE 0
#define RANGE_SHIFT 0
#define DEBUG_RANGE_OFST(str, range, ofst) ((void)0)

#define BITS_GET(dst, buf, bit_ofst, cur_word, nxt_word, num_bits) \
    do { \
        /* implementation */ \
    } while(0)