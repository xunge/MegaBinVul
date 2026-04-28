#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint32_t st_name;
} Elf64_Sym;

typedef struct {
    uint64_t r_info;
} Elf64_Rela;

struct PackLinuxElf64 {
    Elf64_Sym *dynsym;
    char *dynstr;
    
    bool calls_crt1(Elf64_Rela const *rela, int sz);
};

static inline uint32_t get_te32(const void *p) {
    return *(const uint32_t *)p;
}

static inline uint64_t get_te64(const void *p) {
    return *(const uint64_t *)p;
}