#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define PFMT64x "llx"
#define PFMT64u "llu"

typedef struct RBinDwarfDebugInfo RBinDwarfDebugInfo;
typedef struct RBinDwarfDIE RBinDwarfDIE;
typedef struct RBinDwarfAttrValue RBinDwarfAttrValue;

struct RBinDwarfDebugInfo {
    size_t length;
    struct {
        uint64_t offset;
        struct {
            uint32_t length;
            uint16_t version;
            uint32_t abbrev_offset;
            uint8_t pointer_size;
        } hdr;
        RBinDwarfDIE *dies;
        size_t length;
    } *comp_units;
};

struct RBinDwarfDIE {
    uint64_t abbrev_code;
    unsigned int tag;
    RBinDwarfAttrValue *attr_values;
    size_t length;
};

struct RBinDwarfAttrValue {
    unsigned int name;
};

#define DW_TAG_volatile_type 0
#define DW_AT_vtable_elem_location 0

extern const char *dwarf_tag_name_encodings[];
extern const char *dwarf_attr_encodings[];

void r_bin_dwarf_dump_attr_value(RBinDwarfAttrValue *val, FILE *f);