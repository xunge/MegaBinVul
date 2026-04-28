#include <stdbool.h>
#include <stdlib.h>

typedef bool bfd_boolean;
#define FALSE false

enum dwarf_section_display_enum {
    DEBUG_INFO,
    DEBUG_ABBREV,
    DEBUG_LINE,
    DEBUG_FRAME,
    DEBUG_STR,
    DEBUG_LOC,
    DEBUG_PUBNAMES,
    DEBUG_PUBTYPES,
    DEBUG_ARANGES,
    DEBUG_RANGES,
    DEBUG_MACINFO,
    DEBUG_MACRO
};

struct dwarf_section {
    const char *name;
    const char *uncompressed_name;
    const char *compressed_name;
};

struct debug_display {
    struct dwarf_section section;
};

extern struct debug_display debug_displays[];

typedef struct {
    unsigned long e_shstrndx;
} Elf_Internal_Ehdr;

typedef struct {
    unsigned long sh_offset;
    unsigned long sh_size;
} Elf_Internal_Shdr;

typedef struct Filedata {
    Elf_Internal_Ehdr file_header;
    Elf_Internal_Shdr *section_headers;
    char *string_table;
    unsigned long string_table_length;
} Filedata;

extern void *section_subset;

extern char *get_data(void *x, void *y, unsigned long offset, int a, unsigned long size, const char *desc);
extern Elf_Internal_Shdr *find_section_in_set(Filedata *filedata, const char *name, void *subset);
extern void free_debug_section(enum dwarf_section_display_enum debug);
extern bfd_boolean load_specific_debug_section(enum dwarf_section_display_enum debug, Elf_Internal_Shdr *sec, void *data);

const char *_(const char *str);