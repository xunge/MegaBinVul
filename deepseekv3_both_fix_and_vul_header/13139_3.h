#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32_t;
typedef uint32_t upx_uint32_t;

#define DT_NUM 34

struct Elf32_Dyn {
    enum {
        DT_NULL = 0,
        DT_NEEDED = 1,
        DT_INIT = 12,
        DT_PREINIT_ARRAY = 32,
        DT_INIT_ARRAY = 25,
        DT_STRSZ = 10,
        DT_SYMTAB = 6,
        DT_STRTAB = 5,
        DT_SYMENT = 11,
        DT_HASH = 4,
        DT_GNU_HASH = 0x6ffffef5
    };
    int32_t d_tag;
    uint32_t d_val;
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
    void invert_pt_dynamic(Elf32_Dyn const *dynp);
};

extern unsigned dt_table[];
extern unsigned upx_dt_init;
extern unsigned strtab_end;
extern unsigned symnum_end;
extern unsigned const *hashtab;
extern unsigned const *gashtab;
extern unsigned e_shnum;
extern unsigned file_size;
extern char *file_image;
extern struct Elf32_Ehdr ehdri;

unsigned get_te16(const void *);
unsigned get_te32(const void *);
unsigned elf_unsigned_dynamic(unsigned);
void *elf_find_dynamic(unsigned);
void throwCantPack(const char *);