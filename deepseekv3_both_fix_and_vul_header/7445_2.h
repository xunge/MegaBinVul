#include <stdint.h>
#include <stdlib.h>

typedef int64_t loff_t;
typedef uint32_t __le32;

#define GFP_NOFS 0
#define QT_TREEOFF 1
#define ENOMEM 12
#define EUCLEAN 117

struct qtree_mem_dqinfo {
    unsigned int dqi_usable_bs;
    unsigned int dqi_blocks;
    unsigned int dqi_qtree_depth;
};

struct dquot {
    struct super_block *dq_sb;
    unsigned int dq_id;
};

struct super_block;

static inline uint32_t le32_to_cpu(uint32_t val) {
    return val;
}

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
int read_blk(struct qtree_mem_dqinfo *info, unsigned int blk, char *buf);
void quota_error(struct super_block *sb, const char *fmt, ...);
unsigned int get_index(struct qtree_mem_dqinfo *info, unsigned int id, int depth);
loff_t find_block_dqentry(struct qtree_mem_dqinfo *info, struct dquot *dquot, unsigned int blk);