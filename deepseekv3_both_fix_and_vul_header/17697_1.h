#include <stdint.h>
#include <stdio.h>

typedef uint64_t upx_uint64_t;
typedef uint64_t u64_t;

#define DT_NUM 36

struct Elf64_Dyn {
    int64_t d_tag;
    uint64_t d_val;
    static const unsigned DT_NULL = 0;
    static const unsigned DT_INIT = 12;
    static const unsigned DT_PREINIT_ARRAY = 32;
    static const unsigned DT_INIT_ARRAY = 25;
    static const unsigned DT_STRSZ = 10;
    static const unsigned DT_SYMTAB = 6;
    static const unsigned DT_STRTAB = 5;
    static const unsigned DT_SYMENT = 11;
    static const unsigned DT_HASH = 4;
    static const unsigned DT_GNU_HASH = 0x6ffffef5;
};

struct Elf64_Sym {
    uint32_t st_name;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
    uint64_t st_value;
    uint64_t st_size;
};

struct Elf64_Ehdr {
    uint16_t e_shstrndx;
};

class PackLinuxElf64 {
public:
    static unsigned dt_table[];
    static unsigned upx_dt_init;
    static unsigned strtab_end;
    static unsigned symnum_end;
    static unsigned e_shnum;
    static unsigned file_size;
    static unsigned char *file_image;
    static unsigned const *hashtab;
    static unsigned const *gashtab;
    static Elf64_Ehdr ehdri;

    static void invert_pt_dynamic(Elf64_Dyn const *dynp);
};

unsigned PackLinuxElf64::dt_table[DT_NUM];
unsigned PackLinuxElf64::upx_dt_init;
unsigned PackLinuxElf64::strtab_end;
unsigned PackLinuxElf64::symnum_end;
unsigned PackLinuxElf64::e_shnum;
unsigned PackLinuxElf64::file_size;
unsigned char *PackLinuxElf64::file_image;
unsigned const *PackLinuxElf64::hashtab;
unsigned const *PackLinuxElf64::gashtab;
Elf64_Ehdr PackLinuxElf64::ehdri;

unsigned elf_unsigned_dynamic(unsigned tag);
void *elf_find_dynamic(unsigned tag);
uint64_t get_te64(const void *p);
uint32_t get_te32(const void *p);
uint16_t get_te16(const void *p);
void throwCantPack(const char *msg);