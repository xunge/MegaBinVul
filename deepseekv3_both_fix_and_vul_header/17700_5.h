#include <stddef.h>
#include <stdint.h>

typedef uint64_t upx_uint64_t;

typedef struct Elf64_Dyn {
    int64_t d_tag;
    uint64_t d_val;
    static const int DT_NULL = 0;
} Elf64_Dyn;

extern Elf64_Dyn const *dynseg;
extern unsigned sz_dynseg;
extern upx_uint64_t file_size;
extern const void *file_image;

static inline uint64_t get_te64(const void *p) {
    return *(const uint64_t *)p;
}

upx_uint64_t elf_get_offset_from_address(upx_uint64_t addr);

class PackLinuxElf64 {
public:
    const void *elf_find_dynamic(unsigned int key) const;
};