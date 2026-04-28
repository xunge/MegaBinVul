#include <stddef.h>

typedef unsigned char char_u;

typedef struct typval_S {
    int v_type;
    union {
        char_u *v_string;
    } vval;
} typval_T;

typedef struct exarg_S {
    char_u *cmd;
    int cmdidx;
    int addr_count;
    int useridx;
} exarg_T;

typedef enum { FAIL } VimStatus;
typedef enum { FALSE, TRUE } Bool;
typedef enum { CMD_SIZE } cmdidx_T;
typedef enum { CMOD_VIM9CMD, CMOD_LEGACY } cmdmod_flags_T;

struct cmdmod {
    cmdmod_flags_T cmod_flags;
};

struct cmdname {
    char_u *cmd_name;
};

extern struct cmdmod cmdmod;
extern int emsg_silent;
extern struct cmdname cmdnames[];
extern int in_vim9script(void);
extern VimStatus check_for_string_arg(typval_T *, int);
extern VimStatus check_for_opt_bool_arg(typval_T *, int);
extern int tv_get_bool(typval_T *);
extern char_u *skip_range(char_u *, Bool, void *);
extern char_u *find_ex_command(exarg_T *, char_u **, char_u **, int *);
extern int not_in_vim9(exarg_T *);
extern char_u *vim_strsave(char_u *);
extern char_u *get_user_command_name(int, cmdidx_T);

#define IS_USER_CMDIDX(x) (0)
#define VAR_UNKNOWN 0
#define VAR_STRING 1