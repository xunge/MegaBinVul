#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

typedef uint64_t TSK_INUM_T;
typedef uint64_t TSK_DADDR_T;
typedef int64_t TSK_OFF_T;
typedef uint32_t TSK_UID_T;
typedef uint32_t TSK_GID_T;

typedef enum {
    TSK_FS_ISTAT_RUNLIST
} TSK_FS_ISTAT_FLAG_ENUM;

typedef enum {
    TSK_FS_META_FLAG_ALLOC
} TSK_FS_META_FLAG_ENUM;

typedef enum {
    TSK_FS_ATTR_TYPE_DEFAULT,
    TSK_FS_ATTR_NONRES
} TSK_FS_ATTR_TYPE_ENUM;

typedef enum {
    TSK_FS_FILE_WALK_FLAG_AONLY
} TSK_FS_FILE_WALK_FLAG_ENUM;

typedef int (*TSK_FS_FILE_WALK_CB)(void *, TSK_OFF_T, void *);

typedef struct {
    int idx;
    FILE *hFile;
} YAFFSFS_PRINT_ADDR;

typedef struct TSK_FS_INFO {
    uint32_t block_size;
    uint32_t page_size;
    uint32_t spare_size;
} TSK_FS_INFO;

typedef struct TSK_FS_META {
    uint32_t flags;
    char *link;
    TSK_UID_T uid;
    TSK_GID_T gid;
    TSK_OFF_T size;
    uint16_t nlink;
    time_t mtime;
    time_t atime;
    time_t ctime;
    void *meta;
} TSK_FS_META;

typedef struct TSK_FS_FILE {
    TSK_FS_META *meta;
} TSK_FS_FILE;

typedef struct TSK_FS_ATTR {
    uint32_t flags;
} TSK_FS_ATTR;

typedef struct YAFFSFS_INFO {
    uint32_t page_size;
    uint32_t spare_size;
} YAFFSFS_INFO;

typedef struct YaffsCacheChunk {
    TSK_OFF_T ycc_offset;
} YaffsCacheChunk;

typedef struct YaffsCacheVersion {
    YaffsCacheChunk *ycv_header_chunk;
} YaffsCacheVersion;

typedef struct YaffsCacheObject {
    // empty struct for compilation
} YaffsCacheObject;

typedef struct YaffsHeader {
    char name[256];
} YaffsHeader;

#define PRIuINUM PRIu64
#define PRIuDADDR PRIu64
#define PRIdOFF PRId64
#define PRIuUID PRIu32
#define PRIuGID PRIu32

extern void yaffscache_version_find_by_inode(YAFFSFS_INFO *, TSK_INUM_T, YaffsCacheVersion **, YaffsCacheObject **);
extern TSK_FS_FILE *tsk_fs_file_open_meta(TSK_FS_INFO *, TSK_FS_FILE *, TSK_INUM_T);
extern int tsk_fprintf(FILE *, const char *, ...);
extern void tsk_fs_meta_make_ls(TSK_FS_META *, char *, size_t);
extern void yaffsfs_read_header(YAFFSFS_INFO *, YaffsHeader **, TSK_OFF_T);
extern const char *tsk_fs_time_to_str(time_t, char *);
extern const TSK_FS_ATTR *tsk_fs_file_attr_get_type(TSK_FS_FILE *, TSK_FS_ATTR_TYPE_ENUM, uint8_t, uint8_t);
extern int tsk_fs_attr_print(const TSK_FS_ATTR *, FILE *);
extern void tsk_error_print(FILE *);
extern void tsk_error_reset();
extern int tsk_fs_file_walk(TSK_FS_FILE *, TSK_FS_FILE_WALK_FLAG_ENUM, TSK_FS_FILE_WALK_CB, void *);
extern void tsk_fs_file_close(TSK_FS_FILE *);
extern int print_addr_act(void *, TSK_OFF_T, void *);