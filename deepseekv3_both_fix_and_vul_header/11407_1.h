#include <stdbool.h>
#include <stddef.h>

typedef struct ExprDef ExprDef;
typedef struct CompatInfo CompatInfo;
typedef unsigned int xkb_mod_mask_t;
typedef unsigned int xkb_atom_t;

enum xkb_match_operation {
    MATCH_ANY_OR_NONE,
    MATCH_EXACTLY,
    MATCH_ANY
};

enum expr_op {
    EXPR_ACTION_DECL,
    EXPR_IDENT
};

#define MOD_REAL_MASK_ALL 0xFFFFFFFF
#define MOD_REAL 0

extern const void *symInterpretMatchMaskNames;

struct ExprDef {
    struct {
        enum expr_op op;
    } expr;
    union {
        struct {
            xkb_atom_t name;
            ExprDef *args;
        } action;
        struct {
            xkb_atom_t ident;
        } ident;
    };
};

struct CompatInfo {
    void *ctx;
    xkb_mod_mask_t mods;
};

bool LookupString(const void *symInterpretMatchMaskNames, const char *pred_txt, enum xkb_match_operation *pred_rtrn);
const char *xkb_atom_text(void *ctx, xkb_atom_t atom);
bool istreq(const char *str1, const char *str2);
void log_err(void *ctx, const char *fmt, ...);
bool ExprResolveModMask(void *ctx, ExprDef *expr, int type, xkb_mod_mask_t *mods, xkb_mod_mask_t *mods_rtrn);