#include <stdbool.h>
#include <string.h>

struct xkb_context;

typedef struct ExprDef ExprDef;

enum expr_op_type {
    EXPR_VALUE,
    EXPR_IDENT,
    EXPR_FIELD_REF,
    EXPR_INVERT,
    EXPR_NOT,
    EXPR_ADD,
    EXPR_SUBTRACT,
    EXPR_MULTIPLY,
    EXPR_DIVIDE,
    EXPR_ASSIGN,
    EXPR_NEGATE,
    EXPR_UNARY_PLUS
};

enum expr_value_type {
    EXPR_TYPE_BOOLEAN
};

struct expr {
    enum expr_op_type op;
    enum expr_value_type value_type;
};

struct ident {
    const char *ident;
};

struct field_ref {
    const char *element;
    const char *field;
};

struct unary {
    ExprDef *child;
};

struct boolean {
    bool set;
};

struct ExprDef {
    struct expr expr;
    union {
        struct boolean boolean;
        struct ident ident;
        struct field_ref field_ref;
        struct unary unary;
    };
};

const char *xkb_atom_text(struct xkb_context *ctx, const char *atom);
void log_err(struct xkb_context *ctx, const char *fmt, ...);
void log_wsgo(struct xkb_context *ctx, const char *fmt, ...);
const char *expr_value_type_to_string(enum expr_value_type type);
const char *expr_op_type_to_string(enum expr_op_type op);
static inline bool istreq(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}