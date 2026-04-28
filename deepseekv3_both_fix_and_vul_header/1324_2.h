#include <stdint.h>
#include <stdio.h>

typedef uint64_t upx_uint64_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;

#define DT_NUM 34

struct Elf64_Dyn {
    enum {
        DT_NULL = 0,
        DT_NEEDED = 1,
        DT_PLTRELSZ = 2,
        DT_PLTGOT = 3,
        DT_HASH = 4,
        DT_STRTAB = 5,
        DT_SYMTAB = 6,
        DT_RELA = 7,
        DT_RELASZ = 8,
        DT_RELAENT = 9,
        DT_STRSZ = 10,
        DT_SYMENT = 11,
        DT_INIT = 12,
        DT_FINI = 13,
        DT_SONAME = 14,
        DT_RPATH = 15,
        DT_SYMBOLIC = 16,
        DT_REL = 17,
        DT_RELSZ = 18,
        DT_RELENT = 19,
        DT_PLTREL = 20,
        DT_DEBUG = 21,
        DT_TEXTREL = 22,
        DT_JMPREL = 23,
        DT_BIND_NOW = 24,
        DT_INIT_ARRAY = 25,
        DT_FINI_ARRAY = 26,
        DT_INIT_ARRAYSZ = 27,
        DT_FINI_ARRAYSZ = 28,
        DT_RUNPATH = 29,
        DT_FLAGS = 30,
        DT_PREINIT_ARRAY = 32,
        DT_PREINIT_ARRAYSZ = 33,
        DT_GNU_HASH = 0x6ffffef5
    };
    upx_uint64_t d_tag;
    upx_uint64_t d_val;
};

struct Elf64_Sym {
    uint32_t st_name;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
    upx_uint64_t st_value;
    upx_uint64_t st_size;
};

struct Elf64_Ehdr {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    upx_uint64_t e_entry;
    upx_uint64_t e_phoff;
    upx_uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};

struct Elf64_Phdr {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
};

struct PackLinuxElf64 {
    unsigned dt_table[DT_NUM];
    unsigned upx_dt_init;
    unsigned strtab_end;
    unsigned symnum_end;
    unsigned const *hashtab;
    unsigned const *gashtab;
    unsigned file_size;
    unsigned e_phnum;
    unsigned e_shnum;
    char *file_image;
    Elf64_Ehdr ehdri;

    upx_uint64_t get_te64(const void *p);
    unsigned get_te32(const void *p);
    unsigned short get_te16(const void *p);
    unsigned elf_unsigned_dynamic(unsigned tag);
    void *elf_find_dynamic(unsigned tag);
    void throwCantPack(const char *msg);
    void invert_pt_dynamic(Elf64_Dyn const *dynp, upx_uint64_t dt_filesz);
    void invert_pt_dynamic(Elf64_Dyn const *dynp);
};