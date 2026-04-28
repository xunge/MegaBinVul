#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <sys/param.h>

typedef uint64_t paddr_t;
typedef uint32_t __be32;

#define MOD_INITRD 0
#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define PAGE_MASK (PAGE_SIZE - 1)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define PRIpaddr "lx"
#define GV2M_WRITE 0

#define min(a, b) ((a) < (b) ? (a) : (b))

struct module_info {
    paddr_t start;
    paddr_t size;
};

struct early_info {
    struct {
        struct module_info module[1];
    } modules;
};

extern struct early_info early_info;

struct kernel_info {
    paddr_t initrd_paddr;
    void *fdt;
};

void printk(const char *fmt, ...);
void panic(const char *msg);
int fdt_path_offset(void *fdt, const char *path);
int fdt_setprop_inplace(void *fdt, int nodeoffset, const char *name, const void *val, int len);
void dt_set_cell(__be32 **cellp, unsigned int cells, uint64_t value);
int gvirt_to_maddr(paddr_t gva, paddr_t *ma, ...);
void *map_domain_page(unsigned long mfn);
void unmap_domain_page(const void *va);
void copy_from_paddr(void *dst, paddr_t paddr, size_t len);