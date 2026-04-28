#include <stddef.h>
#include <string.h>

typedef unsigned char char_u;
typedef int cmdidx_T;
typedef int varnumber_T;

typedef struct type_S type_T;
typedef struct cctx_S cctx_T;
typedef struct lhs_S lhs_T;
typedef struct lvar_S lvar_T;
typedef struct imported_S imported_T;
typedef struct scriptitem_S scriptitem_T;
typedef struct svar_S svar_T;
typedef struct script_S script_S;

#define FALSE 0
#define TRUE 1
#define FAIL 1
#define OK 0
#define SKIP_YES 1
#define ASSIGN_FINAL 2
#define ASSIGN_CONST 1
#define ASSIGN_VAR 0
#define CMD_final 0
#define CMD_const 0
#define SCRIPT_VERSION_VIM9 0
#define VAR_STRING 0
#define VAR_ANY 0
#define VAR_FUNC 0
#define VAR_PARTIAL 0
#define SCRIPT_ID_VALID(x) (1)

enum {
    dest_local,
    dest_script,
    dest_option,
    dest_func_option,
    dest_global,
    dest_expr
};

struct type_S {
    int tt_type;
    type_T *tt_member;
};

struct lvar_S {
    int lv_idx;
    type_T *lv_type;
    int lv_from_outer;
};

struct lhs_S {
    int lhs_dest;
    int lhs_vimvaridx;
    int lhs_scriptvar_idx;
    int lhs_varlen;
    int lhs_varlen_total;
    char_u *lhs_name;
    int lhs_has_index;
    type_T *lhs_type;
    type_T *lhs_member_type;
    char_u *lhs_dest_end;
    char_u *lhs_end;
    int lhs_opt_flags;
    lvar_T *lhs_lvar;
    lvar_T lhs_local_lvar;
    lvar_T lhs_arg_lvar;
    int lhs_new_local;
    int lhs_has_type;
    int lhs_scriptvar_sid;
};

struct imported_S {
    int imp_sid;
};

struct scriptitem_S {
    struct {
        void *ga_data;
    } sn_var_vals;
};

struct svar_S {
    type_T *sv_type;
};

struct script_S {
    int sc_sid;
};

struct cctx_S {
    int ctx_skip;
    struct {
        int uf_script_ctx_version;
    } *ctx_ufunc;
    void *ctx_type_list;
};

extern type_T t_list_string;
extern type_T t_any;
extern script_S current_sctx;
extern int current_script_is_vim9(void);

#define CLEAR_POINTER(x) memset((x), 0, sizeof(*(x)))
#define CLEAR_FIELD(x) memset(&(x), 0, sizeof(x))
#define STRNCMP strncmp
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define _(x) x
#define e_str_is_used_as_argument ""
#define e_variable_already_declared ""
#define e_cannot_use_s_colon_in_vim9_script_str ""
#define e_cannot_declare_script_variable_in_function_str ""
#define e_variable_already_declared_in_script_str ""
#define e_unknown_variable_str ""
#define e_no_dot_after_imported_name_str ""
#define e_missing_name_after_imported_name_str ""
#define e_white_space_required_after_str_str ""
#define e_can_only_concatenate_to_string ""
#define e_cannot_use_operator_on_new_variable ""
#define e_cannot_use_index_when_declaring_variable ""

static char_u *skip_var_one(char_u *p, int skipwhite) { return p; }
static char_u *skip_option_env_lead(char_u *p) { return p; }
static char_u *to_name_end(char_u *p, int accept_dot) { return p; }
static char_u *skipwhite(char_u *p) { return p; }
static char_u *skip_index(char_u *p) { return p; }
static int is_decl_command(cmdidx_T cmdidx) { return 0; }
static int get_var_dest(char_u *name, int *dest, cmdidx_T cmdidx, int *opt_flags, int *vimvaridx, type_T **type, cctx_T *cctx) { return 0; }
static int check_reserved_name(char_u *name) { return 0; }
static int lookup_local(char_u *name, int len, lvar_T *lvar, cctx_T *cctx) { return 0; }
static int arg_exists(char_u *name, int len, int *idx, type_T **type, int *from_outer, cctx_T *cctx) { return 0; }
static int script_var_exists(char_u *name, int len, cctx_T *cctx, int *sid) { return 0; }
static imported_T *find_imported(char_u *name, int len, int script) { return NULL; }
static int get_script_item_idx(int sid, char_u *name, int assign, cctx_T *cctx, type_T **type) { return 0; }
static int check_defined(char_u *name, int len, cctx_T *cctx, int *sid, int script) { return 0; }
static void vim9_declare_error(char_u *name) {}
static type_T *parse_type(char_u **pp, void *type_list, int optional) { return NULL; }
static int var_wrong_func_name(char_u *name, int decl) { return 0; }
static lvar_T *reserve_local(cctx_T *cctx, char_u *name, int len, int assign, type_T *type) { return NULL; }
static char_u *vim_strnsave(char_u *str, int len) { return NULL; }
static char_u *vim_strchr(char_u *str, int c) { return NULL; }
static void vim_free(void *ptr) {}
static void semsg(const char *msg, ...) {}
static void emsg(const char *msg) {}
static scriptitem_T *SCRIPT_ITEM(int sid) { return NULL; }