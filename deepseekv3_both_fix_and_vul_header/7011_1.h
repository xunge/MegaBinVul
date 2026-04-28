#include <stdint.h>
#include <string.h>

#define TSS2_ERR_LAYER_NAME_MAX 32
#define TSS2_ERR_LAYER_ERROR_STR_MAX 128

typedef uint32_t TSS2_RC;
typedef uint8_t UINT8;
typedef uint16_t UINT16;

typedef const char* (*TSS2_RC_HANDLER)(UINT16);

struct {
    TSS2_RC_HANDLER handler;
    const char *name;
} layer_handler[256];

static void clearbuf(char *buf) {
    memset(buf, 0, TSS2_ERR_LAYER_NAME_MAX + TSS2_ERR_LAYER_ERROR_STR_MAX + 1);
}

static void catbuf(char *buf, const char *fmt, ...) {
}

static UINT8 tss2_rc_layer_number_get(TSS2_RC rc) {
    return (rc >> 24) & 0xFF;
}

static UINT16 tpm2_error_get(TSS2_RC rc) {
    return rc & 0xFFFF;
}

static const char *unknown_layer_handler(UINT16 err_bits) {
    return NULL;
}