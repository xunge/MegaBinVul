#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LOOP_ITERATIONS 1000
#define LZ4F_VERSION 100
#define LZ4F_max64KB 0
#define LZ4F_max256KB 1
#define LZ4F_max1MB 2
#define LZ4F_max4MB 3
#define FALSE 0
#define TRUE 1
#define COL_INFO 0

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gint;
typedef int gboolean;
typedef unsigned char guchar;

typedef struct {
    unsigned blockSizeID;
    uint64_t contentSize;
} LZ4F_frameInfo_t;

typedef void* LZ4F_decompressionContext_t;
typedef size_t LZ4F_errorCode_t;

typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info {
    void* pool;
    void* cinfo;
} packet_info;

#define LZ4F_isError(code) ((code) > 0)
#define DISSECTOR_ASSERT_HINT(cond, msg) do { if (!(cond)) abort(); } while(0)

static void* tvb_memdup(void* pool, tvbuff_t* tvb, int offset, guint32 length) { return NULL; }
static tvbuff_t* tvb_new_composite() { return NULL; }
static void tvb_composite_append(tvbuff_t* composite, tvbuff_t* child) {}
static void tvb_composite_finalize(tvbuff_t* composite) {}
static tvbuff_t* tvb_new_child_real_data(tvbuff_t* parent, guint8* data, guint length, gint reported_length) { return NULL; }
static void* wmem_alloc(void* pool, size_t size) { return NULL; }
static void col_append_str(void* cinfo, int col, const char* str) {}
static LZ4F_errorCode_t LZ4F_createDecompressionContext(LZ4F_decompressionContext_t* ctx, unsigned version) { return 0; }
static LZ4F_errorCode_t LZ4F_getFrameInfo(LZ4F_decompressionContext_t ctx, LZ4F_frameInfo_t* info, const void* src, size_t* srcSize) { return 0; }
static LZ4F_errorCode_t LZ4F_decompress(LZ4F_decompressionContext_t ctx, void* dst, size_t* dstSize, const void* src, size_t* srcSize, void* options) { return 0; }
static void LZ4F_freeDecompressionContext(LZ4F_decompressionContext_t ctx) {}
static uint32_t XXH32(const void* input, size_t length, uint32_t seed) { return 0; }