#include <stddef.h>
#include <sys/types.h>
#include <pthread.h>

typedef unsigned long pgoff_t;

struct mm_struct;
struct vm_area_struct {
    struct file *vm_file;
};
struct page;
struct hstate;
struct address_space {
    pthread_mutex_t i_mmap_mutex;
    void *i_mmap;
};
struct prio_tree_iter {
    int dummy;
};
struct file {
    struct dentry *f_dentry;
};
struct dentry {
    struct inode *d_inode;
};
struct inode {
    struct address_space *i_mapping;
};

#define HPAGE_RESV_OWNER 0

static struct hstate *hstate_vma(struct vm_area_struct *vma) { return NULL; }
static unsigned long huge_page_mask(struct hstate *h) { return 0; }
static pgoff_t vma_hugecache_offset(struct hstate *h, struct vm_area_struct *vma, unsigned long address) { return 0; }
static int is_vma_resv_set(struct vm_area_struct *vma, int resv) { return 0; }
static void __unmap_hugepage_range(struct vm_area_struct *vma, unsigned long start, unsigned long end, struct page *page) {}
static unsigned long huge_page_size(struct hstate *h) { return 0; }

#define vma_prio_tree_foreach(vma, iter, root, start, end) \
    for (vma = NULL; vma != (void *)(end); vma = (void *)(start))