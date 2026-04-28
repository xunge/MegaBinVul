#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char char_u;
typedef int linenr_T;
typedef int bool;

typedef struct garray {
    int ga_len;
    void *ga_data;
} garray_T;

typedef struct dictitem {
    struct {
        int v_type;
        struct {
            char_u *v_string;
        } vval;
        int v_lock;
    } di_tv;
} dictitem_T;

typedef struct dictvar {
    int dv_scope;
    int dv_lock;
} dictvar_T;

typedef struct funcdict {
    dictvar_T *fd_dict;
    dictitem_T *fd_di;
    char_u *fd_newkey;
} funcdict_T;

typedef struct hashitem {
    char_u *hi_key;
} hashitem_T;

typedef struct hashtab {
    hashitem_T *ht_array;
} hashtab_T;

typedef struct imported {
    char_u *imp_name;
} imported_T;

typedef struct cstack {
    int cs_idx;
} cstack_T;

typedef struct regmatch {
    void *regprog;
    int rm_ic;
} regmatch_T;

typedef struct script_ctx {
    int sc_sid;
    int sc_seq;
    int sc_version;
    linenr_T sc_lnum;
} script_ctx_T;

typedef struct ufunc {
    char_u *uf_name;
    char_u *uf_name_exp;
    garray_T uf_args;
    garray_T uf_def_args;
    void *uf_ret_type;
    void *uf_func_type;
    int uf_def_status;
    garray_T uf_lines;
    int uf_varargs;
    int uf_flags;
    int uf_calls;
    int uf_cleared;
    int uf_refcount;
    script_ctx_T uf_script_ctx;
    int uf_script_ctx_version;
    void *uf_scoped;
    void *uf_arg_types;
} ufunc_T;

typedef struct exarg {
    char_u *cmd;
    char_u *arg;
    int skip;
    int forceit;
    int cmdidx;
    char_u *nextcmd;
    cstack_T *cstack;
} exarg_T;

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define FAIL 0
#define OK 1
#define VAR_FUNC 1
#define VAR_PARTIAL 2
#define VAR_DEF_SCOPE 3
#define FC_RANGE 1
#define FC_DICT 2
#define FC_ABORT 4
#define FC_CLOSURE 8
#define FC_DEAD 16
#define FC_REMOVED 32
#define FC_SANDBOX 64
#define FC_VIM9 128
#define FC_EXPORT 256
#define UF_NOT_COMPILED 0
#define UF_TO_BE_COMPILED 1
#define SCRIPT_VERSION_VIM9 1
#define SCRIPT_VERSION_MAX 2
#define CMD_function 1
#define CMD_def 2
#define EVAL_VAR_NOAUTOLOAD 1
#define EVAL_VAR_IMPORT 2
#define EVAL_VAR_NO_FUNC 4
#define TFN_NO_AUTOLOAD 1
#define K_SPECIAL 128
#define AUTOLOAD_CHAR '@'
#define RE_MAGIC 1

#define CLEAR_FIELD(x) memset(&(x), 0, sizeof(x))
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define ASCII_ISUPPER(c) ((c) >= 'A' && (c) <= 'Z')
#define STRLEN(s) strlen((const char *)(s))
#define VIM_CLEAR(p) do { vim_free(p); (p) = NULL; } while (0)
#define UF2HIKEY(fp) ((char_u *)(fp)->uf_name)
#define FUNCLINE(fp, j) (((char_u **)(fp)->uf_lines.ga_data)[j])

static bool did_emsg = FALSE;
static bool p_ic = FALSE;
static bool got_int = FALSE;
static bool KeyTyped = FALSE;
static bool sandbox = FALSE;
static bool is_export = FALSE;
static script_ctx_T current_sctx = {0};
static char_u *SOURCING_NAME = NULL;
static linenr_T SOURCING_LNUM = 0;
static cstack_T *current_funccal = NULL;
static hashtab_T func_hashtab;

static const char *e_dictkey = "";
static const char *e_trailing_arg = "";
static const char *e_invarg2 = "";
static const char *e_redefining_script_item_str = "";
static const char *e_nobang = "";
static const char *e_no_white_space_allowed_before_str_str = "";
static const char *e_white_space_required_after_str_str = "";
static const char *e_expected_type_str = "";
static const char *e_funcdict = "";
static const char *e_funcexts = "";
static const char *e_name_already_defined_str = "";
static const char *e_no_white_space_allowed_before_colon_str = "";

static int cmdline_row = 0;
static int msg_row = 0;
static void *t_any;
static void *t_func_any;

static char_u *vim_strchr(const char_u *str, int c) {
    return (char_u *)strchr((const char *)str, c);
}

static char_u *vim_strsave(const char_u *str) {
    if (!str) return NULL;
    size_t len = strlen((const char *)str) + 1;
    char_u *ret = malloc(len);
    if (ret) memcpy(ret, str, len);
    return ret;
}

static char_u *vim_strnsave(const char_u *str, size_t len) {
    char_u *ret = malloc(len + 1);
    if (ret) {
        memcpy(ret, str, len);
        ret[len] = NUL;
    }
    return ret;
}

static int STRNCMP(const char_u *s1, const char_u *s2, size_t n) {
    return strncmp((const char *)s1, (const char *)s2, n);
}

static bool IS_WHITE_OR_NUL(int c) {
    return c == NUL || VIM_ISWHITE(c);
}

static void emsg(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}

static void *alloc_clear(size_t size) {
    void *p = malloc(size);
    if (p) memset(p, 0, size);
    return p;
}

static void vim_free(void *p) {
    free(p);
}

static void ga_init(garray_T *gap) {
    memset(gap, 0, sizeof(*gap));
}

static void ga_init2(garray_T *gap, int size, int grow) {
    memset(gap, 0, sizeof(*gap));
}

static void ga_clear_strings(garray_T *gap) {
    if (gap->ga_data) {
        free(gap->ga_data);
        gap->ga_data = NULL;
    }
}

static char_u *skipwhite(char_u *p) {
    while (VIM_ISWHITE(*p)) p++;
    return p;
}

static bool ends_excmd(int c) {
    return c == NUL || c == '|' || c == '\n';
}