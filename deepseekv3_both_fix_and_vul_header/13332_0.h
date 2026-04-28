#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define QF_FAIL 1
#define MAX_FUZZY_MATCHES 256
#define VGR_FUZZY (1 << 0)
#define VGR_GLOBAL (1 << 1)

typedef unsigned char char_u;
typedef long colnr_T;
typedef unsigned int int_u;

typedef struct {
    int col;
    int lnum;
} pos_T;

typedef struct {
    pos_T startpos[10];
    pos_T endpos[10];
} regmmatch_T;

typedef struct buf_T {
    int b_fnum;
    struct {
        long ml_line_count;
    } b_ml;
} buf_T;

typedef struct qf_list_T {
    // dummy structure
} qf_list_T;

typedef struct window_S {
    // dummy structure
} win_T;

extern win_T *curwin;
extern int got_int;

char_u *ml_get_buf(buf_T *buf, long lnum, int will_change);
int vim_regexec_multi(regmmatch_T *rmp, win_T *win, buf_T *buf, long lnum, colnr_T col, void *timed_out);
int fuzzy_match(char_u *str, char_u *pat, int match_at_start, int *score, int_u *matches, int_u sz);
int qf_add_entry(qf_list_T *qfl, char_u *dir, char_u *fname, char_u *module, int bufnum, char_u *text, long lnum, long end_lnum, long col, long end_col, int vis_col, char_u *searchpat, int nr, int type, int valid);
void line_breakcheck(void);