#include <stdbool.h>
#include <pthread.h>

struct task_struct {
    int pid;
    char comm[16];
};

struct mm_struct {
    pthread_rwlock_t mmap_sem;
    unsigned long flags;
    struct vm_area_struct *mmap;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    struct vm_area_struct *vm_next;
};

struct mmu_gather {
    struct mm_struct *mm;
};

#define MMF_OOM_SKIP 0
#define MMF_UNSTABLE 1
#define VM_SHARED 0x00000001
#define HZ 100
#define MM_ANONPAGES 0
#define MM_FILEPAGES 1
#define MM_SHMEMPAGES 2

extern struct mutex oom_lock;

static inline bool mm_has_notifiers(struct mm_struct *mm) { return false; }
static inline bool vma_is_anonymous(struct vm_area_struct *vma) { return true; }
static inline bool can_madv_dontneed_vma(struct vm_area_struct *vma) { return true; }
static inline void tlb_gather_mmu(struct mmu_gather *tlb, struct mm_struct *mm, unsigned long start, unsigned long end) {}
static inline void tlb_finish_mmu(struct mmu_gather *tlb, unsigned long start, unsigned long end) {}
static inline void unmap_page_range(struct mmu_gather *tlb, struct vm_area_struct *vma, unsigned long start, unsigned long end, void *arg) {}
static inline int task_pid_nr(struct task_struct *tsk) { return tsk->pid; }
static inline unsigned long get_mm_counter(struct mm_struct *mm, int index) { return 0; }
static inline void trace_skip_task_reaping(int pid) {}
static inline void trace_start_task_reaping(int pid) {}
static inline void trace_finish_task_reaping(int pid) {}
static inline void schedule_timeout_idle(int timeout) {}
static inline bool test_bit(int nr, unsigned long *addr) { return false; }
static inline void set_bit(int nr, unsigned long *addr) {}
static inline bool down_read_trylock(pthread_rwlock_t *lock) { return true; }
static inline void up_read(pthread_rwlock_t *lock) {}
static inline void mutex_lock(pthread_mutex_t *lock) {}
static inline void mutex_unlock(pthread_mutex_t *lock) {}
#define K(x) (x)