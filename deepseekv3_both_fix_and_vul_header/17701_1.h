#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32_t;
typedef uint32_t upx_uint32_t;

struct Elf32_Dyn {
    int32_t d_tag;
    uint32_t d_val;
    static const int DT_NULL = 0;
    static const int DT_INIT = 12;
    static const int DT_PREINIT_ARRAY = 32;
    static const int DT_INIT_ARRAY = 25;
    static const int DT_STRSZ = 10;
    static const int DT_SYMTAB = 6;
    static const int DT_STRTAB = 5;
    static const int DT_SYMENT = 11;
    static const int DT_HASH = 4;
    static const int DT_GNU_HASH = 0x6ffffef5;
};

struct Elf64_Dyn {
    int64_t d_tag;
    uint64_t d_val;
    static const int DT_HASH = 4;
};

struct Elf32_Sym {
    uint32_t st_name;
    uint32_t st_value;
    uint32_t st_size;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
};

struct Elf32_Ehdr {
    uint16_t e_shstrndx;
};

class PackLinuxElf32 {
public:
    static unsigned dt_table[];
    static unsigned upx_dt_init;
    static unsigned strtab_end;
    static unsigned symnum_end;
    static unsigned const *hashtab;
    static unsigned const *gashtab;
    static unsigned e_shnum;
    static unsigned file_size;
    static void *file_image;
    static Elf32_Ehdr ehdri;
    static const int DT_NUM = 34;

    static void invert_pt_dynamic(Elf32_Dyn const *dynp);
};

uint32_t get_te32(const void *);
uint16_t get_te16(const void *);
unsigned elf_unsigned_dynamic(int);
void *elf_find_dynamic(int);
void throwCantPack(const char *);