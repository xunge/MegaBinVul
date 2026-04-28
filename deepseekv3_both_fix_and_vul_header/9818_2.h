#include <stddef.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define VM_DONTEXPAND 0x00020000
#define PAGE_SHIFT 12
#define ENOMEM 12
#define unlikely(x) (x)

struct page;

struct list_head {
    struct list_head *next, *prev;
};

struct mm_struct {
    unsigned long def_flags;
    unsigned long total_vm;
};

struct vm_area_struct {
    struct list_head anon_vma_chain;
    struct mm_struct *vm_mm;
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    unsigned long vm_page_prot;
    const void *vm_ops;
    void *vm_private_data;
};

struct kmem_cache;
extern struct kmem_cache *vm_area_cachep;

struct vm_operations_struct;
extern const struct vm_operations_struct special_mapping_vmops;

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

void *kmem_cache_zalloc(struct kmem_cache *cachep, int flags);
void kmem_cache_free(struct kmem_cache *cachep, void *objp);
unsigned long vm_get_page_prot(unsigned long vm_flags);
int insert_vm_struct(struct mm_struct *mm, struct vm_area_struct *vma);
void perf_event_mmap(struct vm_area_struct *vma);