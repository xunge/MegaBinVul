#include <stddef.h>

#define MAX_NUMNODES 1
#define EFAULT 1
#define ENOENT 1

struct page_to_node {
    unsigned long addr;
    int node;
    int status;
};

struct mm_struct {
    void *mmap_sem;
};

struct vm_area_struct {
};

struct page {
};

static inline int page_to_nid(struct page *page) {
    return 0;
}

static inline struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) {
    return NULL;
}

static inline struct page *follow_page(struct vm_area_struct *vma, unsigned long addr, int flags) {
    return NULL;
}

static inline int PageReserved(struct page *page) {
    return 0;
}

static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}