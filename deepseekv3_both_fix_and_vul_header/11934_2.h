#include <stddef.h>
#include <limits.h>

typedef struct bfd bfd;
typedef unsigned long bfd_size_type;
typedef struct asymbol asymbol;

typedef struct Elf_Internal_Shdr {
    unsigned long sh_size;
} Elf_Internal_Shdr;

typedef struct elf_tdata {
    Elf_Internal_Shdr symtab_hdr;
} elf_tdata;

typedef struct elf_backend_data {
    struct {
        size_t sizeof_sym;
    } *s;
} elf_backend_data;

enum bfd_error {
    bfd_error_file_too_big
};

void bfd_set_error(enum bfd_error error);

#define elf_tdata(abfd) ((elf_tdata *)(abfd))
#define get_elf_backend_data(abfd) ((elf_backend_data *)(abfd))