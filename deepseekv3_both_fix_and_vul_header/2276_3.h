#include <cstdint>
#include <cstdlib>
#include <cstdio>

#define SEEK_SET 0

struct InputFile {
    void seek(long, int);
    void readx(void *, unsigned);
};

struct Elf32_Ehdr {
    enum {
        EI_CLASS = 4,
        EI_DATA = 5,
        ELFCLASS32 = 1,
        ELFDATA2LSB = 1,
        ELFDATA2MSB = 2,
        ET_DYN = 3
    };
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint16_t e_phentsize;
};

struct Elf32_Phdr {
    enum { PT_DYNAMIC = 2 };
    uint32_t p_type;
    uint32_t p_offset;
};

struct Elf32_Shdr {
    enum { SHT_DYNSYM = 11 };
    uint32_t sh_link;
};

struct Elf32_Dyn {
    enum { DT_STRTAB = 5, DT_SYMTAB = 6, DT_GNU_HASH = 0x6ffffef5, DT_HASH = 4 };
};

struct Elf32_Sym {
    uint32_t st_value;
};

struct N_BELE_RTP {
    static const int be_policy;
    static const int le_policy;
};

struct PackLinuxElf32 {
    uint16_t e_type;
    uint16_t e_phnum;
    uint16_t e_shnum;
    uint32_t e_phoff;
    uint32_t e_shoff;
    unsigned sz_phdrs;
    unsigned long file_size;
    unsigned char *file_image;
    Elf32_Phdr *phdri;
    const Elf32_Shdr *shdri;
    const Elf32_Shdr *sec_dynsym;
    const Elf32_Shdr *sec_dynstr;
    const Elf32_Dyn *dynseg;
    const char *dynstr;
    const Elf32_Sym *dynsym;
    const unsigned *gashtab;
    const unsigned *hashtab;
    const Elf32_Sym *jni_onload_sym;
    uint32_t jni_onload_va;
    void *bele;
    Elf32_Ehdr ehdri;

    void PackLinuxElf32help1(InputFile *f);
};

uint16_t get_te16(const void *);
uint32_t get_te32(const void *);
void throwCantUnpack(const char *);
void alloc_file_image(unsigned char *&, unsigned);
const Elf32_Shdr *elf_find_section_type(int);
const void *elf_find_dynamic(int);
const Elf32_Sym *elf_lookup(const char *);