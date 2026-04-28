#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int bfd_boolean;
typedef unsigned char bfd_byte;
typedef unsigned long bfd_size_type;
typedef struct bfd bfd;
typedef struct asection asection;
typedef struct arelent arelent;

enum dwarf_section_display_enum {
    /* dummy value */
    DEBUG_INFO
};

struct dwarf_section {
    const char *filename;
    arelent **reloc_info;
    unsigned long num_relocs;
    bfd_byte *start;
    unsigned long address;
    bfd_size_type size;
    void *user_data;
    const char *name;
};

struct dwarf_display {
    struct dwarf_section section;
    bfd_boolean relocate;
};

extern struct dwarf_display debug_displays[];
extern bfd_boolean is_relocatable;
extern void *syms;

static inline int streq(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}

void free_debug_section(enum dwarf_section_display_enum debug);
const char *bfd_get_filename(bfd *abfd);
unsigned long bfd_get_section_vma(bfd *abfd, asection *sec);
bfd_size_type bfd_get_section_size(asection *sec);
bfd_boolean bfd_get_full_section_contents(bfd *abfd, asection *sec, bfd_byte **contents);
void bfd_cache_section_contents(asection *sec, bfd_byte *contents);
void *bfd_simple_get_relocated_section_contents(bfd *abfd, asection *sec, bfd_byte *contents, void *syms);
long bfd_get_reloc_upper_bound(bfd *abfd, asection *sec);
unsigned long bfd_canonicalize_reloc(bfd *abfd, asection *sec, arelent **relocs, void *symbols);
void *xmalloc(size_t size);

#define _(x) x