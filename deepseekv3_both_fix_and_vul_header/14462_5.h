#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char char_u;
typedef int linenr_T;
typedef int bool;
typedef struct exarg exarg_T;
typedef struct ufunc ufunc_T;
typedef struct garray garray_T;
typedef struct dictitem dictitem_T;
typedef struct funcdict funcdict_T;
typedef struct hashitem hashitem_T;
typedef struct imported imported_T;
typedef struct regmatch regmatch_T;
typedef struct cstack cstack_T;
typedef struct hashtab hashtab_T;
typedef struct dictvar dictvar_T;

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define FAIL 1
#define OK 0
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
#define TFN_NO_AUTOLOAD 1
#define EVAL_VAR_NOAUTOLOAD 1
#define EVAL_VAR_IMPORT 2
#define EVAL_VAR_NO_FUNC 4
#define AUTOLOAD_CHAR '#'
#define CMD_function 1
#define CMD_def 2
#define K_SPECIAL 128
#define RE_MAGIC 1

struct exarg {
    char_u *cmd;
    char_u *arg;
    int skip;
    int forceit;
    int cmdidx;
    cstack_T *cstack;
    char_u *nextcmd;
};

struct garray {
    void *ga_data;
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
};

struct typval {
    int v_type;
    int v_lock;
    union {
        char_u *v_string;
        long v_number;
    } vval;
};

struct script_ctx {
    int sc_sid;
    int sc_seq;
    int sc_version;
    linenr_T sc_lnum;
};

struct ufunc {
    char_u *uf_name;
    char_u *uf_name_exp;
    garray_T uf_args;
    garray_T uf_def_args;
    int uf_varargs;
    int uf_flags;
    int uf_calls;
    int uf_cleared;
    int uf_refcount;
    int uf_def_status;
    garray_T uf_lines;
    void *uf_scoped;
    void *uf_ret_type;
    void *uf_func_type;
    void *uf_arg_types;
    struct script_ctx uf_script_ctx;
    int uf_script_ctx_version;
};

struct dictitem {
    struct typval di_tv;
    int di_flags;
};

struct funcdict {
    struct dictvar *fd_dict;
    struct dictitem *fd_di;
    char_u *fd_newkey;
};

struct hashitem {
    void *hi_key;
};

struct imported {
    char_u *imp_name;
};

struct regmatch {
    void *regprog;
    int rm_ic;
};

struct cstack {
    int cs_idx;
};

struct hashtab {
    struct hashitem *ht_array;
    int ht_used;
    int ht_mask;
};

struct dictvar {
    int dv_scope;
    int dv_lock;
};

struct type {
    int dummy;
};

