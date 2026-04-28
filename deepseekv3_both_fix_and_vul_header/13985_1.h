#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>

#define HEADER_MAGIC "BXPC"
#define REDOLOG_TYPE "Redolog"
#define GROWING_TYPE "Growing"
#define HEADER_VERSION 0x00020000
#define HEADER_V1 0x00010000

struct bochs_header {
    char magic[4];
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

typedef struct BlockDriverState {
    void *opaque;
    int read_only;
    void *file;
    uint64_t total_sectors;
} BlockDriverState;

typedef struct BDRVBochsState {
    uint32_t catalog_size;
    uint32_t *catalog_bitmap;
    uint32_t data_offset;
    uint32_t bitmap_blocks;
    uint32_t extent_blocks;
    uint32_t extent_size;
    void *lock;
} BDRVBochsState;

typedef struct QDict QDict;
typedef struct Error Error;

static inline uint32_t le32_to_cpu(uint32_t v) { return v; }
static inline uint64_t le64_to_cpu(uint64_t v) { return v; }
static inline void le32_to_cpus(uint32_t *v) { *v = le32_to_cpu(*v); }

int bdrv_pread(void *file, int64_t offset, void *buf, int bytes);
void *g_malloc(size_t size);
void g_free(void *ptr);
void error_setg(Error **errp, const char *fmt, ...);
void qemu_co_mutex_init(void *mutex);