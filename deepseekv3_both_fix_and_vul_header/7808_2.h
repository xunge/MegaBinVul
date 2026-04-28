#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long ram_addr_t;

struct uc_struct {
    unsigned int qemu_real_host_page_size;
    int invalid_addr;
    int invalid_error;
};

typedef struct MemoryRegion MemoryRegion;

struct MemoryRegion {
    struct uc_struct *uc;
};

typedef struct RAMBlock {
    MemoryRegion *mr;
    ram_addr_t used_length;
    ram_addr_t max_length;
    ram_addr_t page_size;
    void *host;
    unsigned int flags;
} RAMBlock;

#define RAM_PREALLOC 0
#define UC_ERR_OK 0

void *g_malloc0(size_t size);
void g_free(void *ptr);
void ram_block_add(struct uc_struct *uc, RAMBlock *block);

#define HOST_PAGE_ALIGN(uc, size) ((size) + (uc)->qemu_real_host_page_size - 1) & ~((uc)->qemu_real_host_page_size - 1)