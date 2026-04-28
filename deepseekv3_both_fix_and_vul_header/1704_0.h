#include <stddef.h>

struct vm_area_struct {
    struct anon_vma *anon_vma;
};

struct anon_vma {
    struct anon_vma *root;
    struct anon_vma *parent;
    int num_active_vmas;
    int num_children;
    int degree;
};

struct anon_vma_chain;

int anon_vma_clone(struct vm_area_struct *vma, struct vm_area_struct *pvma);
struct anon_vma *anon_vma_alloc(void);
struct anon_vma_chain *anon_vma_chain_alloc(int gfp_flags);
void get_anon_vma(struct anon_vma *anon_vma);
void put_anon_vma(struct anon_vma *anon_vma);
void anon_vma_lock_write(struct anon_vma *anon_vma);
void anon_vma_unlock_write(struct anon_vma *anon_vma);
void anon_vma_chain_link(struct vm_area_struct *vma, struct anon_vma_chain *avc, struct anon_vma *anon_vma);
void unlink_anon_vmas(struct vm_area_struct *vma);

#define GFP_KERNEL 0
#define ENOMEM 12