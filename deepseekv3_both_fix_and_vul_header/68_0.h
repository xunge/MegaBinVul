#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define MAXLNUM 0x7FFFFFFF
#define DB_COUNT 3

typedef long linenr_T;

typedef struct diff_S diff_T;
struct diff_S {
    linenr_T df_lnum[DB_COUNT];
    long df_count[DB_COUNT];
    diff_T *df_next;
};

typedef struct tabpage_S tabpage_T;
struct tabpage_S {
    diff_T *tp_first_diff;
    void *tp_diffbuf[DB_COUNT];
    int tp_diff_invalid;
    int tp_diff_update;
};

extern tabpage_T *curtab;
extern int diff_internal(void);
extern int diff_busy;
extern diff_T *diff_alloc_new(tabpage_T *tp, diff_T *dprev, diff_T *dp);
extern void diff_check_unchanged(tabpage_T *tp, diff_T *dp);
extern void vim_free(void *ptr);
extern int need_diff_redraw;
extern int diff_need_scrollbind;