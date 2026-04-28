#include <stdint.h>
#include <stdio.h>

typedef uint64_t upx_uint64_t;

typedef struct {
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
} Elf64_Phdr;

typedef struct {
    int64_t d_tag;
    union {
        uint64_t d_val;
        uint64_t d_ptr;
    } d_un;
} Elf64_Dyn;

struct PackLinuxElf64 {
    static upx_uint64_t check_pt_dynamic(Elf64_Phdr const *const phdr);
};

extern upx_uint64_t file_size;
extern upx_uint64_t page_size;
extern upx_uint64_t sz_dynseg;
extern Elf64_Phdr *phdri;

upx_uint64_t get_te64(const void *p);
void throwCantPack(const char *msg);