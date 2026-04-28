#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>

struct page_info {
    unsigned long linear_pt_count;
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
    struct domain {
        bool is_dying;
    } *owner;
};

#define PGT_type_equal(a, b) ((a) == (b))
#define PGT_count_mask 0xFF
#define PGT_validated 0x100
#define PGT_partial 0x200

static int free_page_type(struct page_info *page, unsigned long type, bool preemptible);
static void dec_linear_uses(struct page_info *page);
static void dec_linear_entries(struct page_info *ptpg);
static void page_set_tlbflush_timestamp(struct page_info *page);
static struct domain *page_get_owner(struct page_info *page);
static void smp_wmb(void);
static void get_page_light(struct page_info *page);
#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define ASSERT(cond) do { if (!(cond)) abort(); } while (0)