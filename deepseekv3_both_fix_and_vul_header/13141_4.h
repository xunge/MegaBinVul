#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef uint64_t upx_uint64_t;

typedef struct {
    uint32_t st_name;
    uint8_t  st_info;
    uint8_t  st_other;
    uint16_t st_shndx;
    uint64_t st_value;
    uint64_t st_size;
} Elf64_Sym;

struct PackLinuxElf64 {
    unsigned *hashtab;
    Elf64_Sym *dynsym;
    char *dynstr;
    unsigned *gashtab;
    unsigned file_size;
    char *file_image;

    static uint32_t get_te32(const void *p);
    static uint64_t get_te64(const void *p);
    static unsigned elf_hash(const char *name);
    static unsigned gnu_hash(const char *name);
    const char *get_dynsym_name(unsigned si, unsigned max) const;
    const char *get_str_name(unsigned st_name, unsigned max) const;
    static void throwCantPack(const char *msg);
    Elf64_Sym const *elf_lookup(char const *name) const;
};