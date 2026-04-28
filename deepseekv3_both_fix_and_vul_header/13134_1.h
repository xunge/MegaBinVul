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
    Elf32_Sym const *elf_lookup(char const *name) const;
private:
    unsigned get_te32(void const *p) const;
    char const *get_dynsym_name(unsigned si, unsigned max) const;
    char const *get_str_name(unsigned st_name, unsigned max) const;
    unsigned elf_hash(char const *name) const;
    unsigned gnu_hash(char const *name) const;
    void throwCantPack(char const *msg) const;

    unsigned *hashtab;
    unsigned *gashtab;
    Elf32_Sym *dynsym;
    char *dynstr;
    unsigned file_size;
    char *file_image;
};