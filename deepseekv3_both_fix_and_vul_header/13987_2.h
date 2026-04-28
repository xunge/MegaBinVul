#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define DMG_SECTORCOUNTS_MAX 2048
#define DMG_LENGTHS_MAX 0x200000
#define EINVAL 22
#define Z_OK 0

typedef struct BlockDriverState {
    int read_only;
    void *file;
    void *opaque;
} BlockDriverState;

typedef struct QDict QDict;
typedef struct Error Error;

typedef struct z_stream {
    void *next_in;
    unsigned int avail_in;
    unsigned long total_in;
    void *next_out;
    unsigned int avail_out;
    unsigned long total_out;
    char *msg;
    void *state;
    void *(*zalloc)(void *, unsigned int, unsigned int);
    void (*zfree)(void *, void *);
    void *opaque;
    int data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;

typedef struct BDRVDMGState {
    uint32_t n_chunks;
    uint32_t *types;
    uint64_t *offsets;
    uint64_t *lengths;
    uint64_t *sectors;
    uint64_t *sectorcounts;
    uint8_t *compressed_chunk;
    uint8_t *uncompressed_chunk;
    z_stream zstream;
    int current_chunk;
    void *lock;
} BDRVDMGState;

static int64_t bdrv_getlength(void *file);
static int read_uint32(BlockDriverState *bs, int64_t offset, uint32_t *result);
static int read_uint64(BlockDriverState *bs, int64_t offset, uint64_t *result);
static void error_report(const char *fmt, ...);
static int inflateInit(z_stream *strm);
static void *g_malloc(size_t size);
static void *g_realloc(void *ptr, size_t size);
static void g_free(void *ptr);
static void qemu_co_mutex_init(void *mutex);