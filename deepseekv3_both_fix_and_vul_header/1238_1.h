#include <stddef.h>

typedef unsigned char char_u;

typedef struct cctx_S {
    int ctx_skip;
} cctx_T;

typedef struct lvar_S {
    int lv_from_outer;
    int lv_idx;
} lvar_T;

typedef struct type_S type_T;

typedef enum {
    dest_option,
    dest_func_option,
    dest_global,
    dest_buffer,
    dest_window,
    dest_tab,
    dest_script,
    dest_env,
    dest_reg,
    dest_vimvar,
    dest_local,
    dest_expr
} assign_dest_T;

#define AUTOLOAD_CHAR '#'
#define NUL '\0'
#define SKIP_YES 1

enum {
    ISN_LOADOPT,
    ISN_LOADG,
    ISN_LOADAUTO,
    ISN_LOADB,
    ISN_LOADW,
    ISN_LOADT,
    ISN_LOADENV,
    ISN_LOADREG,
    ISN_LOAD,
    ISN_LOADGDICT,
    ISN_LOADV
};

extern type_T t_dict_any;
extern type_T t_string;

char_u *vim_strchr(const char_u *string, int c);
void generate_LOAD(cctx_T *cctx, int isn, int arg, char_u *name, type_T *type);
void generate_LOADV(cctx_T *cctx, char_u *name);
void generate_LOADOUTER(cctx_T *cctx, int idx, int from_outer, type_T *type);
void generate_instr_type(cctx_T *cctx, int isn, type_T *type);
void compile_load_scriptvar(cctx_T *cctx, char_u *name, void *arg1, void *arg2);