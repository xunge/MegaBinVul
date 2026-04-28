#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t nid_t;

#define GFP_NOFS 0
#define NULL_ADDR 0
#define NID_NEW 0
#define FREE_NID_LIST 0
#define IS_CHECKPOINTED 0
#define unlikely(x) (x)

struct f2fs_sb_info {
    void *nm_info;
};

struct f2fs_nm_info {
    int nid_list_lock;
};

struct free_nid {
    nid_t nid;
    int state;
};

struct nat_entry;

static void *free_nid_slab;

#define NM_I(sbi) ((struct f2fs_nm_info *)(sbi)->nm_info)

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}

static void *f2fs_kmem_cache_alloc(void *slab, int flags) { return NULL; }
static void kmem_cache_free(void *slab, void *ptr) {}
static struct nat_entry *__lookup_nat_cache(struct f2fs_nm_info *nm_i, nid_t nid) { return NULL; }
static bool get_nat_flag(struct nat_entry *ne, int flag) { return false; }
static nid_t nat_get_blkaddr(struct nat_entry *ne) { return 0; }
static struct free_nid *__lookup_free_nid_list(struct f2fs_nm_info *nm_i, nid_t nid) { return NULL; }
static int __insert_nid_to_list(struct f2fs_sb_info *sbi, struct free_nid *i, int list, bool insert) { return 0; }
static int radix_tree_preload(int flags) { return 0; }
static void radix_tree_preload_end(void) {}