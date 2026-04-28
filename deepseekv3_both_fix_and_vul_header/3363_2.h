#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef unsigned long uleb128_t;
typedef signed long sleb128_t;

#define MAX_CFI 1024
#define STP_MAX_STACK_DEPTH 32

enum {
    DW_CFA_nop,
    DW_CFA_set_loc,
    DW_CFA_advance_loc1,
    DW_CFA_advance_loc2,
    DW_CFA_advance_loc4,
    DW_CFA_offset_extended,
    DW_CFA_val_offset,
    DW_CFA_offset_extended_sf,
    DW_CFA_val_offset_sf,
    DW_CFA_same_value,
    DW_CFA_restore_extended,
    DW_CFA_undefined,
    DW_CFA_register,
    DW_CFA_expression,
    DW_CFA_val_expression,
    DW_CFA_remember_state,
    DW_CFA_restore_state,
    DW_CFA_def_cfa,
    DW_CFA_def_cfa_offset,
    DW_CFA_def_cfa_sf,
    DW_CFA_def_cfa_offset_sf,
    DW_CFA_def_cfa_register,
    DW_CFA_def_cfa_expression,
    DW_CFA_GNU_args_size,
    DW_CFA_GNU_negative_offset_extended,
    DW_CFA_GNU_window_save
};

enum rule_type {
    Nowhere,
    Memory,
    Register,
    Value,
    Same,
    Expr,
    ValExpr
};

struct unwind_item {
    enum rule_type type;
    uleb128_t value;
};

struct cfa_info {
    uleb128_t reg;
    uleb128_t offs;
};

struct cfa_state {
    struct cfa_info cfa;
    int cfa_is_expr;
    const u8 *cfa_expr;
    struct unwind_item regs[];
};

struct unwind_state {
    unsigned long loc;
    unsigned long dataAlign;
    int stackDepth;
    struct cfa_state *reg;
    struct unwind_item cie_regs[];
};

#define REG_STATE state->reg[state->stackDepth]

void _stp_warn(const char *fmt, ...);
void dbug_unwind(int level, const char *fmt, ...);
unsigned long read_pointer(const u8 **ptr, const u8 *end, signed ptrType, int user);
int advance_loc(unsigned long delta, struct unwind_state *state);
uleb128_t get_uleb128(const u8 **ptr, const u8 *end);
sleb128_t get_sleb128(const u8 **ptr, const u8 *end);
void set_rule(uleb128_t reg, enum rule_type type, uleb128_t value, struct unwind_state *state);
void set_expr_rule(uleb128_t reg, enum rule_type type, const u8 **ptr, const u8 *end, struct unwind_state *state);
uleb128_t DWARF_REG_MAP(uleb128_t reg);