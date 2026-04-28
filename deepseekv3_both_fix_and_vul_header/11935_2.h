#include <limits.h>

typedef struct bfd bfd;
typedef struct asymbol asymbol;
typedef unsigned long bfd_size_type;

struct Elf_Internal_Shdr {
    unsigned long sh_size;
};

struct elf_backend_data {
    struct {
        unsigned int sizeof_sym;
    } *s;
};

struct elf_tdata {
    struct Elf_Internal_Shdr dynsymtab_hdr;
};

enum bfd_error {
    bfd_error_invalid_operation,
    bfd_error_file_too_big
};

static inline struct elf_tdata* elf_tdata(bfd* abfd) { return (struct elf_tdata*)0; }
static inline unsigned long elf_dynsymtab(bfd* abfd) { return 0; }
static inline struct elf_backend_data* get_elf_backend_data(bfd* abfd) { return (struct elf_backend_data*)0; }
static inline void bfd_set_error(enum bfd_error error) {}

#define Elf_Internal_Shdr struct Elf_Internal_Shdr