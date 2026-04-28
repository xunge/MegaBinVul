#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint16_t ut16;
typedef uint8_t ut8;

#define UT8_MAX 0xff
#define BITS2BYTES(b) ((b) / 8)
#define PFMT64x "llx"
#define R_API
#define r_return_val_if_fail(cond, ret) if (!(cond)) return (ret)

typedef struct r_reg_item_t {
    int arena;
    int offset;
    int size;
    char *name;
} RRegItem;

typedef struct r_reg_arena_t {
    ut8 *bytes;
    int size;
} RRegArena;

typedef struct r_reg_set_t {
    RRegArena *arena;
} RRegSet;

typedef struct r_reg_t {
    RRegSet regset[10];
    bool big_endian;
} RReg;

bool r_reg_is_readonly(RReg *reg, RRegItem *item);
void r_reg_set_longdouble(RReg *reg, RRegItem *item, long double value);
void r_write_be64(ut8 *dest, ut64 val);
void r_write_le64(ut8 *dest, ut64 val);
void r_write_be32(ut8 *dest, ut32 val);
void r_write_le32(ut8 *dest, ut32 val);
void r_write_be16(ut8 *dest, ut16 val);
void r_write_le16(ut8 *dest, ut16 val);
void r_write_ble8(ut8 *dest, ut8 val);
void r_mem_copybits(ut8 *dst, const ut8 *src, int n);
int eprintf(const char *format, ...);