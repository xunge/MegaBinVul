#include <stdbool.h>
#include <stddef.h>

struct xkb_context;

typedef enum {
    EXPR_IDENT,
    EXPR_FIELD_REF,
    EXPR_ARRAY_REF
} expr_op;

typedef struct ExprDef ExprDef;

typedef struct {
    const char *ident;
} ident;

typedef struct {
    const char *element;
    const char *field;
} field_ref;

typedef struct {
    const char *element;
    const char *field;
    ExprDef *entry;
} array_ref;

typedef struct {
    expr_op op;
} expr;

struct ExprDef {
    expr expr;
    union {
        ident ident;
        field_ref field_ref;
        array_ref array_ref;
    };
};

const char *xkb_atom_text(struct xkb_context *ctx, const char *atom);
void log_wsgo(struct xkb_context *ctx, const char *fmt, ...);