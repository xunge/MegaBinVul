#include <stdbool.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef struct buf_T buf_T;
typedef struct tabpage_T tabpage_T;

#define FOR_ALL_TABPAGES(tp) for (tp = first_tabpage; tp != NULL; tp = tp->tp_next)
#define DB_COUNT 0
#define VALID 0

extern tabpage_T *first_tabpage;
extern tabpage_T *curtab;
extern bool need_diff_redraw;

int diff_buf_idx_tp(buf_T *buf, tabpage_T *tp);
void redraw_later(int flags);

struct tabpage_T {
    buf_T **tp_diffbuf;
    bool tp_diff_invalid;
    tabpage_T *tp_next;
};