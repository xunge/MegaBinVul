#include <stddef.h>
#include <stdio.h>
#include <time.h>

typedef struct Dwarf_Debug_s *Dwarf_Debug;
typedef unsigned long long Dwarf_Unsigned;

struct Dwarf_File_Entry_s {
    char *fi_file_name;
    struct Dwarf_File_Entry_s *fi_next;
    unsigned fi_dir_index_present;
    Dwarf_Unsigned fi_dir_index;
    unsigned fi_time_last_mod_present;
    Dwarf_Unsigned fi_time_last_mod;
    unsigned fi_file_length_present;
    Dwarf_Unsigned fi_file_length;
    unsigned fi_md5_present;
    unsigned char fi_md5_value[16];
};
typedef struct Dwarf_File_Entry_s *Dwarf_File_Entry;

struct Dwarf_Line_Context_s {
    Dwarf_File_Entry lc_file_entries;
    unsigned lc_file_entry_count;
};
typedef struct Dwarf_Line_Context_s *Dwarf_Line_Context;

struct dwarfstring_s {
    char *s_data;
    size_t s_avail;
    size_t s_used;
    unsigned s_malloc;
};
typedef struct dwarfstring_s dwarfstring;

#define dwarfstring_string(ds) ((ds)->s_data)
#define dwarfstring_strlen(ds) ((ds)->s_used)

extern void dwarfstring_constructor_static(dwarfstring *ds, char *buf, size_t len);
extern void dwarfstring_append_printf_i(dwarfstring *ds, const char *format, int val);
extern void dwarfstring_append_printf_u(dwarfstring *ds, const char *format, unsigned val);
extern void dwarfstring_append_printf_s(dwarfstring *ds, const char *format, const char *str);
extern void dwarfstring_append(dwarfstring *ds, const char *str);
extern void dwarfstring_reset(dwarfstring *ds);
extern void dwarfstring_destructor(dwarfstring *ds);
extern void _dwarf_printf(Dwarf_Debug dbg, const char *msg);

static char locallinebuf[1024];