#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define DW_LINE_VERSION5 5
#define DW_DLV_OK 0
#define DW_PR_XZEROS "0"
#define DW_PR_DUx "x"

typedef unsigned long Dwarf_Unsigned;
typedef struct Dwarf_Debug_s *Dwarf_Debug;

struct Dwarf_Unsigned_Pair_s {
    Dwarf_Unsigned up_first;
    Dwarf_Unsigned up_second;
};

struct Dwarf_Line_Context_s {
    unsigned int lc_directory_entry_format_count;
    struct Dwarf_Unsigned_Pair_s *lc_directory_format_values;
    Dwarf_Unsigned lc_include_directories_count;
    char **lc_include_directories;
};
typedef struct Dwarf_Line_Context_s *Dwarf_Line_Context;

typedef struct dwarfstring_s dwarfstring;
struct dwarfstring_s {
    char *ds_data;
    size_t ds_allocated;
    size_t ds_strlen;
    char ds_stack[100];
};

extern int dwarf_get_LNCT_name(Dwarf_Unsigned, const char **);
extern int dwarf_get_FORM_name(Dwarf_Unsigned, const char **);
extern void _dwarf_printf(Dwarf_Debug, const char *);
extern void dwarfstring_constructor_static(dwarfstring *, char *, size_t);
extern void dwarfstring_constructor(dwarfstring *);
extern void dwarfstring_append_printf_u(dwarfstring *, const char *, ...);
extern void dwarfstring_append_printf_s(dwarfstring *, const char *, ...);
extern void dwarfstring_append_printf_i(dwarfstring *, const char *, ...);
extern void dwarfstring_reset(dwarfstring *);
extern void dwarfstring_destructor(dwarfstring *);
extern char *dwarfstring_string(dwarfstring *);

static char locallinebuf[100];