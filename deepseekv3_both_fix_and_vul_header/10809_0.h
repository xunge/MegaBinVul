#include <stdbool.h>

#define XENMAPIDX_grant_table_status (1UL << 31)
#define EINVAL 22

typedef unsigned long gfn_t;
typedef unsigned long mfn_t;

struct domain {
    struct grant_table *grant_table;
};

struct grant_table {
    unsigned int gt_version;
    unsigned int max_grant_frames;
    void **shared_raw;
    void **status;
};

static inline mfn_t _mfn(unsigned long mfn) { return mfn; }
static inline unsigned long virt_to_mfn(void *virt) { return 0; }
static inline bool gfn_eq(gfn_t a, gfn_t b) { return a == b; }
static inline gfn_t INVALID_GFN = 0;

static inline unsigned int nr_grant_frames(struct grant_table *gt) { return 0; }
static inline unsigned int nr_status_frames(struct grant_table *gt) { return 0; }
static inline bool paging_mode_translate(struct domain *d) { return false; }
static inline int guest_physmap_remove_page(struct domain *d, gfn_t gfn, mfn_t mfn, int flags) { return 0; }
static inline gfn_t gnttab_get_frame_gfn(struct grant_table *gt, bool status, unsigned long idx) { return 0; }
static inline void gnttab_set_frame_gfn(struct grant_table *gt, bool status, unsigned long idx, gfn_t gfn) {}
static inline void grant_write_lock(struct grant_table *gt) {}
static inline void grant_write_unlock(struct grant_table *gt) {}
static inline void gnttab_grow_table(struct domain *d, unsigned int count) {}