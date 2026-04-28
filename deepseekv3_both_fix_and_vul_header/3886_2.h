#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

struct inode {
    struct ext4_super_block *i_sb;
};

struct buffer_head {
    char *b_data;
};

struct dx_frame {
    struct buffer_head *bh;
    void *at;
    void *entries;
};

struct dx_hash_info {
    u32 hash;
};

struct dx_map_entry {
    u32 hash;
    unsigned int size;
};

struct ext4_dir_entry_2 {
    unsigned int rec_len;
};

struct ext4_dir_entry_tail {
};

struct ext4_super_block {
    unsigned int s_blocksize;
};

typedef struct handle_s handle_t;
typedef unsigned long ext4_lblk_t;

#define KERN_INFO ""
#define IS_ERR(x) (0)
#define BUFFER_TRACE(bh, msg)
#define dxtrace(x)