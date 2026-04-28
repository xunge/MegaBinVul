#include <stddef.h>

typedef long linenr_T;

typedef struct buf_S {
    struct {
        linenr_T ml_line_count;
    } b_ml;
    long changedtick;
} buf_T;

typedef struct win_S {
    int w_id;
    void *w_llist;
    linenr_T w_botline;
} win_T;

typedef struct qf_info_S qf_info_T;
typedef struct qfline_S qfline_T;
typedef struct aco_save_S {
    int dummy;
} aco_save_T;

#define IS_LL_STACK(qi) ((qi) != NULL)
#define CHANGEDTICK(buf) ((buf)->changedtick)
#define UPD_NOT_VALID (1)

extern buf_T *qf_find_buf(qf_info_T *qi);
extern win_T *qf_find_win_with_loclist(qf_info_T *qi);
extern win_T *qf_find_win(qf_info_T *qi);
extern void aucmd_prepbuf(aco_save_T *aco, buf_T *buf);
extern void qf_update_win_titlevar(qf_info_T *qi);
extern void qf_fill_buffer(void *list, buf_T *buf, qfline_T *old_last, int qf_winid);
extern void *qf_get_curlist(qf_info_T *qi);
extern int qf_win_pos_update(qf_info_T *qi, int flags);
extern void aucmd_restbuf(aco_save_T *aco);
extern void redraw_buf_later(buf_T *buf, int type);

extern win_T *curwin;