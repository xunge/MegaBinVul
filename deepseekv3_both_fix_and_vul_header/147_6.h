#include <stddef.h>
#include <string.h>
#include <sys/types.h>

#define PROC_NUMBUF 32
#define EFAULT 14
#define ESRCH 3
#define EINVAL 22
#define EINTR 4
#define VM_SOFTDIRTY (1 << 0)

typedef long ssize_t;
typedef long loff_t;
typedef unsigned long size_t;
#define __user

enum clear_refs_types {
    CLEAR_REFS_ALL,
    CLEAR_REFS_ANON,
    CLEAR_REFS_MAPPED,
    CLEAR_REFS_SOFT_DIRTY,
    CLEAR_REFS_MM_HIWATER_RSS,
    CLEAR_REFS_LAST
};

struct rw_semaphore {
    int dummy;
};
struct mmu_gather {
    int dummy;
};
struct mmu_notifier_range {
    int dummy;
};

struct file {
    struct inode *f_inode;
};
struct inode;
struct task_struct;
struct vm_area_struct {
    unsigned long vm_flags;
    struct vm_area_struct *vm_next;
};
struct mm_struct {
    struct vm_area_struct *mmap;
    unsigned long highest_vm_end;
    struct rw_semaphore mmap_sem;
};
struct clear_refs_private {
    enum clear_refs_types type;
};
struct mm_walk {
    int (*pmd_entry)(void *, unsigned long, unsigned long, struct mm_walk *);
    int (*test_walk)(unsigned long, unsigned long, struct mm_walk *);
    struct mm_struct *mm;
    struct clear_refs_private *private;
};

static int copy_from_user(void *to, const void __user *from, unsigned long n) { return 0; }
static int kstrtoint(const char *s, unsigned int base, int *res) { return 0; }
static char *strstrip(char *s) { return s; }
static struct task_struct *get_proc_task(struct inode *inode) { return 0; }
static struct inode *file_inode(struct file *file) { return 0; }
static struct mm_struct *get_task_mm(struct task_struct *task) { return 0; }
static int down_write_killable(struct rw_semaphore *sem) { return 0; }
static void reset_mm_hiwater_rss(struct mm_struct *mm) {}
static void up_write(struct rw_semaphore *sem) {}
static void down_read(struct rw_semaphore *sem) {}
static void tlb_gather_mmu(struct mmu_gather *tlb, struct mm_struct *mm, unsigned long start, unsigned long end) {}
static void up_read(struct rw_semaphore *sem) {}
static void downgrade_write(struct rw_semaphore *sem) {}
static void mmu_notifier_range_init(struct mmu_notifier_range *range, struct mm_struct *mm, unsigned long start, unsigned long end) {}
static void mmu_notifier_invalidate_range_start(struct mmu_notifier_range *range) {}
static void walk_page_range(unsigned long start, unsigned long end, struct mm_walk *walk) {}
static void mmu_notifier_invalidate_range_end(struct mmu_notifier_range *range) {}
static void tlb_finish_mmu(struct mmu_gather *tlb, unsigned long start, unsigned long end) {}
static void mmput(struct mm_struct *mm) {}
static void put_task_struct(struct task_struct *task) {}
static void vma_set_page_prot(struct vm_area_struct *vma) {}

static int clear_refs_pte_range(void *pmd, unsigned long addr,
                unsigned long end, struct mm_walk *walk) { return 0; }
static int clear_refs_test_walk(unsigned long start, unsigned long end,
                struct mm_walk *walk) { return 0; }