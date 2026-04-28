#include <stdbool.h>
#include <string.h>

typedef struct {
    unsigned int st_name;
} Elf32_Sym;

typedef struct {
    unsigned int r_info;
} Elf32_Rel;

extern Elf32_Sym *dynsym;
extern char *dynstr;

unsigned int get_te32(const void *);

struct PackLinuxElf32 {
    bool calls_crt1(Elf32_Rel const *rel, int sz);
};