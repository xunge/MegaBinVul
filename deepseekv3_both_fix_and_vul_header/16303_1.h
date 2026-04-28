#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

#define PAGE_ALIGNED(addr) (((addr) & (PAGE_SIZE - 1)) == 0)
#define PAGE_ALIGN(addr) (((addr) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
#define PAGE_SIZE 4096
#define CONFIG_MEMORY_FAILURE 1
#define EINVAL 22
#define ENOMEM 12
#define EINTR 4
#define MADV_HWPOISON 100
#define MADV_SOFT_OFFLINE 101

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct vm_area_struct *vm_next;
};

struct mm_struct {
    struct vm_area_struct *mmap;
    void *mmap_sem;
};

struct task_struct {
    struct mm_struct *mm;
};

struct blk_plug {
    // dummy structure
};

extern struct task_struct *current;
extern unsigned long untagged_addr(unsigned long addr);
extern int madvise_behavior_valid(int behavior);
extern int madvise_inject_error(int behavior, unsigned long start, unsigned long end);
extern int madvise_need_mmap_write(int behavior);
extern int down_write_killable(void *sem);
extern void down_read(void *sem);
extern void up_write(void *sem);
extern void up_read(void *sem);
extern struct vm_area_struct *find_vma_prev(struct mm_struct *mm, unsigned long addr, struct vm_area_struct **pprev);
extern struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr);
extern int madvise_vma(struct vm_area_struct *vma, struct vm_area_struct **prev, unsigned long start, unsigned long end, int behavior);
extern void blk_start_plug(struct blk_plug *plug);
extern void blk_finish_plug(struct blk_plug *plug);