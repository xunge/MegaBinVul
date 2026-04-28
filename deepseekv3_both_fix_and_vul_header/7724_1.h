#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FEAT_SEARCHPATH
#define FEAT_FIND_ID
#define FEAT_QUICKFIX
#define FEAT_GUI
#define FEAT_CMDWIN

#define TRUE 1
#define FALSE 0
#define NUL '\0'
#define MAXLNUM 0
#define OK 1
#define FAIL 0
#define WSP_VERT 1
#define WSP_TOP 2
#define WSP_BOT 4
#define FIND_DEFINE 0
#define FIND_ANY 1
#define FIND_IDENT 2
#define ACTION_SPLIT 1
#define ECMD_LASTL 1
#define ECMD_HIDE 2
#define GETF_ALT 1
#define BL_SOL 1
#define BL_FIX 2
#define Ctrl_S 19
#define Ctrl_V 22
#define Ctrl_HAT 30
#define Ctrl_N 14
#define Ctrl_Q 17
#define Ctrl_C 3
#define Ctrl_Z 26
#define Ctrl_O 15
#define Ctrl_W 23
#define Ctrl_J 10
#define Ctrl_K 11
#define Ctrl_H 8
#define Ctrl_L 12
#define Ctrl_T 20
#define Ctrl_B 2
#define Ctrl_P 16
#define Ctrl_X 24
#define Ctrl_R 18
#define Ctrl__ 31
#define Ctrl_F 6
#define Ctrl_I 9
#define Ctrl_D 4
#define Ctrl_G 7
#define Ctrl_RSB 29
#define K_DOWN 258
#define K_UP 259
#define K_LEFT 260
#define K_RIGHT 261
#define K_BS 263
#define K_KENTER 266
#define CAR '\r'
#define TAB '\t'

typedef unsigned char char_u;
typedef long linenr_T;

typedef struct window_S win_T;
typedef struct tabpage_S tabpage_T;
typedef struct cmdmod_T {
    int cmod_tab;
} cmdmod_T;
typedef struct pos {
    linenr_T lnum;
} pos_T;

extern win_T *firstwin;
extern win_T *lastwin;
extern win_T *curwin;
extern win_T *prevwin;
extern tabpage_T *curtab;
extern cmdmod_T cmdmod;
extern int cmdwin_type;
extern int p_pvh;
extern int g_do_tagpreview;
extern int postponed_split;
extern int need_mouse_correct;
extern int ONE_WINDOW;
extern int dont_scroll;
extern int no_mapping;
extern int allow_keys;

struct window_S {
    win_T *w_next;
    win_T *w_prev;
    int w_p_pvw;
    int w_height;
    int w_width;
    long w_alt_fnum;
    pos_T w_cursor;
    int w_set_curswant;
};

struct tabpage_S {
    tabpage_T *tp_next;
};

int tabpage_index(tabpage_T *tp) { return 0; }

#define ERROR_IF_ANY_POPUP_WINDOW 0
#define curbuf ((void*)0)
#define curbuf_locked() 0
#define valid_tabpage(tp) 1
#define win_valid(win) 1
#define one_window() 0
#define FOR_ALL_WINDOWS(wp) for (wp = firstwin; wp != NULL; wp = wp->w_next)
#define LANGMAP_ADJUST(c, condition) 
#define RESET_BINDING(win) 
#define STRCAT(d, s) strcat((char *)d, s)
#define _(s) s
#define e_invalid_in_cmdline_window "E11: Invalid in command-line window"
#define e_no_alternate_file "E23: No alternate file"
#define e_buffer_nr_not_found "E92: Buffer %ld not found"
#define e_there_is_no_preview_window "E249: There is no preview window"
#define m_onlyone "Only one window"

void reset_VIsual_and_resel(void);
int win_split(int size, int flags);
int buflist_findnr(long fnum);
void buflist_getfile(long fnum, linenr_T lnum, int flags, int forceit);
void win_goto(win_T *wp);
void win_goto_ver(int up, long count);
void win_goto_hor(int left, long count);
int win_new_tabpage(int size);
void goto_tabpage_tp(tabpage_T *tp, int trigger_enter, int trigger_leave);
void win_close(win_T *wp, int forceit);
void win_exchange(long Prenum);
void win_rotate(int backwards, int count);
void win_totop(int size, int flags);
void win_equal(win_T *wp, int current, int dir);
void win_setheight(int height);
void win_setwidth(int width);
void do_cmdline_cmd(char_u *cmd);
void cmd_with_count(char *cmd, char_u *buf, int buflen, long Prenum);
int bt_quickfix(void *buf);
void qf_view_result(int newwin);
char_u *grab_file_name(long count, linenr_T *lnum);
int do_ecmd(int fnum, char_u *fname, void *sfname, void *cmd, int opt, int flags, void *cmod);
void setpcmark(void);
void goto_tabpage_win(tabpage_T *tp, win_T *wp);
int find_ident_under_cursor(char_u **ptr, int what);
void find_pattern_in_path(char_u *ptr, int len, int whole, int no_bs, int findall, int type, long count, int action, linenr_T start_lnum, linenr_T end_lnum);
void do_nv_ident(int c1, int c2);
int goto_tabpage(int n);
int goto_tabpage_lastused(void);
void emsg(char *s);
void semsg(char *s, long n);
void msg(char *s);
void beep_flush(void);
void check_cursor_lnum(void);
void beginline(int flags);
int plain_vgetc(void);
int add_to_showcmd(int c);
int vim_snprintf(char *str, size_t size, const char *format, ...);
char_u *vim_strnsave(char_u *str, int len);
void vim_free(void *ptr);