#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

#define QCOW_MAGIC 0x514649fb
#define MIN_CLUSTER_BITS 9
#define MAX_CLUSTER_BITS 21
#define QCOW_MAX_SNAPSHOTS 65536
#define QCOW_CRYPT_AES 1
#define QCOW2_INCOMPAT_MASK 0x0000ffff
#define QCOW2_INCOMPAT_CORRUPT (1 << 0)
#define QCOW2_INCOMPAT_DIRTY (1 << 1)
#define QCOW2_COMPAT_LAZY_REFCOUNTS (1 << 0)
#define QCOW2_OPT_LAZY_REFCOUNTS "lazy-refcounts"
#define QCOW2_OPT_DISCARD_REQUEST "discard-request"
#define QCOW2_OPT_DISCARD_SNAPSHOT "discard-snapshot"
#define QCOW2_OPT_DISCARD_OTHER "discard-other"
#define L2_CACHE_SIZE 32
#define REFCOUNT_CACHE_SIZE 32
#define QCOW_MAX_CRYPT_CLUSTERS 32
#define BDRV_O_RDWR 0x0002
#define BDRV_O_CHECK 0x0010
#define BDRV_O_INCOMING 0x0020
#define BDRV_O_UNMAP 0x0040
#define BDRV_FIX_ERRORS 0x01
#define QCOW2_OL_CONSTANT (1 << 0)
#define QCOW2_OL_CACHED (1 << 1)
#define QCOW2_OL_ALL (QCOW2_OL_CONSTANT | QCOW2_OL_CACHED)
#define QCOW2_OL_MAX_BITNR 2

typedef struct BlockDriverState {
    void *opaque;
    void *file;
    int encrypted;
    int read_only;
    char backing_file[1024];
    int64_t total_sectors;
} BlockDriverState;

typedef struct QDict QDict;
typedef struct Error Error;
typedef struct QemuOpts QemuOpts;

typedef struct BDRVQcowState {
    int qcow_version;
    uint32_t cluster_bits;
    uint32_t cluster_size;
    uint32_t cluster_sectors;
    uint64_t incompatible_features;
    uint64_t compatible_features;
    uint64_t autoclear_features;
    uint32_t refcount_order;
    uint32_t crypt_method_header;
    uint32_t l2_bits;
    uint32_t l2_size;
    uint64_t csize_shift;
    uint64_t csize_mask;
    uint64_t cluster_offset_mask;
    uint64_t refcount_table_offset;
    uint64_t refcount_table_size;
    uint64_t snapshots_offset;
    uint32_t nb_snapshots;
    uint32_t l1_size;
    uint64_t l1_vm_state_index;
    uint64_t l1_table_offset;
    uint64_t *l1_table;
    void *l2_table_cache;
    void *refcount_block_cache;
    void *cluster_cache;
    void *cluster_data;
    int64_t cluster_cache_offset;
    int flags;
    int use_lazy_refcounts;
    bool discard_passthrough[5];
    int overlap_check;
    size_t unknown_header_fields_size;
    void *unknown_header_fields;
    void *lock;
    void *cluster_allocs;
    void *discards;
} BDRVQcowState;

typedef struct QCowHeader {
    uint32_t magic;
    uint32_t version;
    uint64_t backing_file_offset;
    uint32_t backing_file_size;
    uint32_t cluster_bits;
    uint64_t size;
    uint32_t crypt_method;
    uint32_t l1_size;
    uint64_t l1_table_offset;
    uint64_t refcount_table_offset;
    uint32_t refcount_table_clusters;
    uint32_t nb_snapshots;
    uint64_t snapshots_offset;
    uint64_t incompatible_features;
    uint64_t compatible_features;
    uint64_t autoclear_features;
    uint32_t refcount_order;
    uint32_t header_length;
} QCowHeader;

typedef struct QCowSnapshotHeader {
    uint64_t l1_table_offset;
    uint32_t l1_size;
    char id_str[128];
    char name[256];
    uint64_t vm_state_size;
    uint32_t date_sec;
    uint32_t date_nsec;
    uint64_t vm_clock_nsec;
} QCowSnapshotHeader;

typedef struct BdrvCheckResult {
    int corruptions;
    int leaks;
    int check_errors;
    int corruptions_fixed;
    int leaks_fixed;
    int64_t image_end_offset;
    int64_t leak_offset;
    int64_t leak_size;
} BdrvCheckResult;

static const char *overlap_bool_option_names[] = {
    "overlap-check.template",
    "overlap-check.cached",
};

static struct {
    const char *name;
    const char *desc;
} qcow2_runtime_opts[] = {
    { QCOW2_OPT_LAZY_REFCOUNTS, "Postpone refcount updates" },
    { QCOW2_OPT_DISCARD_REQUEST, "Pass guest discard requests to the layer below" },
    { QCOW2_OPT_DISCARD_SNAPSHOT, "Generate discard requests when snapshot related space is freed" },
    { QCOW2_OPT_DISCARD_OTHER, "Generate discard requests when other clusters are freed" },
    { "overlap-check", "Selects which overlap checks to perform from a range of templates" },
    { NULL, NULL }
};

enum {
    QCOW2_DISCARD_NEVER,
    QCOW2_DISCARD_ALWAYS,
    QCOW2_DISCARD_REQUEST,
    QCOW2_DISCARD_SNAPSHOT,
    QCOW2_DISCARD_OTHER,
};

static Error *error_abort = NULL;

static inline uint32_t MIN(uint32_t a, uint32_t b) { return a < b ? a : b; }