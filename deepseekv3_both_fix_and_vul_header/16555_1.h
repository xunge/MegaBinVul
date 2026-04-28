#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct spinlock {
    int lock;
} spinlock_t;

#define _MEMF_bits 32
#define _MEMF_node 0
#define NR_ZONES 10
#define MAX_ORDER 20
#define PGC_need_scrub (1 << 0)
#define PGC_state_free (0)
#define PGC_state_inuse (1 << 1)
#define _PGC_need_scrub 0
#define INVALID_DIRTY_IDX (~0U)
#define XENLOG_ERR 0
#define PRI_mfn "lx"

#define MEMF_no_refcount (1 << 0)
#define MEMF_no_scrub (1 << 1)
#define MEMF_no_tlbflush (1 << 2)
#define MEMF_no_icache_flush (1 << 3)

typedef unsigned int nodeid_t;
typedef unsigned long mfn_t;

struct domain {
    unsigned long outstanding_pages;
    nodeid_t last_alloc_node;
};

struct page_info {
    unsigned long count_info;
    union {
        struct {
            unsigned int first_dirty;
            unsigned long val;
        } free;
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    union {
        struct {
            unsigned int order;
        } free;
    } v;
    uint32_t tlbflush_timestamp;
};

extern unsigned long outstanding_claims;
extern unsigned long total_avail_pages;
extern unsigned long avail[][NR_ZONES];
extern int node_need_scrub[];
extern int scrub_debug;
extern spinlock_t heap_lock;

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define ASSERT(cond) do { if (!(cond)) abort(); } while (0)
#define unlikely(cond) (cond)
#define mfn_x(mfn) (mfn)
#define page_to_mfn(pg) ((mfn_t)0)
#define page_to_maddr(pg) 0
#define page_to_zone(pg) 0
#define PFN_ORDER(pg) 0
#define test_bit(bit, addr) (*(addr) & (1UL << (bit)))
#define spin_lock(lock) do {} while (0)
#define spin_unlock(lock) do {} while (0)
#define printk(fmt, ...) do {} while (0)
#define BUG() abort()

static nodeid_t phys_to_nid(unsigned long addr) { return 0; }
static void accumulate_tlbflush(bool *need, struct page_info *pg, uint32_t *timestamp) {}
static void filtered_flush_tlb_mask(uint32_t timestamp) {}
static void flush_page_to_ram(unsigned long mfn, bool flush_icache) {}
static void scrub_one_page(struct page_info *pg) {}
static void check_one_page(struct page_info *pg) {}
static void check_low_mem_virq() {}
static void page_set_owner(struct page_info *pg, void *owner) {}
static void page_list_add_scrub(struct page_info *pg, nodeid_t node, unsigned int zone, unsigned int order, unsigned int dirty) {}
static struct page_info *get_free_buddy(unsigned int zone_lo, unsigned int zone_hi, unsigned int order, unsigned int memflags, struct domain *d) { return NULL; }