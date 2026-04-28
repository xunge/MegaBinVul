#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;
typedef int64_t st64;

#define READ8(p) (*(p)++)
#define READ16(p) (p += 2, *(ut16*)(p - 2))
#define READ32(p) (p += 4, *(ut32*)(p - 4))
#define READ64(p) (p += 8, *(ut64*)(p - 8))
#define READ(p, t) (*(t*)(p++))
#define PFMT64x "llx"

enum {
    DW_FORM_addr = 0x01,
    DW_FORM_data1 = 0x0B,
    DW_FORM_data2 = 0x0C,
    DW_FORM_data4 = 0x0D,
    DW_FORM_data8 = 0x0E,
    DW_FORM_data16 = 0x0F,
    DW_FORM_sdata = 0x11,
    DW_FORM_udata = 0x12,
    DW_FORM_string = 0x13,
    DW_FORM_block1 = 0x14,
    DW_FORM_block2 = 0x15,
    DW_FORM_block4 = 0x16,
    DW_FORM_block = 0x17,
    DW_FORM_flag = 0x18,
    DW_FORM_strp = 0x19,
    DW_FORM_ref_addr = 0x1A,
    DW_FORM_ref1 = 0x1B,
    DW_FORM_ref2 = 0x1C,
    DW_FORM_ref4 = 0x1D,
    DW_FORM_ref8 = 0x1E,
    DW_FORM_ref_udata = 0x1F,
    DW_FORM_sec_offset = 0x20,
    DW_FORM_exprloc = 0x21,
    DW_FORM_flag_present = 0x22,
    DW_FORM_ref_sig8 = 0x23,
    DW_FORM_strx = 0x24,
    DW_FORM_strx1 = 0x25,
    DW_FORM_strx2 = 0x26,
    DW_FORM_strx3 = 0x27,
    DW_FORM_strx4 = 0x28,
    DW_FORM_implicit_const = 0x29,
    DW_FORM_addrx = 0x2A,
    DW_FORM_addrx1 = 0x2B,
    DW_FORM_addrx2 = 0x2C,
    DW_FORM_addrx3 = 0x2D,
    DW_FORM_addrx4 = 0x2E,
    DW_FORM_line_ptr = 0x2F,
    DW_FORM_strp_sup = 0x30,
    DW_FORM_ref_sup4 = 0x31,
    DW_FORM_ref_sup8 = 0x32,
    DW_FORM_loclistx = 0x33,
    DW_FORM_rnglistx = 0x34
};

typedef enum {
    DW_AT_KIND_ADDRESS,
    DW_AT_KIND_BLOCK,
    DW_AT_KIND_CONSTANT,
    DW_AT_KIND_FLAG,
    DW_AT_KIND_REFERENCE,
    DW_AT_KIND_STRING,
    DW_AT_KIND_LOCLISTPTR
} RBinDwarfAttrKind;

typedef struct {
    ut8 *data;
    ut64 length;
} RBinDwarfBlock;

typedef struct {
    char *content;
    ut64 offset;
} RBinDwarfString;

typedef struct {
    ut64 attr_name;
    ut64 attr_form;
    st64 special;
} RBinDwarfAttrDef;

typedef struct {
    RBinDwarfAttrKind kind;
    ut64 attr_form;
    ut64 attr_name;
    union {
        ut64 uconstant;
        st64 sconstant;
        ut64 address;
        ut64 reference;
        bool flag;
    };
    RBinDwarfBlock block;
    RBinDwarfString string;
} RBinDwarfAttrValue;

typedef struct {
    bool is_64bit;
    ut8 address_size;
    ut64 unit_offset;
} RBinDwarfCompUnitHdr;

#define r_return_val_if_fail(cond, val) if (!(cond)) return (val)
#define R_LOG_WARN(fmt, ...) 

static ut64 dwarf_read_offset(bool is_64bit, const ut8 **buf, const ut8 *buf_end) {
    if (is_64bit) {
        return READ64(*buf);
    }
    return READ32(*buf);
}

static const ut8 *r_leb128(const ut8 *buf, int buf_len, st64 *out) {
    *out = 0;
    return buf;
}

static const ut8 *r_uleb128(const ut8 *buf, int buf_len, ut64 *out, int *sign) {
    *out = 0;
    return buf;
}

static char *r_str_ndup(const char *s, size_t n) {
    return strndup(s, n);
}

static const ut8 *fill_block_data(const ut8 *buf, const ut8 *buf_end, RBinDwarfBlock *block) {
    return buf;
}