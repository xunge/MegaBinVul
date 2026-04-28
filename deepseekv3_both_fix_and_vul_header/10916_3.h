#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

typedef enum {
    TSK_OK,
    TSK_ERR,
    TSK_COR,
    TSK_ERR_FS_ARG,
    TSK_ERR_FS_READ,
    TSK_ERR_FS_INODE_COR,
    TSK_ERR_FS_INODE_NUM,
    TSK_ERR_FS_GENFS
} TSK_RETVAL_ENUM;

typedef uint64_t TSK_INUM_T;
typedef int64_t TSK_OFF_T;
typedef uint64_t TSK_DADDR_T;

#define PRIuINUM PRIu64
#define PRIuDADDR PRIu64
#define PRIdOFF PRId64

#define NTFS_LAST_DEFAULT_INO 16
#define NTFS_UPDATE_SEQ_STRIDE 512
#define NTFS_MFT_MAGIC 0x46494C45
#define NTFS_MFT_MAGIC_BAAD 0x44414142
#define NTFS_MFT_MAGIC_ZERO 0x00000000

typedef struct {
    uint32_t magic;
    uint16_t upd_off;
    uint16_t upd_cnt;
} ntfs_mft;

typedef struct {
    uint16_t upd_val;
    uint16_t upd_seq;
} ntfs_upd;

typedef struct TSK_FS_ATTR_RUN {
    TSK_DADDR_T addr;
    TSK_DADDR_T len;
    struct TSK_FS_ATTR_RUN *next;
} TSK_FS_ATTR_RUN;

typedef struct {
    TSK_INUM_T first_inum;
    TSK_INUM_T last_inum;
    int endian;
} TSK_FS_INFO;

typedef struct {
    struct {
        TSK_FS_ATTR_RUN *run;
    } nrd;
} NTFS_DATA;

typedef struct {
    TSK_FS_INFO fs_info;
    TSK_OFF_T root_mft_addr;
    size_t mft_rsize_b;
    size_t csize_b;
    NTFS_DATA *mft_data;
} NTFS_INFO;

extern int tsk_verbose;
extern void tsk_error_reset(void);
extern void tsk_error_set_errno(int err);
extern void tsk_error_set_errstr(const char *fmt, ...);
extern void tsk_error_set_errstr2(const char *fmt, ...);
extern int tsk_fprintf(FILE *stream, const char *fmt, ...);
extern ssize_t tsk_fs_read(TSK_FS_INFO *fs, TSK_OFF_T off, char *buf, size_t len);
extern uint16_t tsk_getu16(int endian, const void *buf);
extern uint32_t tsk_getu32(int endian, const void *buf);