#include <stdbool.h>

typedef struct ref_s {
    int type;
    void *value;
} ref;

typedef struct os_ptr_s {
    ref *ptr;
} os_ptr;

typedef struct estack_s {
    ref *p;
} estack_t;

typedef struct ostack_s {
    os_ptr p;
} ostack_t;

typedef struct i_ctx_s {
    estack_t estack;
    ostack_t ostack;
    void *error_object;
} i_ctx_t;

typedef struct scanner_state {
    int state;
} scanner_state;

typedef struct scanner_state_dynamic {
    void *mem;
    scanner_state base;
} scanner_state_dynamic;

#define esp (i_ctx_p->estack.p)
#define osp (i_ctx_p->ostack.p)
#define o_push_estack 1

enum {
    scan_BOS = 1,
    scan_EOF = 2,
    scan_Refill = 3,
    scan_Comment = 4,
    scan_DSC_Comment = 5
};

static int tokenexec_continue(i_ctx_t *i_ctx_p, scanner_state *pstate, bool save);
#define ztokenexec_continue tokenexec_continue

void pop(int);
void check_estack(int);
int gs_scan_token(i_ctx_t *, ref *, scanner_state *);
bool r_is_proc(ref *);
void push(int);
void ref_assign(os_ptr, ref *);
int gs_scan_handle_refill(i_ctx_t *, scanner_state *, bool, int (*)(i_ctx_t *, scanner_state *, bool));
int ztoken_handle_comment(i_ctx_t *, scanner_state *, ref *, int, bool, bool, int (*)(i_ctx_t *, scanner_state *, bool));
void gs_scanner_error_object(i_ctx_t *, scanner_state *, void *);
void gs_free_object(void *, void *, const char *);