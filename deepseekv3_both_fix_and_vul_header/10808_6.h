#include <stdbool.h>

#define XENMAPIDX_grant_table_status (1U << 31)
#define _mfn(x) (x)
#define EINVAL 22

struct domain {
    struct grant_table *grant_table;
};

struct grant_table {
    unsigned int gt_version;
    unsigned int max_grant_frames;
    void **shared_raw;
    void **status;
};

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;

void grant_write_lock(struct grant_table *gt);
void grant_write_unlock(struct grant_table *gt);
unsigned int nr_status_frames(struct grant_table *gt);
unsigned int nr_grant_frames(struct grant_table *gt);
int gnttab_grow_table(struct domain *d, unsigned int idx);
void gnttab_set_frame_gfn(struct grant_table *gt, ...);
unsigned long virt_to_mfn(void *virt);