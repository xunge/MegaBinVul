#include <stdint.h>
#include <stdio.h>

#define DT_NUM 0x6000000d

typedef uint64_t upx_uint64_t;
typedef uint32_t u64_t;

struct Elf64_Dyn {
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
    int64_t d_tag;
    uint64_t d_val;
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

extern unsigned dt_table[];
extern unsigned upx_dt_init;
extern unsigned strtab_end;
extern unsigned symnum_end;
extern unsigned const *hashtab;
extern unsigned const *gashtab;
extern unsigned file_size;
extern void *file_image;
extern unsigned e_shnum;
extern struct Elf64_Ehdr ehdri;

unsigned elf_unsigned_dynamic(unsigned tag);
void *elf_find_dynamic(unsigned tag);
uint64_t get_te64(const void *);
uint32_t get_te32(const void *);
uint16_t get_te16(const void *);
void throwCantPack(const char *msg);

class PackLinuxElf64 {
public:
    void invert_pt_dynamic(Elf64_Dyn const *dynp);
};