#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef uint64_t ut64;
typedef uint32_t ut32;
typedef uint8_t ut8;

#define UT32_MAX UINT32_MAX
#define PFMT64x "lx"

#define R_ANAL_ARCHINFO_MIN_OP_SIZE 0
#define R_ANAL_OP_TYPE_CALL 1
#define R_ANAL_REF_TYPE_CALL 2

typedef struct RConfig {
    // dummy structure
} RConfig;

typedef struct RIO {
    int addrbytes;
    // dummy structure
} RIO;

typedef struct RAnal {
    // dummy structure
} RAnal;

typedef struct RAsmConfig {
    int bits;
    // dummy structure
} RAsmConfig;

typedef struct RAsm {
    RAsmConfig *config;
    // dummy structure
} RAsm;

typedef struct RFlag {
    // dummy structure
} RFlag;

typedef struct RCons {
    // dummy structure
} RCons;

typedef struct RCore {
    RConfig *config;
    RIO *io;
    RAnal *anal;
    RAsm *rasm;
    RFlag *flags;
} RCore;

typedef struct RAnalOp {
    int size;
    int type;
    ut64 jump;
} RAnalOp;

typedef struct RAnalHint {
    int bits;
} RAnalHint;

typedef struct RFlagItem {
    char *name;
} RFlagItem;

typedef struct RBinReloc {
    bool import;
    bool symbol;
} RBinReloc;

int r_config_get_i(RConfig *config, const char *key);
int r_anal_archinfo(RAnal *anal, int query);
void r_cons_break_push(void *a, void *b);
bool r_cons_is_breaked(void);
int r_io_read_at(RIO *io, ut64 addr, ut8 *buf, int len);
RAnalHint *r_anal_hint_get(RAnal *anal, ut64 addr);
void r_anal_hint_free(RAnalHint *hint);
void r_config_set_i(RConfig *config, const char *key, int val);
int r_anal_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *data, int len, int mask);
RFlagItem *r_flag_get_i(RFlag *flags, ut64 addr);
RBinReloc *r_core_getreloc(RCore *core, ut64 addr, int size);
void r_cons_printf(const char *fmt, ...);
void r_anal_xrefs_set(RAnal *anal, ut64 from, ut64 to, int type);
bool r_io_is_valid_offset(RIO *io, ut64 addr, int perm);
void r_core_anal_fcn(RCore *core, ut64 addr, ut64 from, int type, int depth);
void r_anal_op_fini(RAnalOp *op);
void r_cons_break_pop(void);