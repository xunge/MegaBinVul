#include <stdint.h>

#define SQUASHFS_MAGIC 0x73717368
#define SQUASHFS_INVALID_BLK 0xFFFFFFFFFFFFFFFFLL
#define TRUE 1

typedef struct squashfs_super_block_3 {
    uint32_t s_magic;
    uint32_t inodes;
    uint32_t mkfs_time;
    uint32_t block_size;
    uint32_t fragments;
    uint32_t block_log;
    uint32_t flags;
    uint32_t s_major;
    uint32_t s_minor;
    uint32_t root_inode;
    uint32_t bytes_used_2;
    uint32_t inode_table_start;
    uint32_t directory_table_start_2;
    uint32_t fragment_table_start_2;
    uint32_t inode_table_start_2;
    uint16_t no_uids;
    uint16_t no_guids;
    uint32_t uid_start_2;
    uint32_t guid_start_2;
} squashfs_super_block_3;

typedef struct {
    struct {
        uint32_t s_magic;
        uint32_t inodes;
        uint32_t mkfs_time;
        uint32_t block_size;
        uint32_t fragments;
        uint32_t block_log;
        uint32_t flags;
        uint32_t s_major;
        uint32_t s_minor;
        uint32_t root_inode;
        uint32_t bytes_used;
        uint32_t inode_table_start;
        uint32_t directory_table_start;
        uint32_t fragment_table_start;
        uint64_t xattr_id_table_start;
    } s;
    uint16_t no_uids;
    uint16_t no_guids;
    uint32_t uid_start;
    uint32_t guid_start;
} squashfs_super_block;

typedef struct squashfs_operations {
    int dummy;
} squashfs_operations;

extern squashfs_super_block sBlk;
extern squashfs_operations ops;
extern void *lookup_compressor(const char *);
extern void *comp;
extern int needs_sorting;