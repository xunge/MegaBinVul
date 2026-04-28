#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef uint32_t TSS2_RC;

static inline void clearbuf(char *buf) {
    memset(buf, 0, 32);
}

static inline void catbuf(char *buf, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, 32, fmt, args);
    va_end(args);
}

static inline uint32_t tpm2_error_get(TSS2_RC rc) {
    return rc;
}