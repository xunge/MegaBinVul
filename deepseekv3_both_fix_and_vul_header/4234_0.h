#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

struct elf_binary {
    uint64_t image_base;
    size_t size;
    uint64_t dest_base;
    size_t dest_size;
    uint64_t xdest_base;
    size_t xdest_size;
    uint64_t caller_xdest_base;
    size_t caller_xdest_size;
};

bool elf_ptrval_in_range(uint64_t ptrval, size_t size, uint64_t base, size_t range_size);
void elf_mark_broken(struct elf_binary *elf, const char *msg);