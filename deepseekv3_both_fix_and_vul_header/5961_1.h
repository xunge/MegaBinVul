#include <stdint.h>
#include <stdio.h>

#define JFS_MAGIC_NUMBER 0xc03b3998U
#define JFS_SUPERBLOCK_V1 1
#define JFS_SUPERBLOCK_V2 2
#define KERN_ERR ""
#define KERN_WARNING ""
#define READ 0
#define EIO 5
#define EINVAL 22

struct buffer_head {
    int dummy;
};

struct journal_header_s {
    uint32_t h_magic;
    uint32_t h_blocktype;
};

struct journal_superblock_s {
    struct journal_header_s s_header;
    uint32_t s_blocksize;
    uint32_t s_maxlen;
    uint32_t s_first;
};
typedef struct journal_superblock_s journal_superblock_t;

struct journal_s {
    struct buffer_head *j_sb_buffer;
    journal_superblock_t *j_superblock;
    uint32_t j_blocksize;
    uint32_t j_maxlen;
    int j_format_version;
};
typedef struct journal_s journal_t;

static inline uint32_t cpu_to_be32(uint32_t x) {
    return ((x & 0xff000000) >> 24) | 
           ((x & 0x00ff0000) >> 8) |
           ((x & 0x0000ff00) << 8) |
           ((x & 0x000000ff) << 24);
}

static inline uint32_t be32_to_cpu(uint32_t x) {
    return cpu_to_be32(x);
}

void ll_rw_block(int, int, struct buffer_head**);
void wait_on_buffer(struct buffer_head*);
int buffer_uptodate(struct buffer_head*);
void journal_fail_superblock(journal_t*);

#define J_ASSERT(cond) do { if (!(cond)) { printf("JBD: assertion failed\n"); } } while (0)