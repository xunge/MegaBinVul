#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#define ntohl(x) __builtin_bswap32(x)
#define PAGE_ALIGN(x) (((x) + 4095) & ~4095)
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
#define FLAT_DATA_ALIGN 4
#define MAX_SHARED_LIBS 4
#define FLAT_VERSION 0x00000004L
#define OLD_FLAT_VERSION 0x00000002L
#define FLAT_FLAG_RAM 0x1
#define FLAT_FLAG_GOTPIC 0x2
#define FLAT_FLAG_GZIP 0x4
#define FLAT_FLAG_GZDATA 0x8
#define FLAT_FLAG_KTRACE 0x10
#define RLIMIT_DATA 2
#define RLIM_INFINITY (~0UL)
#define ENOMEM 12
#define ENOEXEC 8
#define PER_LINUX_32BIT 0x0008
#define IS_ERR_VALUE(x) ((unsigned long)(void *)(x) >= (unsigned long)-4095)
#define PROT_READ 0x1
#define PROT_WRITE 0x2
#define PROT_EXEC 0x4
#define MAP_PRIVATE 0x02
#define MAP_EXECUTABLE 0x1000
#define RELOC_FAILED ((unsigned long)(-1))

#define max_t(type, x, y) ({ \
    type __max1 = (x); \
    type __max2 = (y); \
    __max1 > __max2 ? __max1 : __max2; \
})

struct linux_binprm {
    char buf[128];
    struct file *file;
    const char *filename;
};

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
};

struct inode {
};

struct file {
    struct path f_path;
    struct file_operations *f_op;
};

struct file_operations {
    ssize_t (*read)(struct file *, char *, size_t, loff_t *);
};

struct mm_struct {
    unsigned long start_code, end_code, start_data, end_data;
    unsigned long start_brk, brk;
    struct {
        unsigned long end_brk;
    } context;
    struct rw_semaphore *mmap_sem;
};

struct rw_semaphore {
};

struct task_struct {
    struct mm_struct *mm;
    struct {
        struct {
            unsigned long rlim_cur;
        } rlim[RLIMIT_DATA + 1];
    } *signal;
};

struct lib_info {
    struct {
        unsigned long start_code;
        unsigned long start_data;
        unsigned long start_brk;
        unsigned long text_len;
        int loaded;
        unsigned long entry;
        unsigned long build_date;
    } lib_list[MAX_SHARED_LIBS];
};

struct flat_hdr {
    char magic[4];
    uint32_t rev;
    uint32_t entry;
    uint32_t data_start;
    uint32_t data_end;
    uint32_t bss_end;
    uint32_t stack_size;
    uint32_t reloc_start;
    uint32_t reloc_count;
    uint32_t flags;
    uint32_t build_date;
};

extern struct task_struct *current;
extern int printk(const char *fmt, ...);
extern unsigned long do_mmap(struct file *file, unsigned long addr, unsigned long len, int prot, int flags, off_t offset);
extern void do_munmap(struct mm_struct *mm, unsigned long addr, unsigned long len);
extern int flush_old_exec(struct linux_binprm *bprm);
extern void set_personality(unsigned long personality);
extern void down_write(struct rw_semaphore *sem);
extern void up_write(struct rw_semaphore *sem);
extern unsigned long calc_reloc(unsigned long r, struct lib_info *libinfo, int curid, int internalp);
extern int flat_old_ram_flag(uint32_t flags);
extern void old_reloc(uint32_t r);
extern void flat_put_addr_at_rp(unsigned long *rp, unsigned long addr, unsigned long relval);
extern unsigned long flat_get_addr_from_rp(unsigned long *rp, unsigned long relval, uint32_t flags, unsigned long *persistent);
extern unsigned long flat_get_relocate_addr(unsigned long relval);
extern int flat_set_persistent(unsigned long relval, unsigned long *persistent);
extern void flush_icache_range(unsigned long start, unsigned long end);