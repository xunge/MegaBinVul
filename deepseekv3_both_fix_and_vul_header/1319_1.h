#include <stdint.h>
#include <stdio.h>

typedef uint64_t upx_uint64_t;

typedef struct {
    uint64_t p_type;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_flags;
    uint64_t p_align;
} Elf64_Phdr;

typedef struct {
    int64_t d_tag;
    union {
        uint64_t d_val;
        uint64_t d_ptr;
    } d_un;
} Elf64_Dyn;

typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

struct PackLinuxElf64 {
    static unsigned long file_size;
    static Elf64_Phdr const *phdri;
    static upx_uint64_t sz_dynseg;
    static upx_uint64_t check_pt_dynamic(Elf64_Phdr const *const phdr);
};

upx_uint64_t get_te64(const void *p);
void throwCantPack(const char *msg);