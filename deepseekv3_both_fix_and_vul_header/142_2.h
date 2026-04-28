#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct mutex {};
struct rw_semaphore {};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    void *vm_mm;
};

struct mm_struct {
    struct rw_semaphore mmap_sem;
};

struct ib_uverbs_file {
    struct rw_semaphore hw_destroy_rwsem;
    struct mutex umap_lock;
    struct list_head umaps;
};

struct rdma_umap_priv {
    struct list_head list;
    struct vm_area_struct *vma;
};

#define VM_SHARED 0x00000001
#define VM_MAYSHARE 0x00000002

#define list_empty(ptr) (0)
#define list_first_entry(ptr, type, member) (NULL)
#define list_del_init(ptr) 
#define list_for_each_entry_safe(pos, n, head, member) 
#define lockdep_assert_held(lock) 
#define mutex_lock(lock) 
#define mutex_unlock(lock) 
#define down_write(sem) 
#define up_write(sem) 
#define mmget_not_zero(mm) (0)
#define mmput(mm) 
#define zap_vma_ptes(vma, start, size) 