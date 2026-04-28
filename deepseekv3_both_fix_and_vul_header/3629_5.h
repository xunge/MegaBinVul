#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>
#include <sys/param.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define PAGE_SHIFT 12

typedef uint64_t paddr_t;
#define PRIpaddr PRIx64

#define GV2M_WRITE 0
#define GV2M_READ 1

struct zimage_info {
    paddr_t kernel_addr;
    paddr_t len;
};

struct kernel_info {
    struct zimage_info zimage;
    paddr_t entry;
};

extern paddr_t kernel_zimage_place(struct kernel_info *info);
extern void place_modules(struct kernel_info *info, paddr_t start, paddr_t end);
extern void printk(const char *fmt, ...);
extern int gvirt_to_maddr(paddr_t addr, paddr_t *ma, ...);
extern void *map_domain_page(unsigned long mfn);
extern void unmap_domain_page(void *va);
extern void copy_from_paddr(void *dst, paddr_t paddr, size_t len);
extern void panic(const char *msg);

#define min(a, b) ((a) < (b) ? (a) : (b))