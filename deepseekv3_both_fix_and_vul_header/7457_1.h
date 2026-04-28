#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R_ANAL_OP_DIR_WRITE 1
#define R_ANAL_VAR_ACCESS_TYPE_WRITE 1
#define R_ANAL_VAR_ACCESS_TYPE_READ 0
#define R_ANAL_VAR_KIND_SPV 0
#define R_ANAL_STACK_SET 1
#define R_ANAL_STACK_GET 2
#define R_ANAL_OP_TYPE_PUSH 1
#define R_ANAL_OP_TYPE_POP 2
#define R_ANAL_OP_TYPE_RET 3
#define R_REG_NAME_SP "sp"
#define R_REG_NAME_BP "bp"
#define ARGPREFIX "arg"
#define VARPREFIX "var"
#define PFMT64x "llx"
#define ST32_MAX 0x7fffffff
#define R_ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define R_ABS(x) ((x) < 0 ? -(x) : (x))
#define R_ROUND(x, y) (((x) + (y) - 1) & ~((y) - 1))

typedef int64_t st64;
typedef uint64_t ut64;
typedef int32_t st32;
typedef uint32_t ut32;

typedef struct r_strbuf_t {
    char *buf;
} RStrBuf;

typedef struct r_reg_t {
    const char *name;
} RReg;

typedef struct r_anal_var_t {
    char *name;
} RAnalVar;

typedef struct r_anal_op_t {
    RStrBuf esil;
    ut64 addr;
    ut64 ptr;
    int direction;
    int stackop;
    int type;
    struct {
        ut64 imm;
        st64 delta;
        RReg *reg;
    } *src[4];
    struct {
        RReg *reg;
    } *dst;
} RAnalOp;

typedef struct r_anal_opt_t {
    bool varname_stack;
} RAnalOpt;

typedef struct r_anal_t {
    RReg *reg;
    bool verbose;
    int bits;
    RAnalOpt opt;
    void *sdb_types;
} RAnal;

typedef struct r_anal_function_t {
    char *name;
    st64 stack;
    st64 bp_off;
    int bits;
    char *cc;
} RAnalFunction;

static RAnalVar *get_stack_var(RAnalFunction *fcn, st64 frame_off) { return NULL; }
static void r_anal_var_set_access(RAnalVar *var, const char *reg, ut64 addr, int rw, st64 ptr) {}
static char *r_anal_function_autoname_var(RAnalFunction *fcn, char type, const char *pfx, st64 ptr) { return NULL; }
static RAnalVar *r_anal_function_set_var(RAnalFunction *fcn, st64 frame_off, char type, char *vartype, int size, bool isarg, char *varname) { return NULL; }
static const char *r_strbuf_get(RStrBuf *sb) { return sb->buf; }
static const char *r_reg_get_name(RReg *reg, const char *type) { return NULL; }
static const char *r_anal_cc_arg(RAnal *anal, const char *cc, st32 n) { return NULL; }
static char *r_type_func_guess(void *sdb, const char *name) { return NULL; }
static size_t r_type_func_args_count(void *sdb, const char *name) { return 0; }
static st32 r_anal_cc_max_arg(RAnal *anal, const char *cc) { return 0; }
static char *r_type_func_args_type(void *sdb, const char *name, size_t i) { return NULL; }
static char *r_type_func_args_name(void *sdb, const char *name, size_t i) { return NULL; }
static ut64 r_type_get_bitsize(void *sdb, const char *type) { return 0; }
static char *r_str_newf(const char *fmt, ...) { return NULL; }
static bool r_str_isnumber(const char *str) { return false; }
static st64 r_num_get(void *user, const char *str) { return 0; }
static void eprintf(const char *fmt, ...) {}
#define r_strf_var(buf, size, fmt, ...) char buf[size]; snprintf(buf, size, fmt, __VA_ARGS__)
#define r_return_if_fail(cond) if (!(cond)) return