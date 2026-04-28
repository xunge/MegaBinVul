#include <stdbool.h>

typedef struct i_ctx_t {
    void *error_object;
} i_ctx_t;

typedef struct scanner_state {
    int dummy;
} scanner_state;

typedef struct ref {
    int dummy;
} ref;

typedef void *os_ptr;

#define osp (0)
#define pop(n)
#define push(n)
#define ref_assign(dest, src)
#define make_true(op)
#define make_false(op)
#define ifree_object(p, str)

enum {
    scan_BOS = 1,
    scan_EOF = -1,
    scan_Refill = -2,
    gs_error_syntaxerror = -3,
    o_push_estack = -4
};

int gs_scan_token(i_ctx_t *i_ctx_p, ref *token, scanner_state *pstate);
int gs_note_error(int error);
void gs_scanner_error_object(i_ctx_t *i_ctx_p, scanner_state *pstate, void *error_object);
int gs_scan_handle_refill(i_ctx_t *i_ctx_p, scanner_state *pstate, bool save, void *continuation);
static int ztoken_continue = 0;

// Fix for case value conflict
#define TOKEN_READ 0