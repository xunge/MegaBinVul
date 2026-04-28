#include <stddef.h>

#define PAGE_SIZE 4096
#define VM_READ 0x00000001
#define VM_EXEC 0x00000004
#define VM_MAYREAD 0x00000010
#define VM_MAYWRITE 0x00000020
#define VM_MAYEXEC 0x00000040
#define VM_ALWAYSDUMP 0x00008000

struct linux_binprm;

struct mm_struct {
    struct {
        void *vdso;
    } context;
    unsigned long def_flags;
    unsigned long total_vm;
    void *mmap_sem;
    struct mm_struct *mm;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    unsigned long vm_page_prot;
    void *vm_ops;
    struct mm_struct *vm_mm;
};

struct thread_info {
    void *sysenter_return;
};

struct vm_operations_struct;

extern struct {
    struct mm_struct *mm;
} *current;

extern struct kmem_cache *vm_area_cachep;
extern unsigned long protection_map[8];
extern struct vm_operations_struct syscall_vm_ops;
extern void *syscall_pages;
extern unsigned long SYSENTER_RETURN;

#define IS_ERR_VALUE(x) ((unsigned long)(void *)(x) >= (unsigned long)-4095)
#define VDSO_SYM(x) (x)
#define GFP_KERNEL 0
#define ENOMEM 12
#define unlikely(x) (x)

void down_write(void *);
void up_write(void *);
unsigned long get_unmapped_area(void *, unsigned long, unsigned long, unsigned long, unsigned long);
int install_special_mapping(struct mm_struct *, unsigned long, unsigned long, unsigned long, void *);
void *kmem_cache_zalloc(struct kmem_cache *, int);
void kmem_cache_free(struct kmem_cache *, void *);
int insert_vm_struct(struct mm_struct *, struct vm_area_struct *);
struct thread_info *current_thread_info(void);