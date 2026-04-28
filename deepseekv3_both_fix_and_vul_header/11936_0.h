#include <stddef.h>
#include <limits.h>

typedef long bfd_size_type;
typedef struct bfd bfd;
typedef struct asection asection;
typedef struct arelent arelent;

struct bfd {
    asection *sections;
};

struct asection {
    size_t size;
    asection *next;
    void *used_by_bfd;
};

struct elf_section_data {
    struct {
        unsigned int sh_link;
        unsigned int sh_type;
        size_t sh_entsize;
    } this_hdr;
};

#define SHT_REL 9
#define SHT_RELA 4

enum bfd_error {
    bfd_error_invalid_operation,
    bfd_error_file_too_big
};

void bfd_set_error(enum bfd_error error);

static inline struct elf_section_data *elf_section_data(asection *s) {
    return (struct elf_section_data *)s->used_by_bfd;
}

static inline unsigned int elf_dynsymtab(bfd *abfd) {
    (void)abfd;
    return 0;
}