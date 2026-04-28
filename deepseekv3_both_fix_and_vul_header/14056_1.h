#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t TSK_INUM_T;
typedef int64_t TSK_OFF_T;

#define TSK_ERR 1
#define TSK_OK 0

#define ISO9660_MAXNAMLEN 255
#define ISO9660_FLAG_DIR 0x02

#define TSK_FS_NAME_TYPE_DIR 1
#define TSK_FS_NAME_TYPE_REG 2
#define TSK_FS_NAME_FLAG_ALLOC 1

typedef struct {
    uint32_t ext_loc_m;
    uint8_t entry_len;
    uint8_t flags;
    char fn[1];
} iso9660_dentry;

typedef struct {
    uint32_t ext_loc_m;
} iso9660_dr;

typedef struct {
    iso9660_dr dr;
    char fn[1];
} iso9660_inode;

typedef struct iso9660_inode_node {
    iso9660_inode inode;
    TSK_INUM_T inum;
    TSK_OFF_T dentry_offset;
    struct iso9660_inode_node *next;
} iso9660_inode_node;

typedef struct {
    iso9660_inode_node *in_list;
} ISO_INFO;

typedef struct {
    size_t block_size;
    int endian;
} TSK_FS_INFO;

typedef struct {
    TSK_INUM_T meta_addr;
    char name[ISO9660_MAXNAMLEN + 1];
    int type;
    int flags;
} TSK_FS_NAME;

typedef struct {
    // dummy definition since actual contents aren't used in this function
} TSK_FS_DIR;

TSK_FS_NAME *tsk_fs_name_alloc(size_t len, int flags);
void tsk_fs_name_free(TSK_FS_NAME *fs_name);
void tsk_fs_dir_add(TSK_FS_DIR *a_fs_dir, TSK_FS_NAME *fs_name);
uint32_t tsk_getu32(int endian, uint32_t val);