static int in_vim9script(void) { return 0; }
static int ends_excmd2(char_u *cmd, char_u *arg) { return 0; }
static void list_functions(void *match) {}
static void set_nextcmd(exarg_T *eap, char_u *arg) {}
static char_u *skip_regexp(char_u *arg, char delim, int magic) { return NULL; }
static void *vim_regcomp(char_u *pattern, int flags) { return NULL; }
static void vim_regfree(void *prog) {}
static int p_ic = 0;
static void semsg(const char *msg, ...) {}
static void emsg(const char *msg) {}
static void emsg_funcname(const char *msg, char_u *name) {}
static char_u *save_function_name(char_u **p, int *is_global, int skip, int flags, funcdict_T *fudi) { return NULL; }
static char_u *vim_strchr(char_u *str, int c) { return NULL; }
static int aborting(void) { return 0; }
static int did_emsg = 0;
static void ga_init(garray_T *gap) {}
static void ga_init2(garray_T *gap, int size, int grow) {}
static void ga_clear_strings(garray_T *gap) {}
static char_u *skipwhite(char_u *p) { return p; }
static int IS_WHITE_OR_NUL(int c) { return 0; }
static int STRNCMP(char_u *s1, char_u *s2, int n) { return 0; }
static int VIM_ISWHITE(int c) { return 0; }
static int KeyTyped = 0;
static int msg_row = 0;
static int cmdline_row = 0;
static void msg_putchar(char c) {}
static void msg_outnum(long n) {}
static void msg_prt_line(char_u *line, int list) {}
static void out_flush(void) {}
static void ui_breakcheck(void) {}
static void msg_puts(const char *s) {}
static ufunc_T *find_func(char_u *name, int is_global, void *cctx) { return NULL; }
static char_u *untrans_function_name(char_u *name) { return NULL; }
static void list_func_head(ufunc_T *fp, int verbose) {}
static char_u *FUNCLINE(ufunc_T *fp, int j) { return NULL; }
static int got_int = 0;
static ufunc_T *find_func_even_dead(char_u *name, int is_global, void *cctx) { return NULL; }
static imported_T *find_imported(char_u *name, int flags, void *cctx) { return NULL; }
static struct script_ctx current_sctx;
static int sandbox = 0;
static int is_export = 0;
static int current_funccal = 0;
static char_u *SOURCING_NAME = NULL;
static linenr_T SOURCING_LNUM = 0;
static int eval_isnamec1(int c) { return 0; }
static int eval_isnamec(int c) { return 0; }
static int eval_variable(char_u *name, int len, int flags, void *rettv, void *cctx, int opt) { return 0; }
static int value_check_lock(int lock, char_u *arg, int verbose) { return 0; }
static char_u *autoload_name(char_u *name) { return NULL; }
static int fnamecmp(char_u *p1, char_u *p2) { return 0; }
static ufunc_T *alloc_clear(size_t size) { return NULL; }
static dictitem_T *dictitem_alloc(char_u *key) { return NULL; }
static int dict_add(void *dict, dictitem_T *di) { return 0; }
static void clear_tv(struct typval *tv) {}
static void set_ufunc_name(ufunc_T *fp, char_u *name) {}
static hashitem_T *hash_find(void *ht, char_u *key) { return NULL; }
static int hash_add(void *ht, void *key) { return 0; }
static int register_closure(ufunc_T *fp) { return 0; }
static int prof_def_func(void) { return 0; }
static void func_do_profile(ufunc_T *fp) {}
static void function_using_block_scopes(ufunc_T *fp, cstack_T *cstack) {}
static int parse_argument_types(ufunc_T *fp, garray_T *argtypes, int varargs) { return 0; }
static int parse_return_type(ufunc_T *fp, char_u *ret_type) { return 0; }
static void set_function_type(ufunc_T *fp) {}
static void func_clear_items(ufunc_T *fp) {}
static char_u *vim_strsave(char_u *str) { return NULL; }
static char_u *vim_strnsave(char_u *str, int len) { return NULL; }
static char_u *vim_strdup(char_u *str) { return NULL; }
static void vim_free(void *ptr) {}
static char_u *skip_type(char_u *p, int optional) { return p; }
static int get_function_args(char_u **arg, int termchar, garray_T *newargs, garray_T *argtypes, int skip, void *cctx, int *varargs, garray_T *default_args, int skip_flag, exarg_T *eap, char_u **line_to_free) { return 0; }
static int get_function_body(exarg_T *eap, garray_T *newlines, char_u *line_arg, char_u **line_to_free) { return 0; }
static struct hashtab func_hashtab;
static void *UF2HIKEY(ufunc_T *fp) { return (void *)fp; }
static void CLEAR_FIELD(funcdict_T fudi) {}
static int ends_excmd(int c) { return 0; }
static int ASCII_ISUPPER(int c) { return 0; }
static size_t STRLEN(const char_u *str) { return 0; }
static void VIM_CLEAR(void *p) {}
static dictitem_T *find_var(char_u *name, hashtab_T **ht, int alloc) { return NULL; }

// Error message constants
static const char *e_key_not_present_in_dictionary = "";
static const char *e_trailing_characters_str = "";
static const char *e_undefined_function_str = "";
static const char *e_missing_paren_str = "";
static const char *e_no_white_space_allowed_before_str_str = "";
static const char *e_no_bang_allowed = "";
static const char *e_invalid_argument_str = "";
static const char *e_redefining_script_item_str = "";
static const char *e_cannot_use_g_here = "";
static const char *e_no_white_space_allowed_before_colon_str = "";
static const char *e_white_space_required_after_str_str = "";
static const char *e_expected_type_str = "";
static const char *e_closure_function_should_not_be_at_top_level = "";
static const char *e_dictionary_entry_already_exists = "";
static const char *e_function_str_already_exists_add_bang_to_replace = "";
static const char *e_function_name_conflicts_with_variable_str = "";
static const char *e_name_already_defined_str = "";
static const char *e_cannot_redefine_function_str_it_is_in_use = "";
static const char *e_function_name_does_not_match_script_file_name_str = "";

// Type definitions
static struct type t_any;
static struct type t_func_any;