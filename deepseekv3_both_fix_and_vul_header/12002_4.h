#include <stdlib.h>
#include <string.h>

typedef struct bfd bfd;
typedef unsigned long bfd_vma;

struct asymbol {
    const char *name;
    bfd *the_bfd;
    unsigned int flags;
    void *section;
    bfd_vma value;
    union {
        void *p;
    } udata;
};

struct bfd_mach_o_symtab_command {
    struct {
        struct asymbol symbol;
    } *symbols;
    unsigned long nsyms;
    char *strtab;
    unsigned long strsize;
};

struct bfd_mach_o_dysymtab_command {
    unsigned long nindirectsyms;
    unsigned int *indirect_syms;
};

struct bfd_mach_o_section {
    unsigned long flags;
    unsigned int reserved1;
    bfd_vma addr;
    struct asymbol *bfdsection;
};

struct bfd_mach_o_data_struct {
    struct bfd_mach_o_dysymtab_command *dysymtab;
    struct bfd_mach_o_symtab_command *symtab;
    unsigned long nsects;
    struct bfd_mach_o_section **sections;
};

#define ATTRIBUTE_UNUSED
#define BSF_GLOBAL 0x20
#define BSF_SYNTHETIC 0x100

#define BFD_MACH_O_SECTION_TYPE_MASK 0x000000FF
#define BFD_MACH_O_S_NON_LAZY_SYMBOL_POINTERS 0x00000006
#define BFD_MACH_O_S_LAZY_SYMBOL_POINTERS 0x00000007
#define BFD_MACH_O_S_SYMBOL_STUBS 0x00000008

struct bfd_mach_o_data_struct *bfd_mach_o_get_data(bfd *abfd);
unsigned int bfd_mach_o_section_get_nbr_indirect(bfd *abfd, struct bfd_mach_o_section *sec);
unsigned int bfd_mach_o_section_get_entry_size(bfd *abfd, struct bfd_mach_o_section *sec);
void *bfd_malloc(size_t size);

typedef struct asymbol asymbol;
typedef struct bfd_mach_o_data_struct bfd_mach_o_data_struct;
typedef struct bfd_mach_o_dysymtab_command bfd_mach_o_dysymtab_command;
typedef struct bfd_mach_o_symtab_command bfd_mach_o_symtab_command;
typedef struct bfd_mach_o_section bfd_mach_o_section;