#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t ut64;
typedef uint8_t ut8;
typedef int64_t st64;

typedef struct RList {
    void *head;
    void *tail;
} RList;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
    struct RListIter *p;
} RListIter;

typedef struct RRegArena {
    int size;
    ut8 *bytes;
} RRegArena;

typedef struct RRegFlags {
    int s;
    int z;
    int c;
    int o;
    int p;
} RRegFlags;

typedef struct RRegItem {
    char *name;
    int type;
    int size;
    int offset;
} RRegItem;

typedef struct RRegSet {
    RList *regs;
    RList *pool;
    RRegArena *arena;
} RRegSet;

typedef struct RReg {
    RRegSet regset[3]; // R_REG_TYPE_LAST = 3
    char *reg_profile_cmt;
} RReg;

typedef struct RConsContext {
    struct {
        const char *creg;
    } pal;
} RConsContext;

typedef struct RCons {
    RConsContext *context;
} RCons;

typedef struct RConfig {
    // config implementation
} RConfig;

typedef struct RPrint {
    // print implementation
} RPrint;

typedef struct RNum {
    ut64 value;
} RNum;

typedef struct RDebug {
    RReg *reg;
    RList *q_regs;
} RDebug;

typedef struct RAnal {
    RReg *reg;
    RList *q_regs;
    int bits;
} RAnal;

typedef struct RCore {
    RAnal *anal;
    RDebug *dbg;
    RConfig *config;
    RCons *cons;
    RPrint *print;
    RNum *num;
} RCore;

typedef struct PJ {
    // json implementation
} PJ;

#define R_SYS_BITS_64 64
#define R_REG_TYPE_GPR 0
#define R_REG_TYPE_ALL 1
#define R_REG_TYPE_LAST 3
#define R_REG_COND_LAST 16
#define Color_BWHITE ""
#define PFMT64x "llx"
#define IS_DIGIT(x) (x >= '0' && x <= '9')

// Function declarations
int r_config_get_i(RConfig *cfg, const char *key);
int r_reg_type_by_name(const char *name);
int r_reg_get_name_idx(const char *name);
int r_reg_cond_from_string(const char *name);
int r_reg_cond_bits(RReg *reg, int id, RRegFlags *rf);
int r_list_length(RList *list);
int showreg(RCore *core, const char *name);

const char *r_reg_get_name(RReg *reg, int idx);
const char *r_reg_get_type(int type);
const char *r_reg_cond_to_string(int id);
const char *r_str_trim_head_ro(const char *str);
const char *sdb_fmt(const char *fmt, ...);

char *r_str_trim_dup(const char *str);
char *r_str_trim_nc(char *str);
char *r_core_cmd_strf(RCore *core, const char *fmt, ...);
char *r_reg_profile_to_cc(RReg *reg);

void r_cons_println(const char *str);
void r_cons_printf(const char *fmt, ...);
void r_cons_newline(void);
void r_core_cmd_help(RCore *core, const char **help_msg);
void r_core_cmd0(RCore *core, const char *cmd);
void r_core_cmdf(RCore *core, const char *fmt, ...);
void r_print_hexdump(RPrint *p, ut64 addr, const ut8 *buf, int len, int cols, int step, int zooms);
void r_reg_arena_zero(RReg *reg);
void r_reg_arena_set_bytes(RReg *reg, const char *str);
void r_reg_arena_swap(RReg *reg, bool b);
void r_reg_arena_push(RReg *reg);
void r_reg_arena_pop(RReg *reg);
void r_debug_reg_list(RDebug *dbg, int type, int bits, const char *name, int cols, const char *color);
void r_debug_reg_sync(RDebug *dbg, int type, bool b);
void r_core_debug_rr(RCore *core, RReg *reg, char mode);

RRegItem *r_reg_get(RReg *reg, const char *name, int type);
RRegItem *r_reg_cond_get(RReg *reg, const char *name);
RRegSet *r_reg_regset_get(RReg *reg, int type);
RRegFlags *r_reg_cond_retrieve(RReg *reg, const char *name);
ut64 r_reg_getv(RReg *reg, const char *name);
ut8 *r_reg_get_bytes(RReg *reg, int type, int *size);

void cmd_debug_reg(RCore *core, const char *str);
void cmd_reg_profile(RCore *core, char mode, const char *str);
void __tableRegList(RCore *core, RReg *reg, const char *str);
void __anal_reg_list(RCore *core, int type, int size, char mode);

extern const char *help_msg_arw[];
extern const char *help_msg_ara[];
extern const char *help_msg_ar[];

PJ *pj_new(void);
void pj_a(PJ *pj);
void pj_s(PJ *pj, const char *str);
void pj_end(PJ *pj);
const char *pj_string(PJ *pj);
void pj_free(PJ *pj);

void r_list_foreach(RList *list, RListIter *iter, void *data);
RList *r_list_new(void);
void r_list_append(RList *list, void *data);
bool r_list_empty(RList *list);
void r_list_free(RList *list);

int r_str_isnumber(const char *str);
void r_str_ncpy(char *dst, const char *src, int len);
void eprintf(const char *fmt, ...);
void r_reg_set_value(RReg *reg, RRegItem *item, ut64 value);
st64 r_num_math(RNum *num, const char *str);

// Macro for r_list_foreach
#define r_list_foreach(list, it, pos) \
    for ((it) = (list)->head; (it) && ((pos) = (it)->data, 1); (it) = (it)->n)