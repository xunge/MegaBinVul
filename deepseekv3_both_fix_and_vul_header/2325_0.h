#include <stdbool.h>
#include <stddef.h>

#define unlikely(x) (x)
#define likely(x) (x)
#define ASSERT(x) ((void)0)

#define PGT_count_mask 0
#define PGT_type_mask 0
#define PGT_l4_page_table 0
#define PGT_validated 0
#define PGT_partial 0
#define PGT_type_equal(a, b) (0)
#define EINTR 0

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    int linear_pt_count;
};

static int _put_final_page_type(struct page_info *page, unsigned long x, bool preemptible, struct page_info *ptpg);
static void put_page(struct page_info *page);
static void page_set_tlbflush_timestamp(struct page_info *page);
static struct { int is_dying; } *page_get_owner(struct page_info *page);
static void dec_linear_uses(struct page_info *page);
static void dec_linear_entries(struct page_info *ptpg);
static int hypercall_preempt_check(void);