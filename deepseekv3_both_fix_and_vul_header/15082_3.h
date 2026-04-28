#include <stddef.h>
#include <stdint.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define PTE_FILE_MAX_BITS 32
#define BITS_PER_LONG 64

#define VM_SHARED 0x00000008
#define VM_NONLINEAR 0x00000040
#define VM_CAN_NONLINEAR 0x00000080
#define MAP_NONBLOCK 0x00010000

#define EINVAL 22

struct mm_struct {
    void *mm;
    void *mmap_sem;
};

struct file {
    struct address_space *f_mapping;
};

struct address_space {
    void *i_mmap_lock;
    void *i_mmap;
    void *i_mmap_nonlinear;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    void *vm_private_data;
    struct file *vm_file;
};

#define asmlinkage

extern struct mm_struct *current;
extern void down_read(void *);
extern void up_read(void *);
extern void down_write(void *);
extern void up_write(void *);
extern void downgrade_write(void *);
extern struct vm_area_struct *find_vma(struct mm_struct *, unsigned long);
extern unsigned long mmap_region(struct file *, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long, int);
extern int populate_range(struct mm_struct *, struct vm_area_struct *, unsigned long, unsigned long, unsigned long);
extern void make_pages_present(unsigned long, unsigned long);
extern unsigned long linear_page_index(struct vm_area_struct *, unsigned long);
extern int mapping_cap_account_dirty(struct address_space *);
extern void spin_lock(void *);
extern void spin_unlock(void *);
extern void flush_dcache_mmap_lock(struct address_space *);
extern void flush_dcache_mmap_unlock(struct address_space *);
extern void vma_prio_tree_remove(struct vm_area_struct *, void *);
extern void vma_nonlinear_insert(struct vm_area_struct *, void *);

#define IS_ERR_VALUE(x) ((unsigned long)(x) >= (unsigned long)-4095)
#define BUG_ON(cond) ((void)0)
#define likely(x) (x)
#define unlikely(x) (x)