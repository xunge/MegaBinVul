#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define CAR '\r'
#define NL '\n'
#define Ctrl_E 5
#define Ctrl_Y 25
#define Ctrl_C 3
#define K_KENTER 0
#define CTRL_X_NORMAL 0
#define CTRL_X_WHOLE_LINE 1
#define SHM_COMPLETIONMENU 0
#define EVENT_COMPLETEDONEPRE 0
#define EVENT_COMPLETEDONE 0
#define FEAT_CMDWIN 0
#define KEY_COMPLETE 0

typedef unsigned char char_u;

struct compl_match {
    char_u *cp_str;
    struct compl_match *next;
};

struct window {
    struct cursor {
        int col;
    } w_cursor;
};

static struct compl_match *compl_curr_match;
static struct compl_match *compl_first_match;
static char_u *compl_leader;
static char_u *compl_orig_text;
static int compl_used_match;
static int compl_cont_mode;
static int compl_started;
static int compl_matches;
static int compl_enter_selects;
static struct window *curwin;
static int arrow_used;
static int ctrl_x_mode;
static char *edit_submode;
static int cmdwin_type;

static int pum_visible(void) { return 0; }
static int get_can_cindent(void) { return 0; }
static int cindent_on(void) { return 0; }
static void ins_compl_fixRedoBufForLeader(char_u *ptr) {}
static void do_c_expr_indent(void) {}
static void dec_cursor(void) {}
static int ins_need_undo_get(void) { return 0; }
static void insertchar(char c, int a, int b) {}
static void inc_cursor(void) {}
static char_u *ml_get_curline(void) { return NULL; }
static void ins_compl_delete(void) {}
static int get_compl_len(void) { return 0; }
static void ins_bytes(char_u *str) {}
static void auto_format(int a, int b) {}
static void ins_apply_autocmds(int event) {}
static void ins_compl_free(void) {}
static int shortmess(int flag) { return 0; }
static void msg_clr_cmdline(void) {}
static void showmode(void) {}
static void update_screen(int a) {}
static int in_cinkeys(int key, char c, int b) { return 0; }
static int inindent(int a) { return 0; }