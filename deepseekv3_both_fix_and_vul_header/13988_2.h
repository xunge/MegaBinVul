#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

typedef struct BlockDriverState BlockDriverState;
typedef struct BDRVQcowState BDRVQcowState;
typedef struct QCowSnapshot QCowSnapshot;
typedef struct Error Error;

struct BlockDriverState {
    BDRVQcowState *opaque;
    int read_only;
    void *file;
};

struct BDRVQcowState {
    uint64_t *l1_table;
    uint64_t l1_table_offset;
    int l1_size;
    QCowSnapshot *snapshots;
};

struct QCowSnapshot {
    uint64_t l1_table_offset;
    int l1_size;
};

#define align_offset(offset, align) (((offset) + (align) - 1) & ~((align) - 1))

#define ENOMEM 12
#define ENOENT 2

static inline void be64_to_cpus(uint64_t *x) {
    *x = __builtin_bswap64(*x);
}

static inline void g_free(void *ptr) {
    free(ptr);
}

static inline void *g_malloc0(size_t size) {
    return calloc(1, size);
}

static inline void error_setg(Error **errp, const char *fmt, ...) {
    (void)errp;
    (void)fmt;
}

static int bdrv_pread(void *file, uint64_t offset, void *buf, int bytes) {
    (void)file;
    (void)offset;
    (void)buf;
    (void)bytes;
    return 0;
}

static int find_snapshot_by_id_and_name(BlockDriverState *bs, const char *snapshot_id, const char *name) {
    (void)bs;
    (void)snapshot_id;
    (void)name;
    return 0;
}