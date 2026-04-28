#include <stddef.h>

typedef struct window_S {
    struct buf_S *w_buffer;
} window_T;

typedef struct tabpage_S {
    window_T *tp_curwin;
} tabpage_T;

typedef struct buf_S buf_T;

#define CHECK_CMDWIN
#define OK 1

extern tabpage_T *curtab;
extern buf_T *curbuf;

int leave_tabpage(buf_T *buf, int trigger_leave_autocmds);
int valid_tabpage(tabpage_T *tp);
void enter_tabpage(tabpage_T *tp, buf_T *buf, int trigger_enter_autocmds, int trigger_leave_autocmds);
void set_keep_msg(void *msg, int attr);