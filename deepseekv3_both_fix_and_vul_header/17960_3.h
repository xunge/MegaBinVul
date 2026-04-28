#include <stddef.h>
#include <stdbool.h>

typedef struct { int dummy; } pmd_t;
typedef struct { int dummy; } pte_t;
typedef struct { int dummy; } spinlock_t;
typedef struct { int dummy; } swp_entry_t;

struct mm_walk {
    void *private;
    void *mm;
};

struct vm_area_struct {
    void *vm_mm;
};

struct page {};
struct page_cgroup {};
struct mem_cgroup {};

#define PAGE_SIZE 4096

enum {
    MC_TARGET_PAGE,
    MC_TARGET_SWAP
};

typedef union mc_target {
    struct page *page;
    swp_entry_t ent;
} mc_target;

static struct {
    struct mem_cgroup *from;
    struct mem_cgroup *to;
    unsigned long precharge;
    unsigned long moved_charge;
    unsigned long moved_swap;
} mc;

static int is_target_pte_for_mc(struct vm_area_struct *vma, unsigned long addr, pte_t ptent, mc_target *target) { return 0; }
static int isolate_lru_page(struct page *page) { return 0; }
static struct page_cgroup *lookup_page_cgroup(struct page *page) { return NULL; }
static int mem_cgroup_move_account(struct page *page, int count, struct page_cgroup *pc, struct mem_cgroup *from, struct mem_cgroup *to, bool force) { return 0; }
static void putback_lru_page(struct page *page) {}
static void put_page(struct page *page) {}
static int mem_cgroup_move_swap_account(swp_entry_t ent, struct mem_cgroup *from, struct mem_cgroup *to, bool force) { return 0; }
static int mem_cgroup_do_precharge(int count) { return 0; }
static void split_huge_page_pmd(struct mm_walk *mm, pmd_t *pmd) {}
static pte_t *pte_offset_map_lock(struct vm_area_struct *vma, pmd_t *pmd, unsigned long addr, spinlock_t **ptl) { return NULL; }
static void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static void cond_resched(void) {}