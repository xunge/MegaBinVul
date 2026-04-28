#include <stddef.h>

typedef unsigned char Dwarf_Small;
typedef unsigned long long Dwarf_Unsigned;
typedef unsigned short Dwarf_Half;
typedef int Dwarf_Error;

typedef struct Dwarf_Die_s {
    struct Dwarf_CU_Context_s *di_cu_context;
} *Dwarf_Die;

typedef struct Dwarf_Attribute_s *Dwarf_Attribute;
typedef struct Dwarf_Debug_s *Dwarf_Debug;

typedef struct Dwarf_CU_Context_s {
    struct Dwarf_Debug_s *cc_dbg;
} *Dwarf_CU_Context;

typedef struct Dwarf_Line_Context_s {
    Dwarf_Small *lc_line_ptr_end;
    Dwarf_Unsigned lc_actuals_table_offset;
    Dwarf_Small *lc_line_prologue_start;
    unsigned lc_version_number;
    char *lc_compilation_directory;
} *Dwarf_Line_Context;

struct Dwarf_Section_s {
    Dwarf_Small *dss_data;
    Dwarf_Unsigned dss_size;
};

struct Dwarf_Debug_s {
    struct Dwarf_Section_s de_debug_line;
};

#define DW_DLV_ERROR (-1)
#define DW_DLV_OK 0
#define DW_DLV_NO_ENTRY 1

#define DW_AT_stmt_list 0x10
#define DW_AT_comp_dir 0x1b
#define DW_FORM_data4 0x06
#define DW_FORM_data8 0x07
#define DW_FORM_sec_offset 0x17
#define DW_DLA_ATTR 0x01
#define DW_DLA_LINE_CONTEXT 0x02
#define DW_SECT_LINE 0x01
#define DW_DLE_LINE_OFFSET_BAD 1
#define DW_DLE_ALLOC_FAIL 2

#define CHECK_DIE(die, retval) do { } while(0)

int _dwarf_load_section(Dwarf_Debug dbg, struct Dwarf_Section_s *section, Dwarf_Error *error);
Dwarf_Half _dwarf_get_address_size(Dwarf_Debug dbg, Dwarf_Die die);
int dwarf_attr(Dwarf_Die die, Dwarf_Half attr, Dwarf_Attribute *atp, Dwarf_Error *error);
int dwarf_whatform(Dwarf_Attribute attr, Dwarf_Half *formp, Dwarf_Error *error);
void dwarf_dealloc(Dwarf_Debug dbg, void *space, Dwarf_Half type);
void _dwarf_error(Dwarf_Debug dbg, Dwarf_Error *error, int code);
int dwarf_global_formref(Dwarf_Attribute attr, Dwarf_Unsigned *offset, Dwarf_Error *error);
int _dwarf_get_fission_addition_die(Dwarf_Die die, Dwarf_Half sect, Dwarf_Unsigned *offset, Dwarf_Unsigned *size, Dwarf_Error *error);
int dwarf_formstring(Dwarf_Attribute attr, char **stringp, Dwarf_Error *error);
void *_dwarf_get_alloc(Dwarf_Debug dbg, Dwarf_Half type, size_t size);
int _dwarf_read_line_table_header(Dwarf_Debug dbg, Dwarf_CU_Context cu, Dwarf_Small *section_start, Dwarf_Small *line_ptr, Dwarf_Unsigned section_size, Dwarf_Small **newlinep, Dwarf_Line_Context line_context, Dwarf_Small **bogus_bytes_ptr, Dwarf_Unsigned *bogus_bytes_count, Dwarf_Error *error, int *err_count_out);
void dwarf_srclines_dealloc_b(Dwarf_Line_Context line_context);
void do_line_print_now(Dwarf_Debug dbg, unsigned line_version, char *comp_dir, Dwarf_Line_Context line_context);
void print_include_directory_details(Dwarf_Debug dbg, unsigned line_version, Dwarf_Line_Context line_context);
void print_file_entry_details(Dwarf_Debug dbg, unsigned line_version, Dwarf_Line_Context line_context);
void print_experimental_counts(Dwarf_Debug dbg, unsigned line_version, Dwarf_Line_Context line_context);
int print_actuals_and_locals(Dwarf_Debug dbg, Dwarf_Line_Context line_context, Dwarf_Unsigned bogus_bytes_count, Dwarf_Small *bogus_bytes_ptr, Dwarf_Small *orig_line_ptr, Dwarf_Small *line_ptr, Dwarf_Small *section_start, Dwarf_Small *line_ptr_actuals, Dwarf_Small *line_ptr_end, Dwarf_Half address_size, int *err_count_out, Dwarf_Error *error);