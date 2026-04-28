#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Dwarf_Debug_s *Dwarf_Debug;
typedef unsigned char Dwarf_Bool;

struct Dwarf_Line_Registers_s {
    uint64_t lr_address;
    unsigned lr_op_index;
    unsigned long lr_line;
    unsigned lr_isa;
    int lr_basic_block;
    int lr_end_sequence;
    unsigned long lr_file;
    unsigned long lr_column;
    unsigned lr_discriminator;
    int lr_prologue_end;
    int lr_epilogue_begin;
    int lr_is_stmt;
    unsigned lr_call_context;
    unsigned lr_subprogram;
};

typedef struct dwarfstring_s dwarfstring;

struct dwarfstring_s {
    char *s_data;
    size_t s_size;
    size_t s_avail;
    char s_stack[100];
    unsigned s_malloc:1;
};

#define DW_PR_XZEROS "0"
#define DW_PR_DUx "llx"

extern void dwarfstring_constructor_static(dwarfstring *str, char *buf, size_t size);
extern void dwarfstring_append_printf_s(dwarfstring *str, const char *format, char *value);
extern void dwarfstring_append_printf_i(dwarfstring *str, const char *format, int value);
extern void dwarfstring_append_printf_u(dwarfstring *str, const char *format, unsigned long value);
extern void dwarfstring_append(dwarfstring *str, const char *s);
extern char *dwarfstring_string(dwarfstring *str);
extern void dwarfstring_destructor(dwarfstring *str);
extern void _dwarf_printf(Dwarf_Debug dbg, const char *msg);

static char locallinebuf[100];