#include <stddef.h>

typedef unsigned char char_u;
typedef int bool;
#define FALSE 0
#define TRUE 1
#define OK 1
#define FAIL 0
#define QF_ABORT 2
#define NOTDONE 3

struct qfline_S {
    int qf_fnum;
    void *qf_ptr;
};

struct qf_list_S {
    struct qfline_S *qf_ptr;
    int qf_index;
};

struct qf_info_S {
    struct qf_list_S *qf_curlist;
};

struct window_S {
    int w_id;
};

typedef struct qf_info_S qf_info_T;
typedef struct qf_list_S qf_list_T;
typedef struct qfline_S qfline_T;
typedef struct window_S win_T;

extern char_u *p_swb;
extern char_u *empty_option;
extern unsigned swb_flags;
extern int KeyTyped;
extern win_T *curwin;
extern qf_info_T ql_info;
extern char_u *e_no_errors;

#define _(x) x

static void emsg(char_u *msg);
static void incr_quickfix_busy(void);
static void decr_quickfix_busy(void);
static bool qf_stack_empty(qf_info_T *qi);
static bool qf_list_empty(qf_list_T *qfl);
static qf_list_T *qf_get_curlist(qf_info_T *qi);
static qfline_T *qf_get_entry(qf_list_T *qfl, int errornr, int dir, int *qf_index);
static bool qf_win_pos_update(qf_info_T *qi, int old_qf_index);
static int qf_jump_open_window(qf_info_T *qi, qfline_T *qf_ptr, int newwin, int *opened_window);
static int qf_jump_to_buffer(qf_info_T *qi, int qf_index, qfline_T *qf_ptr, int forceit, int prev_winid, int *opened_window, int old_KeyTyped, int print_message);
static void win_close(win_T *win, bool force);