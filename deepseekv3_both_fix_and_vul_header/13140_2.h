#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Elf32_Word;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Off;

typedef struct {
    Elf32_Word    st_name;
    Elf32_Addr    st_value;
    Elf32_Word    st_size;
    unsigned char st_info;
    unsigned char st_other;
    Elf32_Half    st_shndx;
} Elf32_Sym;

class PackLinuxElf32 {
public:
    unsigned *hashtab;
    unsigned *gashtab;
    Elf32_Sym *dynsym;
    char *dynstr;
    unsigned file_size;
    char *file_image;

    static unsigned get_te32(void const *);
    static unsigned elf_hash(char const *);
    static unsigned gnu_hash(char const *);
    char const *get_dynsym_name(unsigned, unsigned) const;
    char const *get_str_name(unsigned, unsigned) const;
    void throwCantPack(char const *) const;
    Elf32_Sym const *elf_lookup(char const *name) const;
};