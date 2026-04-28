#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t guint32;
typedef uint32_t guint;
typedef uint8_t guint8;
typedef int gint;
typedef unsigned char guchar;
typedef int gboolean;

typedef void* LZ4F_decompressionContext_t;
typedef struct {
    unsigned blockSizeID;
    uint64_t contentSize;
} LZ4F_frameInfo_t;
typedef size_t LZ4F_errorCode_t;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void* pool;
    void* cinfo;
} packet_info;
typedef struct col_info_t col_info_t;
typedef struct composite_tvb_t composite_tvb_t;

#define FALSE 0
#define TRUE 1
#define LZ4F_VERSION 100
#define COL_INFO 0

enum {
    LZ4F_max64KB,
    LZ4F_max256KB,
    LZ4F_max1MB,
    LZ4F_max4MB
};

static void *wmem_packet_scope(void);
static void *tvb_memdup(void *allocator, tvbuff_t *tvb, int offset, guint32 length);
static uint32_t XXH32(const void* input, size_t length, uint32_t seed);
static tvbuff_t *tvb_new_composite(void);
static void tvb_composite_append(tvbuff_t *composite, tvbuff_t *child);
static tvbuff_t *tvb_new_child_real_data(tvbuff_t *parent, guint8 *data, guint length, gint reported_length);
static void tvb_composite_finalize(tvbuff_t *composite);
static void col_append_str(col_info_t *cinfo, int column, const char *str);
static void* wmem_alloc(void* pool, size_t size);
static LZ4F_errorCode_t LZ4F_createDecompressionContext(LZ4F_decompressionContext_t* ctx, unsigned version);
static int LZ4F_isError(LZ4F_errorCode_t code);
static LZ4F_errorCode_t LZ4F_getFrameInfo(LZ4F_decompressionContext_t ctx, LZ4F_frameInfo_t* info, const void* src, size_t* srcSizePtr);
static LZ4F_errorCode_t LZ4F_decompress(LZ4F_decompressionContext_t ctx, void* dst, size_t* dstSizePtr, const void* src, size_t* srcSizePtr, void* options);
static void LZ4F_freeDecompressionContext(LZ4F_decompressionContext_t ctx);