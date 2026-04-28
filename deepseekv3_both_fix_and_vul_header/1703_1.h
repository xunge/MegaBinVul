#include <stddef.h>

struct vm_area_struct {
    struct mm_struct *vm_mm;
    struct anon_vma *anon_vma;
};

struct mm_struct {
    int page_table_lock;
};

struct anon_vma {
    int num_children;
    int num_active_vmas;
    int degree;
};

struct anon_vma_chain;

#define GFP_KERNEL 0
#define ENOMEM 1
#define unlikely(x) (x)
#define likely(x) (x)

void might_sleep(void);
struct anon_vma_chain *anon_vma_chain_alloc(int);
struct anon_vma *find_mergeable_anon_vma(struct vm_area_struct *);
struct anon_vma *anon_vma_alloc(void);
void anon_vma_lock_write(struct anon_vma *);
void anon_vma_unlock_write(struct anon_vma *);
void anon_vma_chain_link(struct vm_area_struct *, struct anon_vma_chain *, struct anon_vma *);
void put_anon_vma(struct anon_vma *);
void anon_vma_chain_free(struct anon_vma_chain *);
void spin_lock(int *);
void spin_unlock(int *);