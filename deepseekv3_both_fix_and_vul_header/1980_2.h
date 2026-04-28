#include <stddef.h>

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
};

struct hstate;
struct hugepage_subpool;

struct region {
    unsigned long start;
    unsigned long end;
};

struct kref {
    int refcount;
};

struct resv_map {
    struct kref refs;
    struct region regions;
};

static inline struct hstate *hstate_vma(struct vm_area_struct *vma) { return NULL; }
static inline struct resv_map *vma_resv_map(struct vm_area_struct *vma) { return NULL; }
static inline struct hugepage_subpool *subpool_vma(struct vm_area_struct *vma) { return NULL; }
static inline unsigned long vma_hugecache_offset(struct hstate *h, struct vm_area_struct *vma, unsigned long addr) { return 0; }
static inline long region_count(struct region *regions, unsigned long start, unsigned long end) { return 0; }
static inline void resv_map_release(struct kref *ref) {}
static inline void hugetlb_acct_memory(struct hstate *h, long delta) {}
static inline void hugepage_subpool_put_pages(struct hugepage_subpool *spool, long delta) {}
static inline void kref_put(struct kref *kref, void (*release)(struct kref *kref)) {}