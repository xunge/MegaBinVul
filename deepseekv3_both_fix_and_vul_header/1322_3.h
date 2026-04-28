#include <stddef.h>
#include <string.h>

typedef struct {
    unsigned st_name;
    unsigned st_value;
} Elf32_Sym;

class PackLinuxElf32 {
public:
    static unsigned get_te32(const void *);
    static const char *get_str_name(unsigned, unsigned);
    int adjABS(Elf32_Sym *sym, unsigned delta);
};

extern char const *abs_symbol_names[];