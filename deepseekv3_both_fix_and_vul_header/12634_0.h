#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ATTRIBUTE_MALLOC
#define BITCODE_RC unsigned char
#define DBG_MAX_COUNT UINT64_MAX
#define DWG_ERR_CRITICAL 1
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    size_t size;
    size_t byte;
} Bit_Chain;

void bit_read_fixed(Bit_Chain *dat, BITCODE_RC *data, int64_t size);
BITCODE_RC *decode_rs(BITCODE_RC *rsdata, int64_t block_count, int k, int64_t page_size);
int decompress_r2007(BITCODE_RC *out, int64_t out_size, BITCODE_RC *in, int64_t in_size);

#define LOG_ERROR(fmt, ...)
#define LOG_HANDLE(fmt, ...)