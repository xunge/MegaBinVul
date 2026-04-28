#include <stddef.h>
#include <errno.h>

typedef unsigned int vm_flags_t;

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_ALIGN(addr) (((addr)+PAGE_SIZE-1)&PAGE_MASK)

#define VM_MAYREAD 0x00000010
#define VM_MAYWRITE 0x00000020  
#define VM_MAYEXEC 0x00000040
#define VM_MAYSHARE 0x00000080
#define VM_SHARED 0x00000001
#define VM_EXEC 0x00000004
#define VM_GROWSDOWN 0x00000100
#define VM_GROWSUP 0x00000200
#define VM_LOCKED 0x00002000
#define VM_NORESERVE 0x00000040

#define MAP_SHARED 0x01
#define MAP_PRIVATE 0x02
#define MAP_FIXED 0x10
#define MAP_FIXED_NOREPLACE 0x100000
#define MAP_LOCKED 0x02000
#define MAP_POPULATE 0x08000
#define MAP_NONBLOCK 0x10000
#define MAP_NORESERVE 0x04000
#define MAP_TYPE 0x0f
#define MAP_SHARED_VALIDATE 0x03

#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4

#define FMODE_READ 0x1
#define FMODE_WRITE 0x2

#define READ_IMPLIES_EXEC 0x04000000
#define LEGACY_MAP_MASK (MAP_SHARED | MAP_PRIVATE | MAP_FIXED)
#define OVERCOMMIT_NEVER 2

struct path {
    void *dummy;
};

struct vm_area_struct {
    unsigned long vm_start;
};

struct file_operations {
    unsigned long mmap_supported_flags;
    int (*mmap)(struct file *, void *);
};

struct file {
    struct path f_path;
    const struct file_operations *f_op;
    unsigned int f_mode;
};

struct mm_struct {
    unsigned long def_flags;
    unsigned long map_count;
};

struct inode {
    int dummy;
};

struct list_head {
    void *next, *prev;
};

struct task_struct {
    struct mm_struct *mm;
    unsigned long personality;
};

#define current ((struct task_struct *)0)
#define sysctl_max_map_count 65530
#define sysctl_overcommit_memory 0

#define IS_APPEND(inode) 0
#define IS_ERR_VALUE(x) ((unsigned long)(void *)(x) >= (unsigned long)-4095)

static inline int execute_only_pkey(struct mm_struct *mm) { return 0; }
static inline unsigned long get_unmapped_area(struct file *file, unsigned long addr,
                    unsigned long len, unsigned long pgoff, unsigned long flags) { return 0; }
static inline unsigned long mmap_region(struct file *file, unsigned long addr,
                    unsigned long len, vm_flags_t vm_flags, unsigned long pgoff,
                    struct list_head *uf) { return 0; }
static inline int can_do_mlock(void) { return 1; }
static inline int mlock_future_check(struct mm_struct *mm, vm_flags_t vm_flags,
                    unsigned long len) { return 0; }
static inline int path_noexec(const struct path *path) { return 0; }
static inline int locks_verify_locked(struct file *file) { return 0; }
static inline int is_file_hugepages(struct file *file) { return 0; }
static inline unsigned long round_hint_to_min(unsigned long addr) { return addr; }
static inline unsigned long calc_vm_prot_bits(unsigned long prot, int pkey) { return 0; }
static inline unsigned long calc_vm_flag_bits(unsigned long flags) { return 0; }
static inline struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) { return NULL; }
static inline int offset_in_page(unsigned long addr) { return 0; }
static inline struct inode *file_inode(struct file *file) { return NULL; }