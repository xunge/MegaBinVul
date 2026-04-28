#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef unsigned int ext4_group_t;

struct super_block {
    unsigned int s_blocksize_bits;
    void *s_fs_info;
};

struct ext4_group_desc {
    uint16_t bg_flags;
};

struct list_head {
    struct list_head *next, *prev;
};

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct rw_semaphore {
    long count;
};

struct ext4_sb_info {
    struct ext4_group_info ***s_group_info;
};

struct ext4_group_info {
    unsigned long bb_state;
    unsigned int bb_free;
    struct list_head bb_prealloc_list;
    struct rw_semaphore alloc_sem;
    struct rb_root bb_free_root;
    int bb_largest_free_order;
#ifdef DOUBLE_CHECK
    void *bb_bitmap;
#endif
};

struct kmem_cache;

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define EXT4_DESC_PER_BLOCK(sb) (1 << (sb)->s_blocksize_bits)
#define EXT4_DESC_PER_BLOCK_BITS(sb) ((sb)->s_blocksize_bits)
#define EXT4_GROUP_INFO_NEED_INIT_BIT 0
#define EXT4_BG_BLOCK_UNINIT 0x0001
#define GFP_NOFS 0
#define KERN_ERR 0
#define ENOMEM 12
#define RB_ROOT ((struct rb_root){NULL})

static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void *kmem_cache_zalloc(struct kmem_cache *cachep, int flags) { return calloc(1, sizeof(struct ext4_group_info)); }
static inline struct kmem_cache *get_groupinfo_cache(unsigned int blocksize_bits) { return NULL; }
static inline void set_bit(int nr, volatile unsigned long *addr) { *addr |= (1UL << nr); }
static inline void ext4_msg(struct super_block *sb, int level, const char *fmt, ...) {}
static inline unsigned int ext4_free_clusters_after_init(struct super_block *sb, ext4_group_t group, struct ext4_group_desc *desc) { return 0; }
static inline unsigned int ext4_free_group_clusters(struct super_block *sb, struct ext4_group_desc *desc) { return 0; }
static inline void INIT_LIST_HEAD(struct list_head *list) { list->next = list->prev = list; }
static inline void init_rwsem(struct rw_semaphore *sem) { sem->count = 0; }