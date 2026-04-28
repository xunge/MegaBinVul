#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _packet_info packet_info;
typedef struct _tvbuff tvbuff_t;
typedef struct _wmem_allocator_t wmem_allocator_t;
typedef struct _column_info column_info;

typedef unsigned int guint;
typedef int gint;
typedef unsigned char guchar;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef size_t LZ4F_errorCode_t;

typedef enum {
    LZ4F_max64KB = 0,
    LZ4F_max256KB,
    LZ4F_max1MB,
    LZ4F_max4MB
} LZ4F_blockSizeID_t;

typedef struct {
    LZ4F_blockSizeID_t blockSizeID;
    uint64_t contentSize;
} LZ4F_frameInfo_t;

typedef void* LZ4F_decompressionContext_t;

#define LZ4F_VERSION 100
#define LZ4F_isError(code) ((code) > 0)

#define wmem_packet_scope() ((wmem_allocator_t *)0)
#define tvb_memdup(allocator, tvb, offset, length) ((const void *)0)
#define tvb_new_composite() ((tvbuff_t *)0)
#define tvb_new_child_real_data(tvb, data, length, reported_length) ((tvbuff_t *)0)
#define tvb_composite_append(composite, tvb) 
#define tvb_composite_finalize(composite) 
#define tvb_free_chain(tvb) 
#define col_append_str(pinfo, column, str) 

struct _packet_info {
    wmem_allocator_t *pool;
    column_info *cinfo;
};

struct _column_info {
    int COL_INFO;
};

static uint32_t XXH32(const void* input, size_t length, uint32_t seed) {
    return 0;
}

static LZ4F_errorCode_t LZ4F_createDecompressionContext(LZ4F_decompressionContext_t* ctx, unsigned version) {
    return 0;
}

static LZ4F_errorCode_t LZ4F_getFrameInfo(LZ4F_decompressionContext_t ctx, LZ4F_frameInfo_t* info, const void* src, size_t* srcSize) {
    return 0;
}

static LZ4F_errorCode_t LZ4F_decompress(LZ4F_decompressionContext_t ctx, void* dst, size_t* dstSize, const void* src, size_t* srcSize, const void* options) {
    return 0;
}

static void LZ4F_freeDecompressionContext(LZ4F_decompressionContext_t ctx) {
}