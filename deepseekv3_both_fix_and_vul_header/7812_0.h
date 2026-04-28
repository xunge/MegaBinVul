#include <stdlib.h>
#include <stdint.h>

typedef uint64_t hwaddr;

struct MemoryRegion {
    hwaddr addr;
    void *ram_block;
};

struct uc_struct {
    void *system_memory;
    void *cpu;
};

typedef struct MemoryRegion MemoryRegion;

void memory_region_init_ram(struct uc_struct *uc, MemoryRegion *ram, size_t size, uint32_t perms);
void memory_region_add_subregion(void *system_memory, hwaddr begin, MemoryRegion *ram);
void tlb_flush(void *cpu);
void g_free(void *ptr);

#define g_new(type, count) ((type *)malloc(sizeof(type) * (count)))
#define g_free(ptr) free(ptr)