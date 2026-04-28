#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef int linenr_T;
typedef unsigned char char_u;
typedef int bool;

#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define MAXLNUM INT_MAX
#define DB_COUNT 3
#define NUL '\0'
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')
#define EVENT_DIFFUPDATED 0

typedef struct buf_T buf_T;
typedef struct diff_T diff_T;
typedef struct exarg_T exarg_T;
typedef struct tabpage_T tabpage_T;
typedef struct window_T window_T;
typedef struct aco_save_T aco_save_T;
typedef struct memline_T memline_T;

struct memline_T {
    linenr_T ml_line_count;
};

struct buf_T {
    int b_p_ma;
    int b_changed;
    memline_T b_ml;
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

struct aco_save_T {
    int dummy;
};

extern buf_T *curbuf;
extern tabpage_T *curtab;
extern window_T *curwin;
extern int diff_busy;
extern int diff_need_update;
extern int KeyTyped;

#define CMD_diffget 0
#define CMD_diffput 1

#define _(x) x
#define e_current_buffer_is_not_in_diff_mode "E_current_buffer_is_not_in_diff_mode"
#define e_no_other_buffer_in_diff_mode_is_modifiable "E_no_other_buffer_in_diff_mode_is_modifiable"
#define e_no_other_buffer_in_diff_mode "E_no_other_buffer_in_diff_mode"
#define e_more_than_two_buffers_in_diff_mode_dont_know_which_one_to_use "E_more_than_two_buffers_in_diff_mode_dont_know_which_one_to_use"
#define e_cant_find_buffer_str "E_cant_find_buffer_str"
#define e_buffer_str_is_not_in_diff_mode "E_buffer_str_is_not_in_diff_mode"
#define e_buffer_changed_unexpectedly "E_buffer_changed_unexpectedly"

#define STRLEN(x) strlen((char*)(x))
#define vim_isdigit(c) isdigit((unsigned char)(c))
#define BUFEMPTY() (curbuf->b_ml.ml_line_count == 0)

int diff_buf_idx(buf_T *buf);
int diff_check(window_T *win, linenr_T lnum);
int diff_equal_entry(diff_T *dp, int idx1, int idx2);
void emsg(const char *msg);
void semsg(const char *msg, const char *arg);
void change_warning(int n);
int u_save(linenr_T start, linenr_T end);
void ml_delete(linenr_T lnum);
char_u *vim_strsave(const char_u *str);
char_u *ml_get_buf(buf_T *buf, linenr_T lnum, int will_change);
void ml_append(linenr_T lnum, char_u *line, int len, int newfile);
void vim_free(void *ptr);
void mark_adjust(linenr_T lnum, linenr_T end, long amount, long amount_after);
void changed_lines(linenr_T lnum, linenr_T end, linenr_T extra, long count);
void check_cursor(void);
void changed_line_abv_curs(void);
void diff_redraw(int force);
void apply_autocmds(int event, char *pat, char *cmd, int force, buf_T *buf);
void aucmd_prepbuf(aco_save_T *aco, buf_T *buf);
void aucmd_restbuf(aco_save_T *aco);
int u_sync(int force);
void ex_diffupdate(exarg_T *eap);
long atol(const char *nptr);
int buflist_findpat(char_u *arg, char_u *p, int unlisted, int diffmode, int curbuf);
buf_T *buflist_findnr(int nr);