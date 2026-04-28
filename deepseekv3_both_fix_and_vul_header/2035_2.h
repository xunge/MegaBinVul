#include <stddef.h>

struct kref {
    int dummy;
};

struct file {
    struct {
        int dummy;
    } *f_mapping;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct file *vm_file;
};

struct hstate;
struct resv_map {
    struct {
        int dummy;
    } regions;
    struct kref refs;
};

static struct hstate *hstate_vma(struct vm_area_struct *vma) { return NULL; }
static struct resv_map *vma_resv_map(struct vm_area_struct *vma) { return NULL; }
static unsigned long vma_hugecache_offset(struct hstate *h, struct vm_area_struct *vma, unsigned long addr) { return 0; }
static long region_count(void *regions, unsigned long start, unsigned long end) { return 0; }
static void kref_put(struct kref *kref, void (*release)(struct kref *kref)) {}
static void resv_map_release(struct kref *kref) {}
static void hugetlb_acct_memory(struct hstate *h, long reserve) {}
static void hugetlb_put_quota(void *mapping, unsigned long reserve) {}