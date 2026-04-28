#include <stddef.h>

typedef unsigned char char_u;
typedef long unsigned int long_u;

#define MAXCOL 0x7FFFFFFF
#define NUL '\0'
#define FALSE 0
#define TRUE 1

#define P_ALLOCED 0x01
#define P_SECURE 0x02
#define P_INSECURE 0x04
#define P_CURSWANT 0x08
#define P_RALL 0x10

#define OPT_LOCAL 0x01
#define OPT_GLOBAL 0x02
#define OPT_NO_REDRAW 0x04

typedef enum {
    OP_ADDING,
    OP_PREPENDING,
    OP_REMOVING
} set_op_T;

typedef struct {
    char_u *os_varp;
    int os_idx;
    int os_flags;
    set_op_T os_op;
    union {
        char_u *string;
    } os_oldval;
    union {
        char_u *string;
    } os_newval;
    char *os_errbuf;
    int os_errbuflen;
    int os_value_checked;
    int os_restore_chartab;
    int os_value_changed;
    int os_did_swaptcap;
} optset_T;

typedef char *(*opt_did_set_cb_T)(optset_T *);

extern char_u T_NAME;
extern char_u *p_hl;
extern char_u *p_mouse;
extern char_u *p_go;
extern char_u *p_guifont;
extern char_u *p_rtp;
extern char_u *p_flp;
extern char_u *empty_option;
extern char *e_not_allowed_here;
extern char *e_invalid_argument;

extern int secure;
extern int sandbox;
extern int gui_in_use;

struct window {
    char_u *w_s;
    int w_briopt_list;
    int w_curswant;
    int w_set_curswant;
};
extern struct window *curwin;

struct buffer {
    char_u *b_p_syn;
    char_u *b_p_ft;
    char_u *b_p_flp;
    char_u *b_p_spl;
};
extern struct buffer *curbuf;

int get_option_flags(int opt_idx);
opt_did_set_cb_T get_option_did_set_cb(int opt_idx);
int findoption(char_u *name);
int check_illegal_path_names(int opt_idx, char_u **varp);
void free_string_option(char_u *p);
void set_option_flag(int opt_idx, int flag);
int is_global_local_option(int opt_idx);
char_u *get_option_varp_scope(int opt_idx, int scope);
void set_string_option_global(int opt_idx, char_u **varp);
void setmouse(void);
void mch_setmouse(int flag);
void check_redraw(int flags);
void init_highlight(int force, int reset);
void highlight_changed(void);
void init_chartab(void);
void redraw_all_later(int flags);
void set_termname(char_u *name);
void update_package_paths_in_lua(void);
void do_syntax_autocmd(int changed);
void do_filetype_autocmd(char_u **varp, int opt_flags, int changed);
void do_spelllang_source(void);
void set_option_sctx_idx(int opt_idx, int opt_flags, void *sctx);