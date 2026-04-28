#include <stdbool.h>
#include <stddef.h>

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

#define PGT_count_mask 0xFF
#define PGT_locked 0x100
#define PGT_type_mask 0xFF00
#define PGT_validated 0x10000
#define PGT_partial 0x20000
#define PGT_l4_page_table 0x1

#define ASSERT(x) 
#define ASSERT_UNREACHABLE() 
#define unlikely(x) (x)
#define likely(x) (x)
#define BUG_ON(x) 
#define IS_ENABLED(x) 0
#define CONFIG_PV_LINEAR_PT 0

#define EILSEQ 1
#define EINTR 2

static void current_locked_page_ne_check(struct page_info *page) {}
static int _put_final_page_type(struct page_info *page, unsigned long x, bool preemptible, struct page_info *ptpg) { return 0; }
static void put_page(struct page_info *page) {}
static void set_tlbflush_timestamp(struct page_info *page) {}
static void cpu_relax(void) {}
static bool hypercall_preempt_check(void) { return false; }
static bool PGT_type_equal(unsigned long a, unsigned long b) { return false; }
static void dec_linear_uses(struct page_info *page) {}
static void dec_linear_entries(struct page_info *ptpg) {}

static unsigned long cmpxchg(unsigned long *ptr, unsigned long old, unsigned long new) {
    unsigned long prev = *ptr;
    if (prev == old)
        *ptr = new;
    return prev;
}