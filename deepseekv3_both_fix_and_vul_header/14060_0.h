#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>
#include <math.h>

typedef uint64_t TSK_DADDR_T;
typedef int64_t ssize_t;

#define FATFS_FAIL 0
#define FATFS_OK 1
#define FATFS_DATA_UNIT_ALLOC_STATUS_UNKNOWN 0
#define TSK_ERR_FS_READ 0

typedef struct {
    uint8_t entry_type;
    uint8_t flags;
    uint32_t first_cluster_of_bitmap;
    uint64_t length_of_alloc_bitmap_in_bytes;
} EXFATFS_ALLOC_BITMAP_DIR_ENTRY;

typedef struct {
    TSK_DADDR_T first_sector_of_alloc_bitmap;
    uint64_t length_of_alloc_bitmap_in_bytes;
} EXFATFS_INFO;

typedef struct {
    int endian;
} TSK_FS_INFO;

typedef struct {
    TSK_FS_INFO fs_info;
    EXFATFS_INFO EXFATFS_INFO;
    uint32_t rootsect;
    uint32_t firstdatasect;
    uint32_t clustcnt;
    uint32_t csize;
    uint32_t ssize;
} FATFS_INFO;

typedef struct {
    // Define FATFS_DENTRY structure as needed
} FATFS_DENTRY;

enum EXFATFS_DIR_ENTRY_TYPE_ENUM {
    EXFATFS_DIR_ENTRY_TYPE_ALLOC_BITMAP
};

void *tsk_malloc(size_t size);
ssize_t tsk_fs_read_block(TSK_FS_INFO *fs, TSK_DADDR_T sector, char *buf, size_t size);
uint32_t tsk_getu32(int endian, uint32_t val);
uint64_t tsk_getu64(int endian, uint64_t val);
void tsk_error_reset(void);
void tsk_error_set_errno(int err);
void tsk_error_set_errstr2(const char *fmt, ...);
int exfatfs_get_enum_from_type(uint8_t type);
int exfatfs_is_alloc_bitmap_dentry(FATFS_DENTRY *dentry, int status, FATFS_INFO *fatfs);
#define FATFS_CLUST_2_SECT(fatfs, clust) ((clust) * (fatfs)->csize + (fatfs)->firstdatasect)
#define roundup(x, y) ((((x) + (y) - 1) / (y)) * (y))
#define PRIuDADDR PRIu64