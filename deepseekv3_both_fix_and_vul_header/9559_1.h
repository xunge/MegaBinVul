#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RR_MAX_CE_ENTRIES 32
#define KERN_NOTICE "<7>"
#define EIO 5
#define ENOMEM 12
#define GFP_KERNEL 0

struct rock_ridge {
    char u[0];
};

struct rock_state {
    struct inode *inode;
    void *buffer;
    unsigned int cont_offset;
    unsigned int cont_size;
    unsigned int cont_extent;
    unsigned int cont_loops;
    char *chr;
    unsigned int len;
};

struct inode {
    struct super_block *i_sb;
    unsigned int i_blkbits;
};

struct super_block;
struct buffer_head {
    char *b_data;
};

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
struct buffer_head *sb_bread(struct super_block *sb, unsigned int block);
void put_bh(struct buffer_head *bh);
int printk(const char *fmt, ...);