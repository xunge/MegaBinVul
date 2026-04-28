#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef uint8_t ut8;
typedef uint64_t ut64;

#define UT64_MAX UINT64_MAX

typedef struct {
    // Define RzBinDwarfAttrValue structure members here
    int attr_name;
    int attr_form;
    struct {
        char *content;
    } string;
    int kind;
    union {
        ut64 uconstant;
        ut64 reference;
    };
} RzBinDwarfAttrValue;

typedef struct {
    // Define RzBinDwarfAbbrevDef structure members here
    // Add necessary members
} RzBinDwarfAbbrevDef;

typedef struct {
    size_t count;
    RzBinDwarfAbbrevDef *defs;
} RzBinDwarfAbbrevDecl;

typedef struct {
    // Define RzBinDwarfCompUnitHdr structure members here
    // Add necessary members
} RzBinDwarfCompUnitHdr;

typedef struct {
    RzBinDwarfAttrValue *attr_values;
    size_t count;
} RzBinDwarfDie;

typedef struct {
    // Define HtUP structure here
    // Add necessary members
} HtUP;

typedef struct {
    HtUP *line_info_offset_comp_dir;
} RzBinDwarfDebugInfo;

// DWARF constants
#define DW_AT_comp_dir 0x1b
#define DW_AT_stmt_list 0x10
#define DW_FORM_strp 0xe
#define DW_FORM_string 0x8
#define DW_AT_KIND_CONSTANT 1
#define DW_AT_KIND_REFERENCE 2

// Function prototype
static const ut8 *parse_attr_value(const ut8 *buf, size_t buf_len, RzBinDwarfAbbrevDef *def, RzBinDwarfAttrValue *attr_value, RzBinDwarfCompUnitHdr *hdr, const ut8 *debug_str, size_t debug_str_len, bool big_endian);