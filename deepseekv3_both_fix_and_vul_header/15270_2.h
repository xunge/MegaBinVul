#include <stdatomic.h>
#include <stddef.h>

#define GFP_KERNEL 0
#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define VM_MAYSHARE 0x00000080
#define VM_SHARED 0x00000008
#define VM_EXECUTABLE 0x00001000
#define VM_MAPPED_COPY 0x00000004
#define BDI_CAP_MAP_DIRECT 0x00000001
#define BDI_CAP_MAP_COPY 0x00000002
#define ENOSYS 38
#define ENODEV 19
#define EINVAL 22
#define ENOMEM 12
#define KERN_WARNING 0
#define PROT_EXEC 0x4

struct list_head {
    struct list_head *next, *prev;
};

struct rb_node {
    unsigned long  __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
};

struct file_operations {
    unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
};

struct file {
    struct path f_path;
    const struct file_operations *f_op;
};

struct vm_region {
    struct rb_node vm_rb;
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    unsigned long vm_pgoff;
    struct file *vm_file;
    atomic_int vm_usage;
};

struct mm_struct {
    unsigned long total_vm;
};

struct task_struct {
    struct mm_struct *mm;
    int pid;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    unsigned long vm_pgoff;
    struct file *vm_file;
    struct vm_region *vm_region;
    struct mm_struct *vm_mm;
    struct list_head anon_vma_node;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct rw_semaphore {
    long count;
};

extern struct kmem_cache *vm_region_jar;
extern struct kmem_cache *vm_area_cachep;
extern struct rb_root nommu_region_tree;
extern struct rw_semaphore nommu_region_sem;
extern struct task_struct *current;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define kenter(fmt, ...) 
#define kleave(fmt, ...) 
#define kdebug(fmt, ...) 
#define printk(fmt, ...) 

static inline void atomic_set(atomic_int *v, int i) { *v = i; }
static inline void atomic_inc(atomic_int *v) { (*v)++; }
static inline void atomic_dec(atomic_int *v) { (*v)--; }

static inline struct rb_node *rb_first(const struct rb_root *root) { return NULL; }
static inline struct rb_node *rb_next(const struct rb_node *node) { return NULL; }
#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static inline void down_write(struct rw_semaphore *sem) {}
static inline void up_write(struct rw_semaphore *sem) {}
static inline void *kmem_cache_zalloc(struct kmem_cache *cache, int flags) { return NULL; }
static inline void kmem_cache_free(struct kmem_cache *cache, void *obj) {}
static inline void get_file(struct file *file) {}
static inline void fput(struct file *file) {}
static inline void INIT_LIST_HEAD(struct list_head *list) {}
static inline void added_exe_file_vma(struct mm_struct *mm) {}
static inline void removed_exe_file_vma(struct mm_struct *mm) {}
static inline void flush_icache_range(unsigned long start, unsigned long end) {}
static inline void show_free_areas(void) {}
static inline void add_nommu_region(struct vm_region *region) {}
static inline void add_vma_to_mm(struct mm_struct *mm, struct vm_area_struct *vma) {}

static inline int validate_mmap_request(struct file *file, unsigned long addr,
                    unsigned long len, unsigned long prot,
                    unsigned long flags, unsigned long pgoff,
                    unsigned long *capabilities) { return 0; }

static inline unsigned long determine_vm_flags(struct file *file,
                        unsigned long prot,
                        unsigned long flags,
                        unsigned long capabilities) { return 0; }

static inline int do_mmap_shared_file(struct vm_area_struct *vma) { return 0; }
static inline int do_mmap_private(struct vm_area_struct *vma,
                struct vm_region *region,
                unsigned long len,
                unsigned long capabilities) { return 0; }