#include <elf.h>
#include <string.h>

class PackLinuxElf64 {
public:
    static unsigned get_te32(const void *);
    static const char *get_str_name(unsigned, unsigned);
    int adjABS(Elf64_Sym *sym, unsigned delta);
};

extern char const *abs_symbol_names[];