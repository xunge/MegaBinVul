#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ATTRIBUTE_MALLOC
#define DBG_MAX_COUNT (1ULL << 30)
#define DWG_ERR_CRITICAL (1)
#define PRId64 "lld"

typedef unsigned char BITCODE_RC;

typedef struct {
    size_t size;
    size_t byte;
} Bit_Chain;

#define LOG_ERROR(fmt, ...)
#define LOG_HANDLE(fmt, ...)

static inline void bit_read_fixed(Bit_Chain *dat, BITCODE_RC *data, int64_t size) {}
static inline BITCODE_RC *decode_rs(BITCODE_RC *rsdata, int64_t block_count, int k, int64_t page_size) { return NULL; }
static inline int decompress_r2007(BITCODE_RC *out, int64_t out_size, BITCODE_RC *in, int64_t in_size) { return 0; }
#define MIN(a, b) ((a) < (b) ? (a) : (b))