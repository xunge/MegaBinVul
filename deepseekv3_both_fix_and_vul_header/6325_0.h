#include <stdbool.h>

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;

struct domain {
    struct grant_table *grant_table;
};

struct grant_table {
    int gt_version;
};

struct page;

#define XENMAPIDX_grant_table_status (1UL << 31)
#define INVALID_GFN ((gfn_t)-1)
#define EBUSY 16

void grant_write_lock(struct grant_table *gt);
void grant_write_unlock(struct grant_table *gt);
bool evaluate_nospec(bool condition);
int gnttab_get_status_frame_mfn(struct domain *d, unsigned long idx, mfn_t *mfn);
int gnttab_get_shared_frame_mfn(struct domain *d, unsigned long idx, mfn_t *mfn);
bool paging_mode_translate(struct domain *d);
gfn_t gnttab_get_frame_gfn(struct grant_table *gt, bool status, unsigned long idx);
bool gfn_eq(gfn_t a, gfn_t b);
int guest_physmap_remove_page(struct domain *d, gfn_t gfn, mfn_t mfn, int flags);
struct page *mfn_to_page(mfn_t mfn);
bool get_page(struct page *page, struct domain *d);
void gnttab_set_frame_gfn(struct grant_table *gt, bool status, unsigned long idx, gfn_t gfn);