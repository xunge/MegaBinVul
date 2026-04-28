#include <stddef.h>

typedef enum { QFLT_QUICKFIX } qfltype_T;

typedef struct qf_info_S {
    int qf_curlist;
} qf_info_T;

typedef struct qfline_S {
    int qf_type;
    int qf_fnum;
} qfline_T;

typedef struct qf_list_S {
    int qf_changedtick;
    qfltype_T qfl_type;
} qf_list_T;

typedef struct window_S {
    struct buf_T *w_buffer;
} win_T;

typedef struct buf_T {
    // buffer fields
} buf_T;

typedef struct cmdmod_S {
    int cmod_tab;
} cmdmod_T;

#define FAIL 1
#define OK 0
#define QF_ABORT 2
#define NOTDONE 3

extern win_T *curwin;
extern buf_T *curbuf;
extern cmdmod_T cmdmod;

static int bt_help(buf_T *buf) { return 0; }
static int bt_quickfix(buf_T *buf) { return 0; }
static int jump_to_help_window(qf_info_T *qi, int newwin, int *opened_window) { return 0; }
static int qf_jump_to_usable_window(int qf_fnum, int newwin, int *opened_window) { return 0; }
static int is_qf_entry_present(qf_list_T *qfl, qfline_T *qf_ptr) { return 1; }
static qf_list_T *qf_get_curlist(qf_info_T *qi) { return NULL; }
static void emsg(const char *str) {}
static char *_(const char *str) { return (char *)str; }

#define e_current_quickfix_list_was_changed "E925"
#define e_current_location_list_was_changed "E926"