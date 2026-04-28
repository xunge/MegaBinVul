#include <stddef.h>
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
#define READ16(p) (p += 2, *(uint16_t*)(p - 2))
#define READ32(p) (p += 4, *(uint32_t*)(p - 4))
#define READ64(p) (p += 8, *(uint64_t*)(p - 8))
#define READ(p, t) (*(t*)(p++))

#define r_return_val_if_fail(cond, ret) if (!(cond)) return ret
#define eprintf(...) 
#define PFMT64x "llx"

enum {
    DW_FORM_addr = 0x01,
    DW_FORM_block2 = 0x03,
    DW_FORM_block4 = 0x04,
    DW_FORM_data2 = 0x05,
    DW_FORM_data4 = 0x06,
    DW_FORM_data8 = 0x07,
    DW_FORM_string = 0x08,
    DW_FORM_block = 0x09,
    DW_FORM_block1 = 0x0a,
    DW_FORM_data1 = 0x0b,
    DW_FORM_flag = 0x0c,
    DW_FORM_sdata = 0x0d,
    DW_FORM_strp = 0x0e,
    DW_FORM_udata = 0x0f,
    DW_FORM_ref_addr = 0x10,
    DW_FORM_ref1 = 0x11,
    DW_FORM_ref2 = 0x12,
    DW_FORM_ref4 = 0x13,
    DW_FORM_ref8 = 0x14,
    DW_FORM_ref_udata = 0x15,
    DW_FORM_indirect = 0x16,
    DW_FORM_sec_offset = 0x17,
    DW_FORM_exprloc = 0x18,
    DW_FORM_flag_present = 0x19,
    DW_FORM_ref_sig8 = 0x20,
    DW_FORM_strx = 0x1a,
    DW_FORM_addrx = 0x1b,
    DW_FORM_ref_sup4 = 0x1c,
    DW_FORM_strp_sup = 0x1d,
    DW_FORM_data16 = 0x1e,
    DW_FORM_line_ptr = 0x1f,
    DW_FORM_implicit_const = 0x21,
    DW_FORM_loclistx = 0x22,
    DW_FORM_rnglistx = 0x23,
    DW_FORM_ref_sup8 = 0x24,
    DW_FORM_strx1 = 0x25,
    DW_FORM_strx2 = 0x26,
    DW_FORM_strx3 = 0x27,
    DW_FORM_strx4 = 0x28,
    DW_FORM_addrx1 = 0x29,
    DW_FORM_addrx2 = 0x2a,
    DW_FORM_addrx3 = 0x2b,
    DW_FORM_addrx4 = 0x2c
};

typedef struct {
    ut8 *data;
    ut64 length;
} RBinDwarfBlock;

typedef struct {
    char *content;
    ut64 offset;
} RBinDwarfString;

typedef struct {
    int attr_form;
    int attr_name;
    st64 special;
} RBinDwarfAttrDef;

typedef struct {
    int attr_form;
    int attr_name;
    ut64 address;
    ut64 data;
    st64 sdata;
    RBinDwarfBlock block;
    RBinDwarfString string;
    bool flag;
    ut64 reference;
} RBinDwarfAttrValue;

typedef struct {
    ut8 address_size;
    bool is_64bit;
    ut64 unit_offset;
} RBinDwarfCompUnitHdr;

static ut64 dwarf_read_piece(bool is_64bit, const ut8 **buf, const ut8 *buf_end);
static const ut8 *r_leb128(const ut8 *buf, int buf_len, st64 *out);
static const ut8 *r_uleb128(const ut8 *buf, int buf_len, ut64 *out);