#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef unsigned int guint;
typedef int gint;
typedef uint32_t guint32;
typedef int gboolean;
typedef uint8_t guint8;

#define FALSE 0
#define TRUE 1

typedef struct tvbuff_t tvbuff_t;
typedef struct _wmem_allocator_t {
    void* pool;
} wmem_allocator_t;

typedef struct epan_column_info {
    void* cinfo;
} epan_column_info;

typedef struct packet_info {
    wmem_allocator_t* pool;
    epan_column_info* cinfo;
} packet_info;

typedef struct {
    const void* src;
    size_t size;
    size_t pos;
} ZSTD_inBuffer;

typedef struct {
    void* dst;
    size_t size;
    size_t pos;
} ZSTD_outBuffer;

typedef struct ZSTD_DStream_s ZSTD_DStream;

#define COL_INFO 0

wmem_allocator_t* wmem_packet_scope();
void* wmem_alloc(wmem_allocator_t* pool, size_t size);
void* tvb_memdup(wmem_allocator_t* alloc, tvbuff_t* tvb, int offset, guint32 length);
tvbuff_t* tvb_new_composite();
void tvb_composite_append(tvbuff_t* composite, tvbuff_t* child);
tvbuff_t* tvb_new_child_real_data(tvbuff_t* parent, guint8* data, guint length, gint reported_length);
void tvb_composite_finalize(tvbuff_t* composite);
void col_append_str(epan_column_info* cinfo, int column, const char* str);

ZSTD_DStream* ZSTD_createDStream();
size_t ZSTD_decompressStream(ZSTD_DStream* zds, ZSTD_outBuffer* output, ZSTD_inBuffer* input);
int ZSTD_isError(size_t code);
size_t ZSTD_DStreamOutSize(void);
void ZSTD_freeDStream(ZSTD_DStream* zds);