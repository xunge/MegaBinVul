#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned int guint;
typedef unsigned char guint8;
typedef unsigned char Bytef;
#define G_MAXUINT UINT_MAX
#define QTDEMUX_MAX_SAMPLE_INDEX_SIZE (1024 * 1024 * 1024)

#define Z_OK 0
#define Z_STREAM_END 1
#define Z_MEM_ERROR (-4)
#define Z_NO_FLUSH 0

struct z_stream_s {
    void *next_in;
    unsigned int avail_in;
    void *next_out;
    unsigned int avail_out;
    void *zalloc;
    void *zfree;
    void *opaque;
    unsigned int total_out;
};
typedef struct z_stream_s z_stream;

#define GST_ERROR(fmt, ...)
#define GST_WARNING(fmt, ...)

static int inflateInit(z_stream *strm);
static int inflate(z_stream *strm, int flush);
static int inflateEnd(z_stream *strm);

static void *g_malloc(size_t size);
static void *g_realloc(void *ptr, size_t size);
static void g_free(void *ptr);