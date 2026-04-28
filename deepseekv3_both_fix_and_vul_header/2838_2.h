#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

#define PFMT64x PRIx64
#define PFMT64u PRIu64
#define UT64_MAX UINT64_MAX
#define Color_RESET ""
#define R_ANAL_OP_MASK_ESIL 0
#define R_ANAL_OP_TYPE_COND 0
#define R_PRINT_FLAGS_COLOR 1
#define R_STRBUF_SAFEGET(x) ""
#define R_MIN(a,b) ((a)<(b)?(a):(b))
#define R_MAX(a,b) ((a)>(b)?(a):(b))

typedef struct RCore RCore;
typedef struct RConfig RConfig;
typedef struct RPrint {
    int flags;
    bool big_endian;
} RPrint;
typedef struct RCons {
    struct {
        const char *label;
    } pal;
    void (*printf)(const char *fmt, ...);
    void (*print)(const char *str);
    void (*newline)(void);
} RCons;
typedef struct RAnal RAnal;
typedef struct RAnalOp {
    int size;
    ut64 val;
    ut64 ptr;
    ut64 jump;
    ut64 fail;
    int refptr;
    bool sign;
    ut64 prefix;
    int id;
    int cycles;
    int failcycles;
    int delay;
    int stackop;
    int stackptr;
    int type;
    int type2;
    int family;
    int cond;
    int direction;
    char *reg;
    char *ireg;
    int scale;
    struct {
        char *buf;
    } esil;
    struct {
        char *buf;
    } opex;
} RAnalOp;
typedef struct RAnalEsil RAnalEsil;
typedef struct RAnalHint {
    int size;
    char *opcode;
    char *esil;
    ut64 jump;
    ut64 fail;
} RAnalHint;
typedef struct RAsmOp {
    int size;
    char *asm_op;
} RAsmOp;
typedef struct RAsm RAsm;
typedef struct RParse {
    int relsub;
    ut64 relsub_addr;
} RParse;
typedef struct RIO RIO;
typedef struct RFlag RFlag;

struct RCore {
    RConfig *config;
    RPrint *print;
    RCons *cons;
    RAnal *anal;
    RAsm *assembler;
    RParse *parser;
    RIO *io;
    RFlag *flags;
    ut64 offset;
    int blocksize;
};

const char *r_anal_optype_to_string(int type);
const char *r_anal_op_family_to_string(int family);
const char *r_anal_cond_tostring(int cond);
const char *r_anal_stackop_tostring(int stackop);
const char *r_str_bool(bool b);
char *r_asm_op_get_asm(RAsmOp *op);
char *r_asm_describe(RAsm *a, const char *opname);
void r_anal_op_fini(RAnalOp *op);
RAnalEsil *r_anal_esil_new(int stacksize, bool iotrap, unsigned int addrsize);
void r_anal_esil_to_reil_setup(RAnalEsil *esil, RAnal *anal, bool romem, bool stats);
void r_anal_esil_set_pc(RAnalEsil *esil, ut64 pc);
void r_anal_esil_parse(RAnalEsil *esil, const char *str);
void r_anal_esil_dumpstack(RAnalEsil *esil);
void r_anal_esil_stack_free(RAnalEsil *esil);
void r_anal_esil_free(RAnalEsil *esil);
RAnalHint *r_anal_hint_get(RAnal *anal, ut64 addr);
void r_anal_hint_free(RAnalHint *hint);
void r_asm_set_pc(RAsm *a, ut64 pc);
int r_asm_disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len);
int r_anal_op(RAnal *anal, RAnalOp *op, ut64 addr, const ut8 *buf, int len, int mask);
void r_parse_varsub(RParse *p, void *user, ut64 addr, int len, const char *asm_str, char *out, int out_len);
bool r_io_read_i(RIO *io, ut64 addr, ut64 *val, int size, bool big_endian);
void r_parse_filter(RParse *p, ut64 addr, RFlag *flags, char *in, char *out, int out_len, bool big_endian);
void r_str_split(char *str, char ch);
int r_config_get_i(RConfig *cfg, const char *name);
void eprintf(const char *fmt, ...);