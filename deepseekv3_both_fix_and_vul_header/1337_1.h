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

struct PackLinuxElf32 {
    Elf32_Sym const *elf_lookup(char const *name) const;
};

extern unsigned char const *file_image;
extern unsigned file_size;
extern Elf32_Sym const *dynsym;
extern char const *dynstr;
extern unsigned const *hashtab;
extern unsigned const *gashtab;

unsigned get_te32(void const *);
char const *get_dynsym_name(unsigned, unsigned);
char const *get_str_name(unsigned, unsigned);
unsigned elf_hash(char const *);
unsigned gnu_hash(char const *);
void throwCantPack(char const *);