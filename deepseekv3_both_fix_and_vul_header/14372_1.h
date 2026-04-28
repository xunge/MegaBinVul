#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef long linenr_T;

typedef struct typval_S typval_T;
typedef struct evalarg_S evalarg_T;
typedef struct garray_S garray_T;
typedef struct ufunc_S ufunc_T;
typedef struct exarg_S exarg_T;
typedef struct partial_S partial_T;
typedef struct script_ctx_S script_ctx_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1

#define EVAL_EVALUATE 1
#define CMD_block 0
#define FC_LAMBDA 0x01
#define FC_SANDBOX 0x02
#define FC_VIM9 0x04
#define VAR_PARTIAL 1

static int SOURCING_LNUM = 0;

struct garray_S {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    void *ga_data;
};

struct typval_S {
    int v_type;
    union {
        struct partial_S *v_partial;
    } vval;
};

struct evalarg_S {
    int eval_flags;
    garray_T eval_ga;
    garray_T eval_freega;
    void *eval_cctx;
    int (*eval_getline)(void);
    void *eval_cookie;
    int eval_break_count;
    garray_T eval_tofree_ga;
    int eval_using_cmdline;
    void *eval_cstack;
};

struct script_ctx_S {
    int sc_version;
    int sc_lnum;
};

struct ufunc_S {
    char_u *uf_name;
    int uf_flags;
    int uf_refcount;
    garray_T uf_args;
    garray_T uf_def_args;
    void *uf_func_type;
    garray_T uf_lines;
    script_ctx_T uf_script_ctx;
    int uf_script_ctx_version;
};

struct exarg_S {
    int cmdidx;
    int forceit;
    char_u **cmdlinep;
    int skip;
    int (*getline)(void);
    void *cookie;
    char_u *nextcmd;
};

struct partial_S {
    ufunc_T *pt_func;
    int pt_refcount;
};

static script_ctx_T current_sctx = {0};
static void *func_hashtab = NULL;
static int sandbox = 0;
static void *t_func_any = NULL;

#define skipwhite(p) (p)
#define ends_excmd2(a, b) 0
#define semsg(a, b)
#define _(x) x
#define e_trailing_arg ""
#define CLEAR_FIELD(x) memset(&(x), 0, sizeof(x))
#define ga_init2(gap, size, len) memset((gap), 0, sizeof(*(gap)))
#define ga_grow(gap, n) 1
#define vim_free(p) free(p)
#define vim_strnsave(p, n) malloc(n)
#define mch_memmove(d, s, n) memmove(d, s, n)
#define vim9_comment_start(p) 0
#define STRLEN(p) strlen((char *)(p))
#define NUL '\0'
#define get_lambda_name() ((char_u *)"lambda")
#define alloc_clear(size) calloc(1, size)
#define set_ufunc_name(uf, name) (uf)->uf_name = (name)
#define hash_add(ht, key) 0
#define UF2HIKEY(uf) NULL
#define parse_argument_types(uf, at, va) 0
#define parse_return_type(uf, rt) 0
#define ALLOC_CLEAR_ONE(type) calloc(1, sizeof(type))
#define ASCII_ISUPPER(c) isupper((unsigned char)(c))
#define set_function_type(uf)
#define function_using_block_scopes(uf, cs)
#define ga_clear_strings(gap)
#define func_clear(uf, free)
#define func_free(uf, free)
#define fill_exarg_from_cctx(eap, cctx)
#define get_function_body(eap, newlines, p, line_to_free) OK