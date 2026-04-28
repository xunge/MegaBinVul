#include <stdlib.h>
#include <stdint.h>

#define QT_TREEOFF 1
#define ENOMEM 12
#define EUCLEAN 117
#define GFP_NOFS 0

struct qtree_mem_dqinfo {
    unsigned int dqi_usable_bs;
    unsigned int dqi_blocks;
    unsigned int dqi_qtree_depth;
};

struct dquot {
    void *dq_sb;
    uint32_t dq_id;
};

typedef uint32_t __le32;
typedef uint32_t qid_t;

static inline uint32_t le32_to_cpu(__le32 val) { return val; }
static inline __le32 cpu_to_le32(uint32_t val) { return val; }

static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *ptr) { free(ptr); }

static int read_blk(struct qtree_mem_dqinfo *info, unsigned int blk, char *buf);
static int free_dqentry(struct qtree_mem_dqinfo *info, struct dquot *dquot, unsigned int blk);
static int put_free_dqblk(struct qtree_mem_dqinfo *info, char *buf, unsigned int blk);
static int write_blk(struct qtree_mem_dqinfo *info, unsigned int blk, char *buf);
static int get_index(struct qtree_mem_dqinfo *info, qid_t id, int depth);
static void quota_error(void *sb, const char *fmt, ...);