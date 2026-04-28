#include <stdint.h>
#include <limits.h>
#include <string.h>

typedef int32_t __s32;
typedef uint32_t __u32;
typedef uint64_t __u64;

struct inode {
    unsigned long i_ino;
    void *i_sb;
    void *i_data_sem;
};

struct extent_status {
    __u32 es_lblk;
    __u32 es_len;
    __u64 es_pblk;
};

struct ext4_map_blocks {
    __u32 m_lblk;
    __u32 m_len;
    __u64 m_pblk;
    unsigned int m_flags;
};

struct ext4_inode_info {
    void *i_data_sem;
};

#define EXT4_I(inode) ((struct ext4_inode_info *)(inode))

#define EXT4_INODE_EXTENTS      0x00080000
#define EXT4_GET_BLOCKS_KEEP_SIZE   0x0001
#define EXT4_GET_BLOCKS_CREATE      0x0002
#define EXT4_GET_BLOCKS_CONVERT_UNWRITTEN 0x0004
#define EXT4_GET_BLOCKS_DELALLOC_RESERVE  0x0008
#define EXT4_GET_BLOCKS_PRE_IO     0x0010
#define EXT4_GET_BLOCKS_ZERO       0x0020

#define EXT4_MAP_MAPPED    0x0001
#define EXT4_MAP_UNWRITTEN 0x0002
#define EXT4_MAP_NEW       0x0004
#define EXT4_MAP_FLAGS     (EXT4_MAP_MAPPED | EXT4_MAP_UNWRITTEN | EXT4_MAP_NEW)

#define EXTENT_STATUS_WRITTEN      0x01
#define EXTENT_STATUS_UNWRITTEN    0x02
#define EXTENT_STATUS_DELAYED      0x04

#define EXT_MAX_BLOCKS     0xffffffff
#define EFSCORRUPTED       117

#define ES_AGGRESSIVE_TEST

typedef void *handle_t;

#define ext_debug(fmt, ...)
#define ext4_warning(sb, fmt, ...)
#define ext4_test_inode_flag(inode, flag) (0)
#define ext4_clear_inode_state(inode, state)
#define ext4_es_lookup_extent(inode, lblk, es) (0)
#define ext4_es_is_written(es) (0)
#define ext4_es_is_unwritten(es) (0)
#define ext4_es_is_delayed(es) (0)
#define ext4_es_is_hole(es) (0)
#define ext4_es_pblock(es) (0)
#define ext4_ext_map_blocks(handle, inode, map, flags) (0)
#define ext4_ind_map_blocks(handle, inode, map, flags) (0)
#define ext4_es_insert_extent(inode, lblk, len, pblk, status) (0)
#define ext4_find_delalloc_range(inode, start, end) (0)
#define ext4_da_update_reserve_space(inode, len, used) 
#define ext4_issue_zeroout(inode, lblk, pblk, len) (0)
#define ext4_map_blocks_es_recheck(handle, inode, map, orig_map, flags)
#define check_block_validity(inode, map) (0)
#define down_read(sem)
#define up_read(sem)
#define down_write(sem)
#define up_write(sem)
#define WARN_ON(cond)
#define unlikely(cond) (cond)
#define BUG_ON(cond)