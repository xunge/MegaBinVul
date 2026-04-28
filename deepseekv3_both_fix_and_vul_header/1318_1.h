#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32_t;

struct PackLinuxElf32 {
    static unsigned check_pt_dynamic(const struct Elf32_Phdr *phdr);
};

struct Elf32_Phdr {
    uint32_t p_type;
    uint32_t p_offset;
    uint32_t p_vaddr;
    uint32_t p_paddr;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
};

struct Elf32_Dyn {
    int32_t d_tag;
    union {
        uint32_t d_val;
        uint32_t d_ptr;
    } d_un;
};

struct Elf32_Ehdr {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};

extern unsigned long file_size;
extern const struct Elf32_Phdr *phdri;
extern unsigned sz_dynseg;

unsigned get_te32(const void *);
void throwCantPack(const char *);