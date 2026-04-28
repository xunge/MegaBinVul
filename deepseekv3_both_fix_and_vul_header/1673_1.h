#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define HEADER_MAGIC "Bochs Virtual HD Image"
#define REDOLOG_TYPE "Redolog"
#define GROWING_TYPE "Growing"
#define HEADER_VERSION 0x20000
#define HEADER_V1 0x10000

typedef struct BlockDriverState {
    void *opaque;
    int read_only;
    uint64_t total_sectors;
    void *file;
} BlockDriverState;

typedef struct QDict QDict;
typedef struct Error Error;

struct bochs_header {
    char magic[32];
    char type[16];
    char subtype[16];
    uint32_t version;
    uint32_t header;
    uint32_t catalog;
    uint32_t bitmap;
    uint32_t extent;
    union {
        struct {
            uint64_t disk;
        } redolog;
        struct {
            uint64_t disk;
        } redolog_v1;
    } extra;
};

typedef struct BDRVBochsState {
    uint32_t catalog_size;
    uint32_t *catalog_bitmap;
    uint32_t data_offset;
    uint32_t bitmap_blocks;
    uint32_t extent_blocks;
    uint32_t extent_size;
    void *lock;
} BDRVBochsState;

static inline uint32_t le32_to_cpu(uint32_t v) { return v; }
static inline uint64_t le64_to_cpu(uint64_t v) { return v; }
static inline void le32_to_cpus(uint32_t *v) { *v = le32_to_cpu(*v); }

int bdrv_pread(void *file, int64_t offset, void *buf, int bytes);
void error_setg(Error **errp, const char *fmt, ...);
void *g_malloc(size_t size);
void g_free(void *ptr);
void qemu_co_mutex_init(void *mutex);