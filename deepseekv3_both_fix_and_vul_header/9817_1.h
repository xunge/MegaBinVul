#include <stddef.h>
#include <stdint.h>

#define STACK_TOP_MAX ((1UL << 47) - 4096)
#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define ENOMEM 12
#define VM_STACK_FLAGS 0x1000000
#define VM_STACK_INCOMPLETE_SETUP 0x2000000
#define BUG_ON(cond) ((void)0)

struct list_head {
    struct list_head *next, *prev;
};

struct rw_semaphore {
    int dummy;
};

struct vm_area_struct {
    struct mm_struct *vm_mm;
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    uint64_t vm_page_prot;
    struct list_head anon_vma_chain;
};

struct mm_struct {
    struct rw_semaphore mmap_sem;
    unsigned long stack_vm;
    unsigned long total_vm;
};

struct linux_binprm {
    struct mm_struct *mm;
    struct vm_area_struct *vma;
    unsigned long p;
};

extern struct kmem_cache *vm_area_cachep;
extern uint64_t vm_get_page_prot(unsigned long vm_flags);
extern int insert_vm_struct(struct mm_struct *mm, struct vm_area_struct *vma);

static inline void *kmem_cache_zalloc(struct kmem_cache *cachep, int flags) {
    (void)cachep; (void)flags;
    return calloc(1, sizeof(struct vm_area_struct));
}

static inline void kmem_cache_free(struct kmem_cache *cachep, void *objp) {
    (void)cachep;
    free(objp);
}

static inline void down_write(struct rw_semaphore *sem) {
    (void)sem;
}

static inline void up_write(struct rw_semaphore *sem) {
    (void)sem;
}

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}