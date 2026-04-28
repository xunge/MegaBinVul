#include <stddef.h>
#include <stdbool.h>
#include <string.h>

typedef unsigned char ut8;
typedef unsigned long long ut64;

typedef struct {
    int attr_form;
    int attr_name;
    union {
        char *content;
        ut64 u64;
    } string;
} RBinDwarfAttrValue;

typedef struct {
    int count;
    int capacity;
    RBinDwarfAttrValue *attr_values;
} RBinDwarfDie;

typedef struct {
    int count;
    void *defs;
} RBinDwarfAbbrevDecl;

typedef struct {
    // Add necessary fields for RBinDwarfCompUnitHdr
} RBinDwarfCompUnitHdr;

typedef struct Sdb {
    // Add necessary fields for Sdb
} Sdb;

#define DW_FORM_strp 0
#define DW_FORM_string 0
#define DW_AT_comp_dir 0

static const ut8 *parse_attr_value(const ut8 *buf, size_t buf_len, void *def, RBinDwarfAttrValue *attr, RBinDwarfCompUnitHdr *hdr, const ut8 *debug_str, size_t debug_str_len);