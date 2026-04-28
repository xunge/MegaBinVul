#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t Dwarf_Unsigned;
typedef uint8_t Dwarf_Small;
typedef uint16_t Dwarf_Half;
typedef bool Dwarf_Bool;
typedef void* Dwarf_Debug;
typedef struct Dwarf_Line_Context_s* Dwarf_Line_Context;
typedef void* Dwarf_Error;

#define DW_DLV_OK 0
#define DW_DLV_ERROR 1
#define DW_DLE_VERSION_STAMP_ERROR 123
#define DW_PR_DUu "llu"
#define DW_PR_DUx "llx"
#define DW_PR_XZEROS "0"
#define EXPERIMENTAL_LINE_TABLES_VERSION 0

struct Dwarf_Line_Context_s {
    unsigned lc_version_number;
    Dwarf_Unsigned lc_actuals_table_offset;
};

typedef struct dwarfstring {
    char* s;
    size_t len;
    size_t size;
} dwarfstring;

void dwarfstring_constructor(dwarfstring*);
void dwarfstring_destructor(dwarfstring*);
void dwarfstring_reset(dwarfstring*);
char* dwarfstring_string(dwarfstring*);
void dwarfstring_append_printf_u(dwarfstring*, const char*, ...);

void _dwarf_printf(Dwarf_Debug, const char*);
void _dwarf_error(Dwarf_Debug, Dwarf_Error*, int);
void dwarf_srclines_dealloc_b(Dwarf_Line_Context);

int read_line_table_program(Dwarf_Debug, Dwarf_Small*, Dwarf_Small*, Dwarf_Small*, 
                          Dwarf_Small*, Dwarf_Line_Context, Dwarf_Half, Dwarf_Bool, 
                          Dwarf_Bool, Dwarf_Bool, Dwarf_Bool, Dwarf_Error*, int*);
void print_line_header(Dwarf_Debug, Dwarf_Bool, Dwarf_Bool);