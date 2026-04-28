#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Off;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Word;

typedef struct {
    Elf32_Word p_type;
    Elf32_Off p_offset;
    Elf32_Addr p_vaddr;
    Elf32_Addr p_paddr;
    Elf32_Word p_filesz;
    Elf32_Word p_memsz;
    Elf32_Word p_flags;
    Elf32_Word p_align;
} Elf32_Phdr;

typedef struct {
    Elf32_Word d_tag;
    union {
        Elf32_Word d_val;
        Elf32_Addr d_ptr;
    } d_un;
} Elf32_Dyn;

struct PackLinuxElf32 {
    unsigned check_pt_dynamic(Elf32_Phdr const *const phdr);
};

extern unsigned get_te32(const void *);
extern off_t file_size;
extern size_t page_size;
extern Elf32_Phdr const *phdri;
extern unsigned sz_dynseg;
extern void throwCantPack(const char *);