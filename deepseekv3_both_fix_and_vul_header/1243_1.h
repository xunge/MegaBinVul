#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t u32_t;
typedef uint32_t upx_uint32_t;

struct Elf32_Dyn {
    int32_t d_tag;
    uint32_t d_val;
    static const int DT_NULL = 0;
    static const int DT_NEEDED = 1;
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

struct PackLinuxElf32 {
    void invert_pt_dynamic(Elf32_Dyn const *dynp);
};

static const unsigned DT_NUM = 0x6000000d;

unsigned dt_table[DT_NUM];
unsigned upx_dt_init;
unsigned strtab_end;
unsigned symnum_end;
unsigned const *hashtab;
unsigned const *gashtab;
unsigned e_shnum;
struct Elf32_Ehdr ehdri;
const unsigned char *file_image;
unsigned file_size;

uint32_t get_te32(const void *p);
uint16_t get_te16(const void *p);
unsigned elf_unsigned_dynamic(int tag);
void *elf_find_dynamic(int tag);
void throwCantPack(const char *msg);