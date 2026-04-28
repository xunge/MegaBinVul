#include <stdbool.h>
#include <string.h>

typedef struct {
    unsigned int r_info;
} Elf32_Rel;

struct PackLinuxElf32 {
    unsigned int *dynsym;
    char *dynstr;
    unsigned int get_te32(const void *);
    char *get_dynsym_name(unsigned int, unsigned int);
    bool calls_crt1(Elf32_Rel const *rel, int sz);
};