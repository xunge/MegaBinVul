#include <stdbool.h>
#include <string.h>

typedef struct {
    unsigned long r_info;
} Elf64_Rela;

extern Elf64_Rela *dynsym;
extern char *dynstr;

struct PackLinuxElf64 {
    bool calls_crt1(Elf64_Rela const *rela, int sz);
};

unsigned long get_te64(const void *);
char *get_dynsym_name(unsigned, unsigned);