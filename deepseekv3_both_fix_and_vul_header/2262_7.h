#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } bfd_boolean;
typedef unsigned char bfd_byte;
typedef size_t bfd_size_type;

struct asection {
    bfd_size_type rawsize;
    bfd_size_type size;
};

struct asymbol;

struct dwarf1_debug {
    void *abfd;
    bfd_byte *line_section;
    bfd_byte *line_section_end;
    struct asymbol **syms;
};

struct dwarf1_unit {
    uint32_t stmt_list_offset;
    uint32_t line_count;
    struct linenumber *linenumber_table;
};

struct linenumber {
    uint32_t linenumber;
    uint32_t addr;
};

static struct asection *bfd_get_section_by_name(void *abfd, const char *name) {
    static struct asection section;
    return &section;
}

static bfd_byte *bfd_simple_get_relocated_section_contents(void *abfd, struct asection *sec, void *unused, struct asymbol **syms) {
    static bfd_byte contents[1024];
    return contents;
}

static uint32_t bfd_get_32(void *abfd, const bfd_byte *addr) {
    return *(const uint32_t *)addr;
}

static void *bfd_alloc(void *abfd, bfd_size_type size) {
    return malloc(size);
}

#define asection struct asection