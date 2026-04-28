#include <stdint.h>
#include <sys/types.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_ALIGN(addr) (((addr)+PAGE_SIZE-1)&PAGE_MASK)

#define ENODEV 19
#define EINVAL 22
#define EAGAIN 11

typedef uint32_t u32;

struct file;
struct mutex {
    int lock;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_pgoff;
    unsigned long vm_flags;
    unsigned long vm_page_prot;
};

struct fb_info {
    struct fb_ops *fbops;
    struct {
        unsigned long smem_start;
        unsigned long smem_len;
        unsigned long mmio_start;
        unsigned long mmio_len;
    } fix;
    struct {
        unsigned int accel_flags;
    } var;
    struct mutex mm_lock;
};

struct fb_ops {
    int (*fb_mmap)(struct fb_info *info, struct vm_area_struct *vma);
};

static inline void mutex_lock(struct mutex *lock) { (void)lock; }
static inline void mutex_unlock(struct mutex *lock) { (void)lock; }

static inline struct fb_info *file_fb_info(struct file *file) { (void)file; return 0; }
static inline unsigned long vm_get_page_prot(unsigned long flags) { (void)flags; return 0; }
static inline void fb_pgprotect(struct file *file, struct vm_area_struct *vma, unsigned long off) { (void)file; (void)vma; (void)off; }
static inline int io_remap_pfn_range(struct vm_area_struct *vma, unsigned long addr, unsigned long pfn, unsigned long size, unsigned long prot) { (void)vma; (void)addr; (void)pfn; (void)size; (void)prot; return 0; }