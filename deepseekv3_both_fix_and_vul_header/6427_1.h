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
} RBinDwarfCompUnitHdr;

typedef struct {
    int name;
    union {
        struct {
            const char *string;
        } str_struct;
    } encoding;
} RBinDwarfAttrValue;

typedef struct {
    int tag;
    size_t length;
    size_t capacity;
    void *specs;
} RBinDwarfAbbrevDecl;

typedef struct {
    ut64 abbrev_code;
    int tag;
    size_t length;
    size_t capacity;
    RBinDwarfAttrValue *attr_values;
} RBinDwarfDie;

typedef struct {
    size_t length;
    size_t capacity;
    RBinDwarfAbbrevDecl *decls;
} RBinDwarfDebugAbbrev;

typedef struct {
    RBinDwarfCompUnitHdr hdr;
    size_t length;
    size_t capacity;
    RBinDwarfDie *dies;
} RBinDwarfCompUnit;

#define DW_AT_comp_dir 0

void r_bin_dwarf_expand_cu(RBinDwarfCompUnit *cu);
void r_bin_dwarf_init_die(RBinDwarfDie *die);
void r_bin_dwarf_expand_die(RBinDwarfDie *die);
const ut8 *r_uleb128(const ut8 *buf, size_t len, ut64 *v);
const ut8 *r_bin_dwarf_parse_attr_value(const ut8 *buf, size_t buf_len, void *spec, RBinDwarfAttrValue *attr, RBinDwarfCompUnitHdr *hdr, const ut8 *debug_str, size_t debug_str_len);
void eprintf(const char *format, ...);
void sdb_set(Sdb *s, const char *key, const char *val, int cas);