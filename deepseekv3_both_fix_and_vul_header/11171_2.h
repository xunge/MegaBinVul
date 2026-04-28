#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef uint8_t ut8;
typedef uint64_t ut64;

typedef struct Sdb Sdb;

typedef struct {
    size_t length;
    size_t capacity;
} RBinDwarfCompUnitHeader;

typedef struct RBinDwarfAttrValue {
    int name;
    union {
        struct {
            const char *string;
        } str_struct;
    } encoding;
} RBinDwarfAttrValue;

typedef struct RBinDwarfAttrSpec {
    unsigned int name;
    unsigned int form;
} RBinDwarfAttrSpec;

typedef struct RBinDwarfAbbrevDecl {
    unsigned int tag;
    size_t length;
    size_t capacity;
    RBinDwarfAttrSpec *specs;
} RBinDwarfAbbrevDecl;

typedef struct {
    size_t length;
    size_t capacity;
    RBinDwarfAbbrevDecl *decls;
} RBinDwarfDebugAbbrev;

typedef struct RBinDwarfDie {
    ut64 abbrev_code;
    unsigned int tag;
    size_t length;
    size_t capacity;
    RBinDwarfAttrValue *attr_values;
} RBinDwarfDie;

typedef struct {
    RBinDwarfCompUnitHeader hdr;
    size_t length;
    size_t capacity;
    RBinDwarfDie *dies;
} RBinDwarfCompUnit;

#define DW_AT_comp_dir 0

void r_bin_dwarf_expand_cu(RBinDwarfCompUnit *cu);
void r_bin_dwarf_init_die(RBinDwarfDie *die);
void r_bin_dwarf_expand_die(RBinDwarfDie *die);
const ut8 *r_uleb128(const ut8 *buf, size_t len, ut64 *v);
const ut8 *r_bin_dwarf_parse_attr_value(const ut8 *buf, size_t buf_len, RBinDwarfAttrSpec *spec, RBinDwarfAttrValue *val, RBinDwarfCompUnitHeader *hdr, const ut8 *debug_str, size_t debug_str_len);
void eprintf(const char *fmt, ...);
void sdb_set(Sdb *s, const char *key, const char *val, int cas);