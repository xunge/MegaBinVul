#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define HEADER_MAGIC "WithoutFreeSpace"
#define HEADER_VERSION 1

typedef struct BlockDriverState {
    void *opaque;
    int read_only;
    int64_t total_sectors;
    void *file;
} BlockDriverState;

typedef struct QDict QDict;
typedef struct Error Error;

struct parallels_header {
    char magic[16];
    uint32_t version;
    uint32_t nb_sectors;
    uint32_t tracks;
    uint32_t catalog_entries;
};

struct CoMutex {
    int dummy;
};

typedef struct BDRVParallelsState {
    uint32_t *catalog_bitmap;
    uint32_t catalog_size;
    uint32_t tracks;
    struct CoMutex lock;
} BDRVParallelsState;

static inline uint32_t le32_to_cpu(uint32_t v) {
    return v;
}

static inline void le32_to_cpus(uint32_t *v) {
    *v = le32_to_cpu(*v);
}

static inline int bdrv_pread(void *file, int64_t offset, void *buf, int bytes) {
    return 0;
}

static inline void error_setg(Error **errp, const char *fmt, ...) {}

static inline void *g_malloc(size_t size) {
    return malloc(size);
}

static inline void g_free(void *ptr) {
    free(ptr);
}

static inline void qemu_co_mutex_init(struct CoMutex *mutex) {}