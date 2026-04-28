#include <stddef.h>

typedef enum {
    QFLT_LOCATION,
    QFLT_QUICKFIX
} qfltype_T;

typedef struct qf_info_T {
    int qf_curlist;
} qf_info_T;

typedef struct qfline_T {
    int qf_type;
    int qf_fnum;
} qfline_T;

typedef struct qf_list_T {
    int qf_changedtick;
    qfltype_T qfl_type;
    int qf_id;
} qf_list_T;

typedef struct win_T {
    int w_id;
    struct qf_info_T *w_llist;
} win_T;

typedef struct buf_T buf_T;
typedef int linenr_T;

#define OK 1
#define FAIL 0
#define QF_ABORT 2
#define NOTDONE 3
#define FALSE 0
#define TRUE 1

#define ECMD_HIDE 0x01
#define ECMD_SET_HELP 0x02
#define GETF_SETMARK 0x01
#define GETF_SWITCH 0x02

extern buf_T *curbuf;
extern win_T *curwin;

extern const char *e_current_window_was_closed;
extern const char *e_current_quickfix_list_was_changed;
extern const char *e_current_location_list_was_changed;

#define _(x) x

qf_list_T *qf_get_curlist(qf_info_T *qi);
int can_abandon(buf_T *buf, int forceit);
void no_write_message(void);
int do_ecmd(int fnum, char *fname, char *cmd, char *arg, linenr_T lnum, int flags, win_T *win);
int buflist_getfile(int fnum, linenr_T lnum, int flags, int forceit);
win_T *win_id2wp(int id);
void emsg(const char *str);
int is_qf_entry_present(qf_list_T *qfl, qfline_T *qf_ptr);
int qflist_valid(qf_info_T *qi, int qfid);