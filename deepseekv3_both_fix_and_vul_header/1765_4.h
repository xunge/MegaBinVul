#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

typedef int vm_fault_t;
#define VM_FAULT_SIGBUS 0
#define EFAULT 14

struct page {
    unsigned long flags;
};

struct mutex {
    int lock;
};

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct {
    unsigned long mmap_base;
};

struct task_struct {
    int pid;
};

#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define mutex_lock(lock) ((void)0)
#define mutex_unlock(lock) ((void)0)
#define mutex_lock_nested(lock, subclass) ((void)0)
#define READ_ONCE(x) (x)
#define current ((struct task_struct *)0)

enum svm_work_list_ops {
    SVM_OP_UPDATE_RANGE_NOTIFIER,
    SVM_OP_UPDATE_RANGE_NOTIFIER_AND_MAP
};

struct svm_range {
    unsigned long start;
    unsigned long last;
    unsigned long *actual_loc;
    struct mutex migrate_mutex;
    struct mutex lock;
};

struct kfd_svm {
    struct mutex lock;
    struct task_struct *faulting_task;
};

struct kfd_process {
    bool xnack_enabled;
    struct kfd_svm svms;
};

struct vm_fault {
    unsigned long address;
    struct vm_area_struct *vma;
    struct page *page;
};

#define KFD_MIGRATE_TRIGGER_PAGEFAULT_CPU 0
#define PAGE_SHIFT 12

extern struct kfd_process *kfd_lookup_process_by_mm(struct mm_struct *mm);
extern void kfd_unref_process(struct kfd_process *p);
extern struct svm_range *svm_range_from_addr(struct kfd_svm *svms, unsigned long addr, struct svm_range **parent);
extern int svm_range_split_by_granularity(struct kfd_process *p, struct mm_struct *mm, unsigned long addr, struct svm_range *parent, struct svm_range *prange);
extern int svm_migrate_vram_to_ram(struct svm_range *prange, struct mm_struct *mm, int trigger, ...);
extern void svm_range_add_list_work(struct kfd_svm *svms, struct svm_range *prange, struct mm_struct *mm, enum svm_work_list_ops op);
extern void schedule_deferred_list_work(struct kfd_svm *svms);
extern void svm_range_lock(struct svm_range *prange);
extern void svm_range_unlock(struct svm_range *prange);