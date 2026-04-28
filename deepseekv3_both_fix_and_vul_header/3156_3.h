#include <stdint.h>
#include <stdatomic.h>
#include <errno.h>

typedef uint64_t chunk_t;
typedef uint64_t sector_t;

struct block_device;

struct dm_snapshot {
    struct block_device *bdev;
};

struct dm_exception_store {
    struct dm_snapshot *snap;
    uint32_t chunk_size;
};

struct dm_exception {
    chunk_t new_chunk;
};

struct pstore {
    chunk_t next_free;
    uint32_t exceptions_per_area;
    atomic_uint pending_count;
};

extern struct pstore *get_info(struct dm_exception_store *store);
extern sector_t get_dev_size(struct block_device *bdev);
extern struct dm_snapshot *dm_snap_cow(struct dm_snapshot *snap);
extern uint64_t sector_div(uint64_t dividend, uint32_t divisor);