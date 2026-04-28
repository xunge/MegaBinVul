#include <stddef.h>

typedef unsigned char char_u;

typedef struct script_ctx {
    int sc_lnum;
} script_ctx_T;

typedef struct {
    char_u *xp_arg;
    script_ctx_T xp_script_ctx;
    int xp_context;
} expand_T;

typedef struct {
    char_u *ga_data;
    int ga_len;
} garray_T;

typedef struct {
    garray_T b_ucmds;
} buf_T;

typedef struct {
    buf_T *w_buffer;
} win_T;

typedef struct {
    char_u *uc_name;
    int uc_argt;
    int uc_compl;
    char_u *uc_compl_arg;
    script_ctx_T uc_script_ctx;
    int uc_addr_type;
} ucmd_T;

typedef struct {
    char_u *cmd;
    int cmdidx;
    long argt;
    int useridx;
    int addr_type;
} exarg_T;

#define FALSE 0
#define TRUE 1
#define CMD_USER 0
#define CMD_USER_BUF 1
#define NUL '\0'
#define FEAT_CMDWIN
#define FEAT_EVAL
#define SOURCING_LNUM 0
#define EXPAND_UNSUCCESSFUL 0

extern buf_T *curbuf;
extern win_T *prevwin;
extern garray_T ucmds;

win_T *prevwin_curwin(void);
int vim_isdigit(int c);
int is_in_cmdwin(void);

#define USER_CMD_GA(gap, j) ((ucmd_T *)((gap)->ga_data) + (j))