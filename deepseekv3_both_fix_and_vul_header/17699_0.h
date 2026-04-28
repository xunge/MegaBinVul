#include <stdint.h>

typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Word;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf32_Off;

struct Elf32_Dyn {
    Elf32_Sword d_tag;
    Elf32_Word d_val;
    static const Elf32_Sword DT_NULL = 0;
};

extern Elf32_Dyn const *dynseg;
extern unsigned sz_dynseg;
extern char const *file_image;
extern unsigned file_size;

class PackLinuxElf32 {
public:
    void const *elf_find_dynamic(unsigned int key) const;
};

unsigned elf_get_offset_from_address(unsigned addr);
uint32_t get_te32(void const *p);