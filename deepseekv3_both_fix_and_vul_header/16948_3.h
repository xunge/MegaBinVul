#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct bfd {
    unsigned int flags;
    uint64_t size;
} bfd;

typedef struct asection {
    uint64_t vma;
    uint64_t size;
} asection;

typedef struct arelent {
    int dummy;
} arelent;

enum dwarf_section_display_enum {
    DEBUG_INFO,
    DEBUG_ABBREV,
    DEBUG_LINE
};

struct dwarf_section {
    char *filename;
    char *start;
    arelent **reloc_info;
    unsigned int num_relocs;
    uint64_t address;
    uint64_t size;
    char *name;
};

struct dwarf_section_display {
    struct dwarf_section section;
    bool relocate;
};

extern struct dwarf_section_display debug_displays[];
extern arelent **syms;

#define EXEC_P 0x1
#define DYNAMIC 0x2

typedef unsigned char bfd_byte;
typedef uint64_t bfd_size_type;

char *bfd_get_filename(bfd *abfd);
uint64_t bfd_section_vma(asection *sec);
uint64_t bfd_section_size(asection *sec);
uint64_t bfd_get_size(bfd *abfd);
void *xmalloc(size_t size);
void free_debug_section(enum dwarf_section_display_enum debug);
bool bfd_simple_get_relocated_section_contents(bfd *abfd, asection *sec, void *start, arelent **syms);
long bfd_get_reloc_upper_bound(bfd *abfd, asection *sec);
long bfd_canonicalize_reloc(bfd *abfd, asection *sec, arelent **relocs, arelent **syms);
bool bfd_get_full_section_contents(bfd *abfd, asection *sec, bfd_byte **contents);
char *sanitize_string(char *str);
bool streq(const char *s1, const char *s2);
#define _(x) x