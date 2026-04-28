#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define VM_LOCKED     0x00002000
#define VM_NONLINEAR  0x00004000
#define VM_HUGETLB    0x00008000
#define VM_SHARED     0x00000001
#define VM_WRITE      0x00000002

#define PAGE_SHIFT    12
#define EINVAL        22
#define EACCES        13
#define FALLOC_FL_PUNCH_HOLE 0x02
#define FALLOC_FL_KEEP_SIZE  0x01

typedef long loff_t;

struct rw_semaphore {
    pthread_rwlock_t lock;
};

struct inode {
    int dummy;
};

struct address_space {
    struct inode *host;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    unsigned long vm_pgoff;
    struct file *vm_file;
};

struct file {
    struct address_space *f_mapping;
    int (*fallocate)(struct file *, int, loff_t, loff_t);
};

struct mm_struct {
    struct rw_semaphore mmap_sem;
};

struct task_struct {
    struct mm_struct *mm;
};

extern struct task_struct *current;

int do_fallocate(struct file *file, int mode, loff_t offset, loff_t len);

static inline void up_read(struct rw_semaphore *sem) {
    pthread_rwlock_unlock(&sem->lock);
}

static inline void down_read(struct rw_semaphore *sem) {
    pthread_rwlock_rdlock(&sem->lock);
}