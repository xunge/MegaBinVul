#include <stdbool.h>
#include <stddef.h>

typedef struct ExprDef ExprDef;
struct ExprDef {
    struct {
        int op;
    } expr;
    struct {
        int ident;
    } ident;
    struct {
        int element;
        int field;
    } field_ref;
    struct {
        int element;
        int field;
        ExprDef *entry;
    } array_ref;
};

struct xkb_context;

enum {
    EXPR_IDENT,
    EXPR_FIELD_REF,
    EXPR_ARRAY_REF
};

#define XKB_ATOM_NONE 0

const char *xkb_atom_text(struct xkb_context *ctx, int atom);
void log_wsgo(struct xkb_context *ctx, const char *format, ...);