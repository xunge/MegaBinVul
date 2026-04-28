#include <stdlib.h>
#include <unistd.h>

#define BDRV_O_RDWR 0x0002
#define BDRV_O_CACHE_WB 0x0020
#define BDRV_O_NO_FLUSH 0x0080

#define BLOCK_OPT_SIZE 0
#define BLOCK_OPT_BACKING_FILE 1

typedef struct commit_t {
    // dummy definition since we don't know the actual structure
    int dummy;
} commit_t;

typedef struct BlockDriver {
    const char *format_name;
    void *create_options;
} BlockDriver;

typedef struct QEMUOptionParameter {
    const char *name;
    int type;
    union {
        int n;
        char *s;
    } value;
} QEMUOptionParameter;

typedef struct BlockDriverState {
    struct BlockDriver *drv;
    void *opaque;
    struct BlockDriverState *backing_hd;
} BlockDriverState;

typedef struct BDRVVVFATState {
    int sector_count;
    unsigned char *used_clusters;
    char *qcow_filename;
    BlockDriverState *qcow;
    BlockDriverState *bs;
    struct {
        commit_t *data;
        size_t size;
    } commits;
} BDRVVVFATState;

static BlockDriver vvfat_write_target;

static inline void array_init(void *array, size_t element_size) {
    ((struct { void *data; size_t size; }*)array)->data = NULL;
    ((struct { void *data; size_t size; }*)array)->size = 0;
}

static inline void *g_malloc(size_t size) { return malloc(size); }
static inline int sector2cluster(BDRVVVFATState *s, int sector) { return sector / 8; }