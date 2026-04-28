#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint64_t upx_uint64_t;

typedef struct {
    unsigned st_name;
    unsigned st_value;
    unsigned st_size;
    unsigned char st_info;
    unsigned char st_other;
    unsigned short st_shndx;
} Elf64_Sym;

class PackLinuxElf64 {
public:
    Elf64_Sym const *elf_lookup(char const *name) const;
    unsigned get_te32(const void *p) const;
    uint64_t get_te64(const void *p) const;
    unsigned elf_hash(const char *name) const;
    unsigned gnu_hash(const char *name) const;
    char const *get_dynsym_name(unsigned si, unsigned max) const;
    char const *get_str_name(unsigned st_name, unsigned max) const;
    void throwCantPack(const char *msg) const;

    unsigned *hashtab;
    unsigned *gashtab;
    Elf64_Sym *dynsym;
    char *dynstr;
    unsigned file_size;
    unsigned char *file_image;
};