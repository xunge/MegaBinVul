#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define __init
#define XEN_EXTRA_MEM_RATIO  (10)
#define EXTRA_MEM_RATIO      (10)
#define MAXMEM               (-1UL)
#define ISA_START_ADDRESS    (0xa0000)
#define ISA_END_ADDRESS      (0x100000)
#define PAGE_SIZE            (4096)
#define ENOSYS               (38)
#define E820_TYPE_RAM        (1)
#define E820_TYPE_RESERVED   (2)
#define XENMEM_memory_map    (0)
#define XENMEM_machine_memory_map (1)

#define BUG() abort()
#define BUG_ON(cond) do { if (cond) BUG(); } while (0)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define min3(a, b, c) min(min(a, b), c)
#define PFN_PHYS(x) ((phys_addr_t)(x) << PAGE_SHIFT)
#define PFN_UP(x) (((x) + PAGE_SIZE-1) >> PAGE_SHIFT)
#define PFN_DOWN(x) ((x) >> PAGE_SHIFT)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define __pa_symbol(x) ((phys_addr_t)(x))
#define PAGE_SHIFT (12)

typedef uint64_t phys_addr_t;
typedef uint32_t u32;

struct xen_start_info {
    unsigned long nr_pages;
};

struct xen_e820_entry {
    uint64_t addr;
    uint64_t size;
    uint32_t type;
};

struct xen_e820_table {
    uint32_t nr_entries;
    struct xen_e820_entry entries[128];
};

struct xen_memory_map {
    unsigned int nr_entries;
    void *buffer;
};

struct boot_params {
    struct {
        uint64_t ramdisk_image;
        uint64_t ramdisk_size;
    } hdr;
    uint64_t ext_ramdisk_image;
};

extern struct xen_e820_table xen_e820_table;
extern struct xen_e820_table *e820_table;
extern struct boot_params boot_params;
extern struct xen_start_info *xen_start_info;
extern unsigned long xen_max_p2m_pfn;
extern unsigned long xen_released_pages;
extern unsigned long max_mem_size;
extern unsigned long xen_saved_max_mem_size;
extern char _text[];
extern char __bss_stop[];

void set_xen_guest_handle(void *hnd, void *ptr);
bool xen_initial_domain(void);
int HYPERVISOR_memory_op(int op, void *arg);
void xen_parse_512gb(void);
unsigned long xen_get_pages_limit(void);
unsigned long xen_get_max_pages(void);
void xen_ignore_unusable(void);
void xen_add_extra_mem(unsigned long pfn, unsigned long n_pfns);
void xen_align_and_add_e820_region(phys_addr_t addr, phys_addr_t size, u32 type);
void xen_pt_check_e820(void);
void xen_reserve_xen_mfnlist(void);
unsigned long xen_foreach_remap_area(unsigned long max_pfn, unsigned long (*func)(unsigned long, unsigned long));
void xen_set_identity_and_remap_chunk(unsigned long start_pfn, unsigned long end_pfn);
unsigned long xen_count_remap_pages(unsigned long start_pfn, unsigned long end_pfn);
bool xen_is_e820_reserved(phys_addr_t start, phys_addr_t size);
void xen_raw_console_write(const char *str);
void xen_phys_memcpy(phys_addr_t dest, phys_addr_t src, phys_addr_t n);
phys_addr_t xen_find_free_area(phys_addr_t size);
void set_phys_range_identity(unsigned long pfn, unsigned long max_pfn);
void e820__update_table(struct xen_e820_table *table);
void e820__range_add(uint64_t start, uint64_t size, uint32_t type);
void memblock_free(uint64_t addr, uint64_t size);
int pr_info(const char *fmt, ...);