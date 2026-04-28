#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef unsigned char ut8;

typedef struct Sdb Sdb;

typedef struct RBinDwarfAbbrevDef {
    // Placeholder for abbrev def structure
} RBinDwarfAbbrevDef;

typedef struct RBinDwarfAbbrevDecl {
    size_t count;
    RBinDwarfAbbrevDef *defs;
} RBinDwarfAbbrevDecl;

typedef struct RBinDwarfCompUnitHdr {
    // Placeholder for comp unit header
} RBinDwarfCompUnitHdr;

typedef struct RBinDwarfString {
    const char *content;
} RBinDwarfString;

typedef struct RBinDwarfAttrValue {
    unsigned int attr_form;
    unsigned int attr_name;
    RBinDwarfString string;
} RBinDwarfAttrValue;

typedef struct RBinDwarfDie {
    RBinDwarfAttrValue *attr_values;
    size_t count;
} RBinDwarfDie;

static const ut8 *parse_attr_value(const ut8 *buf, size_t buf_len, RBinDwarfAbbrevDef *def, 
                                  RBinDwarfAttrValue *attr_val, RBinDwarfCompUnitHdr *hdr, 
                                  const ut8 *debug_str, size_t debug_str_len);

void sdb_set(Sdb *sdb, const char *key, const char *val, int cas);

#define DW_FORM_strp 0x10
#define DW_FORM_string 0x8
#define DW_AT_comp_dir 0x1b