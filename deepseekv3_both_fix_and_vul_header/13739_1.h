#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;

typedef struct sc_context {
    // dummy context structure
} sc_context;

typedef struct cac_private_data_t {
    unsigned char *cache_buf;
    size_t cache_buf_len;
    int cached;
} cac_private_data_t;

typedef struct sc_card_t {
    sc_context *ctx;
    void *drv_data;
} sc_card_t;

#define CAC_DATA(card) ((cac_private_data_t *)(card)->drv_data)
#define SC_FORMAT_LEN_SIZE_T "z"
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SC_ERROR_FILE_END_REACHED 1
#define SC_ERROR_INVALID_DATA 2
#define SC_ERROR_NOT_SUPPORTED 3
#define SC_ERROR_OUT_OF_MEMORY 4
#define SC_LOG_DEBUG_VERBOSE 0
#define LOG_FUNC_RETURN(ctx, r) return (r)
#define SC_FUNC_CALLED(ctx, level)

void sc_log(sc_context *ctx, const char *format, ...);
int cac_cac1_get_certificate(sc_card_t *card, u8 **val, size_t *val_len);