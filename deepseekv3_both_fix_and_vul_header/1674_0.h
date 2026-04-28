#include <stdint.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct BDRVBochsState BDRVBochsState;

struct BDRVBochsState {
    uint32_t *catalog_bitmap;
    int64_t extent_size;
    int64_t data_offset;
    int64_t extent_blocks;
    int64_t bitmap_blocks;
    void *opaque;
};

struct BlockDriverState {
    BDRVBochsState *opaque;
    void *file;
};

int bdrv_pread(void *file, int64_t offset, void *buf, int size);