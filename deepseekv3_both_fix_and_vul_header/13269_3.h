#include <linux/types.h>

typedef int vm_fault_t;
#define VM_FAULT_SIGBUS 0

typedef unsigned long pgoff_t;

struct page;
struct vm_area_struct {
    void *vm_private_data;
};
struct vm_fault {
    struct vm_area_struct *vma;
    pgoff_t pgoff;
    struct page *page;
};
struct udmabuf {
    unsigned long pagecount;
    struct page **pages;
};

void get_page(struct page *page);