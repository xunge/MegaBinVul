#include <stdlib.h>

typedef struct bfd bfd;

struct abbrev_info {
    struct abbrev_info *next;
    void *attrs;
};

struct funcinfo {
    char *file;
    char *caller_file;
    struct funcinfo *prev_func;
};

struct varinfo {
    char *file;
    struct varinfo *prev_var;
};

struct line_table {
    void *dirs;
    void *files;
};

struct comp_unit {
    struct abbrev_info **abbrevs;
    struct funcinfo *function_table;
    struct varinfo *variable_table;
    struct line_table *line_table;
    void *lookup_funcinfo_table;
    struct comp_unit *next_unit;
};

struct bfd_hash_table {
    void *base;
};

struct bfd_hash_table_entry {
    struct bfd_hash_table base;
};

struct dwarf2_debug {
    struct comp_unit *all_comp_units;
    struct bfd_hash_table_entry *funcinfo_hash_table;
    struct bfd_hash_table_entry *varinfo_hash_table;
    void *dwarf_abbrev_buffer;
    void *dwarf_line_buffer;
    void *dwarf_str_buffer;
    void *dwarf_line_str_buffer;
    void *dwarf_ranges_buffer;
    void *info_ptr_memory;
    bfd *bfd_ptr;
    int close_on_cleanup;
    void *alt_dwarf_str_buffer;
    void *alt_dwarf_info_buffer;
    void *sec_vma;
    void *adjusted_sections;
    bfd *alt_bfd_ptr;
};

#define ABBREV_HASH_SIZE 1