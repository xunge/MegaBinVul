#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE 1
#define FAIL -1
#define OK 0
#define MAXLNUM 0x7fffffff
#define DB_COUNT 2
#define NUL '\0'
#define CMD_diffget 0
#define CMD_diffput 1
#define EVENT_DIFFUPDATED 0

typedef unsigned int linenr_T;
typedef int bool;
typedef char char_u;

typedef struct buf_T buf_T;
typedef struct diff_T diff_T;
typedef struct exarg_T exarg_T;
typedef struct tabpage_T tabpage_T;
typedef struct window_T window_T;
typedef struct aco_save_T {
    int dummy;
} aco_save_T;

struct buf_T {
    int b_p_ma;
    int b_changed;
    struct {
        linenr_T ml_line_count;
    } b_ml;
};

struct diff_T {
    linenr_T df_lnum[DB_COUNT];
    int df_count[DB_COUNT];
    diff_T *df_next;
};

struct exarg_T {
    char_u *arg;
    int cmdidx;
    int addr_count;
    linenr_T line1;
    linenr_T line2;
};

struct tabpage_T {
    buf_T *tp_diffbuf[DB_COUNT];
    diff_T *tp_first_diff;
};

struct window_T {
    struct {
        linenr_T lnum;
    } w_cursor;
};

extern buf_T *curbuf;
extern tabpage_T *curtab;
extern window_T *curwin;
extern int diff_busy;
extern int diff_need_update;
extern int KeyTyped;

#define _(x) x
#define e_current_buffer_is_not_in_diff_mode "E1"
#define e_no_other_buffer_in_diff_mode_is_modifiable "E2"
#define e_no_other_buffer_in_diff_mode "E3"
#define e_more_than_two_buffers_in_diff_mode_dont_know_which_one_to_use "E4"
#define e_cant_find_buffer_str "E5"
#define e_buffer_str_is_not_in_diff_mode "E6"
#define e_buffer_changed_unexpectedly "E7"

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define BUFEMPTY() (curbuf->b_ml.ml_line_count == 0)
#define STRLEN(s) strlen((char *)(s))
#define vim_isdigit(c) isdigit((unsigned char)(c))

int diff_buf_idx(buf_T *buf);
int diff_check(window_T *win, linenr_T lnum);
void emsg(const char *msg);
void semsg(const char *msg, const char *arg);
void change_warning(int n);
int u_save(linenr_T start, linenr_T end);
int ml_delete(linenr_T lnum);
char_u *ml_get_buf(buf_T *buf, linenr_T lnum, int will_change);
int ml_append(linenr_T lnum, char_u *line, int len, int newfile);
void vim_free(void *ptr);
void mark_adjust(linenr_T line1, linenr_T line2, long amount, long amount_after);
void changed_lines(linenr_T lnum, long col, linenr_T lnume, long xtra);
int valid_diff(diff_T *dp);
void aucmd_prepbuf(aco_save_T *aco, buf_T *buf);
void aucmd_restbuf(aco_save_T *aco);
void u_sync(int force);
void check_cursor();
void changed_line_abv_curs();
void diff_redraw(int do_update);
void apply_autocmds(int event, char *pat, char *cmd, int force, buf_T *buf);
void ex_diffupdate(exarg_T *eap);
int diff_equal_entry(diff_T *dp, int idx1, int idx2);
char_u *vim_strsave(const char_u *str);
int buflist_findpat(char_u *arg, char_u *p, int f1, int f2, int f3);
buf_T *buflist_findnr(int i);