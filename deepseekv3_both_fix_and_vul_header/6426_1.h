#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;
typedef int64_t st64;

#define READ(buf, type) (*(type *)(buf)); buf += sizeof(type)

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
    DW_FORM_ref8 = 0x14
};

typedef struct {
    ut64 attr_name;
    ut64 attr_form;
} RBinDwarfAttrSpec;

typedef struct {
    ut8 *data;
    ut64 length;
} RBinDwarfBlock;

typedef struct {
    char *string;
    ut64 offset;
} RBinDwarfStrStruct;

typedef union {
    ut64 address;
    ut64 data;
    ut64 reference;
    ut8 flag;
    st64 sdata;
    RBinDwarfBlock block;
    RBinDwarfStrStruct str_struct;
} RBinDwarfAttrEncoding;

typedef struct {
    ut64 form;
    ut64 name;
    RBinDwarfAttrEncoding encoding;
} RBinDwarfAttrValue;

typedef struct {
    ut8 pointer_size;
} RBinDwarfCompUnitHdr;

const ut8 *r_uleb128(const ut8 *data, int len, ut64 *v);
const ut8 *r_leb128(const ut8 *data, st64 *v);
int eprintf(const char *format, ...);
#define R_MIN(x, y) ((x) < (y) ? (x) : (y))
#define PFMT64x "llx"