#include <stdio.h>
#include <stddef.h>
#include <elf.h>

typedef enum { FALSE, TRUE } bfd_boolean;

typedef struct {
    Elf32_Word st_name;
    Elf32_Addr st_value;
    unsigned char st_info;
} Elf_Internal_Sym;

typedef struct {
    Elf32_Word sh_type;
    Elf32_Word sh_link;
    Elf32_Off sh_offset;
    Elf32_Word sh_size;
} Elf_Internal_Shdr;

extern Elf_Internal_Shdr section_headers[];
extern Elf32_Ehdr elf_header;
extern void *get_data(void *x, FILE *file, Elf32_Off offset, int a, Elf32_Word size, const char *msg);

#define GET_ELF_SYMBOLS(file, symsec, nsyms) NULL
#define _(x) x
#define ELF_ST_TYPE(info) ELF32_ST_TYPE(info)
#define ELF_ST_BIND(info) ELF32_ST_BIND(info)