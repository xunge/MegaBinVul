#include <stddef.h>
#include <stdbool.h>

struct super_block;
struct mempolicy;

struct spinlock {
    int lock;
};

struct percpu_counter {
    long counter;
};

struct shmem_sb_info {
    unsigned long max_inodes;
    unsigned long free_inodes;
    unsigned long max_blocks;
    struct percpu_counter used_blocks;
    struct spinlock stat_lock;
    struct mempolicy *mpol;
};

#define SHMEM_SB(sb) ((struct shmem_sb_info *)((char*)sb + 0))
#define EINVAL 22

static inline void spin_lock(struct spinlock *lock) { (void)lock; }
static inline void spin_unlock(struct spinlock *lock) { (void)lock; }
static inline int percpu_counter_compare(struct percpu_counter *counter, unsigned long value) { return 0; }

int shmem_parse_options(char *data, struct shmem_sb_info *config, bool remount);
void mpol_put(struct mempolicy *mpol);