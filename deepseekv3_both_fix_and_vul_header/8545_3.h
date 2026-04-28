#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define ACPI_OVERRIDE_TABLES 64
#define MAP_CHUNK_SIZE (256 * 1024)
#define PAGE_SHIFT 12
#define PAGE_SIZE (1 << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE - 1))
#define PREFIX "ACPI: "
#define __init

struct acpi_table_header {
    char signature[4];
    uint32_t length;
};

struct cpio_data {
    void *data;
    size_t size;
    char name[32];
};

typedef unsigned long phys_addr_t;

extern const char *table_sigs[];
extern struct cpio_data acpi_initrd_files[ACPI_OVERRIDE_TABLES];
extern unsigned long acpi_tables_addr;
extern size_t all_tables_size;
extern unsigned long max_low_pfn_mapped;

int acpi_table_checksum(void *data, size_t size);
struct cpio_data find_cpio_data(const char *path, void *data, size_t len, long *offset);
int get_securelevel(void);
void *early_ioremap(unsigned long phys_addr, size_t size);
void early_iounmap(void *addr, size_t size);
void memblock_reserve(unsigned long addr, size_t size);
void arch_reserve_mem_area(unsigned long addr, size_t size);