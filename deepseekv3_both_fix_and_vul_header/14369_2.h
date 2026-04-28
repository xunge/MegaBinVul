#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct MemoryRegion MemoryRegion;
typedef struct RAMBlock RAMBlock;
typedef struct uc_struct uc_struct;

struct MemoryRegion {
    uint64_t addr;
    uint64_t end;
    uint32_t perms;
    void *size;
};

struct RAMBlock {
    MemoryRegion *mr;
    uint64_t offset;
    size_t used_length;
    uint8_t *host;
    uint32_t flags;
    RAMBlock *next;
};

struct uc_struct {
    struct {
        RAMBlock *blocks;
    } ram_list;
};

#define QLIST_FOREACH(var, head, field) \
    for ((var) = (head); (var); (var) = (var)->field)

uint64_t int128_get64(void *v);
uint8_t *copy_region(uc_struct *uc, MemoryRegion *mr);
int uc_mem_unmap(uc_struct *uc, uint64_t address, size_t size);
int uc_mem_map(uc_struct *uc, uint64_t address, size_t size, uint32_t perms);
int uc_mem_write(uc_struct *uc, uint64_t address, const void *bytes, size_t size);
int uc_mem_map_ptr(uc_struct *uc, uint64_t address, size_t size, uint32_t perms, void *ptr);

#define UC_ERR_OK 0