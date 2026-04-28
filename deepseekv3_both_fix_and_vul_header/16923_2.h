#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t ut8;
typedef uint16_t ut16;
typedef uint32_t ut32;
typedef uint64_t ut64;
typedef int64_t st64;

typedef enum {
    DW_AT_KIND_BLOCK,
    DW_AT_KIND_LOCLISTPTR,
    DW_AT_KIND_REFERENCE,
    DW_AT_KIND_CONSTANT
} DwarfAttrKind;

typedef enum {
    DW_OP_fbreg,
    DW_OP_reg0,
    DW_OP_reg1,
    DW_OP_reg2,
    DW_OP_reg3,
    DW_OP_reg4,
    DW_OP_reg5,
    DW_OP_reg6,
    DW_OP_reg7,
    DW_OP_reg8,
    DW_OP_reg9,
    DW_OP_reg10,
    DW_OP_reg11,
    DW_OP_reg12,
    DW_OP_reg13,
    DW_OP_reg14,
    DW_OP_reg15,
    DW_OP_reg16,
    DW_OP_reg17,
    DW_OP_reg18,
    DW_OP_reg19,
    DW_OP_reg20,
    DW_OP_reg21,
    DW_OP_reg22,
    DW_OP_reg23,
    DW_OP_reg24,
    DW_OP_reg25,
    DW_OP_reg26,
    DW_OP_reg27,
    DW_OP_reg28,
    DW_OP_reg29,
    DW_OP_reg30,
    DW_OP_reg31,
    DW_OP_breg0,
    DW_OP_breg1,
    DW_OP_breg2,
    DW_OP_breg3,
    DW_OP_breg4,
    DW_OP_breg5,
    DW_OP_breg6,
    DW_OP_breg7,
    DW_OP_breg8,
    DW_OP_breg9,
    DW_OP_breg10,
    DW_OP_breg11,
    DW_OP_breg12,
    DW_OP_breg13,
    DW_OP_breg14,
    DW_OP_breg15,
    DW_OP_breg16,
    DW_OP_breg17,
    DW_OP_breg18,
    DW_OP_breg19,
    DW_OP_breg20,
    DW_OP_breg21,
    DW_OP_breg22,
    DW_OP_breg23,
    DW_OP_breg24,
    DW_OP_breg25,
    DW_OP_breg26,
    DW_OP_breg27,
    DW_OP_breg28,
    DW_OP_breg29,
    DW_OP_breg30,
    DW_OP_breg31,
    DW_OP_bregx,
    DW_OP_addr,
    DW_OP_call_frame_cfa
} DwarfOpcode;

typedef enum {
    LOCATION_UNKNOWN,
    LOCATION_GLOBAL,
    LOCATION_BP
} VariableLocationKind;

typedef struct {
    size_t length;
    ut8 *data;
} RBinDwarfBlock;

typedef struct {
    RBinDwarfBlock *expression;
} RBinDwarfLocRange;

typedef struct {
    void *list;
} RBinDwarfLocList;

typedef struct {
    DwarfAttrKind kind;
    ut64 reference;
    RBinDwarfBlock block;
} RBinDwarfAttrValue;

typedef struct {
    void *locations;
    struct {
        void *cpu;
        int bits;
        int big_endian;
    } *anal;
} Context;

typedef struct {
    const char *reg_name;
    ut64 reg_num;
    VariableLocationKind kind;
    st64 offset;
    ut64 address;
} VariableLocation;

#define R_NEW0(x) calloc(1, sizeof(x))

static st64 r_sleb128(const ut8 **p, const ut8 *end) {
    st64 result = 0;
    int shift = 0;
    ut8 byte;
    do {
        if (*p >= end) return 0;
        byte = *(*p)++;
        result |= (st64)(byte & 0x7f) << shift;
        shift += 7;
    } while (byte & 0x80);
    if ((byte & 0x40) && (shift < 64)) {
        result |= -(1ULL << shift);
    }
    return result;
}

static ut64 r_uleb128(const ut8 *p, size_t len, ut64 *v, const ut8 **next) {
    ut64 result = 0;
    int shift = 0;
    const ut8 *end = p + len;
    while (p < end) {
        ut8 byte = *p++;
        result |= (ut64)(byte & 0x7f) << shift;
        if (!(byte & 0x80)) break;
        shift += 7;
    }
    if (v) *v = result;
    if (next) *next = p;
    return result;
}

static ut8 r_read_ble8(const ut8 *p) {
    return *p;
}

static ut16 r_read_ble16(const ut8 *p, int big_endian) {
    if (big_endian) {
        return (p[0] << 8) | p[1];
    }
    return (p[1] << 8) | p[0];
}

static ut32 r_read_ble32(const ut8 *p, int big_endian) {
    if (big_endian) {
        return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
    }
    return (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
}

static ut64 r_read_ble64(const ut8 *p, int big_endian) {
    if (big_endian) {
        return ((ut64)p[0] << 56) | ((ut64)p[1] << 48) | ((ut64)p[2] << 40) | ((ut64)p[3] << 32) |
               ((ut64)p[4] << 24) | ((ut64)p[5] << 16) | ((ut64)p[6] << 8) | (ut64)p[7];
    }
    return ((ut64)p[7] << 56) | ((ut64)p[6] << 48) | ((ut64)p[5] << 40) | ((ut64)p[4] << 32) |
           ((ut64)p[3] << 24) | ((ut64)p[2] << 16) | ((ut64)p[1] << 8) | (ut64)p[0];
}

static void r_warn_if_reached(void) {
    return;
}

static const char *get_dwarf_reg_name(void *cpu, ut64 reg_num, VariableLocationKind *kind, int bits) {
    return NULL;
}

static RBinDwarfLocRange *find_largest_loc_range(void *list) {
    return NULL;
}

static void *ht_up_find(void *ht, ut64 key, void *user) {
    return NULL;
}