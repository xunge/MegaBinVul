#include <stddef.h>

typedef long linenr_T;

typedef struct {
    int lnum;
    int col;
} pos_T;

typedef struct {
    pos_T start;
    pos_T end;
    pos_T cursor_start;
    int line_count;
    int is_VIsual;
    int end_adjusted;
} oparg_T;

typedef struct {
    long ml_line_count;
} memline_T;

typedef struct {
    pos_T b_op_start;
    pos_T b_op_end;
    memline_T b_ml;
} buf_T;

typedef struct {
    pos_T w_cursor;
    long w_old_cursor_lnum;
    long w_old_visual_lnum;
} win_T;

typedef struct {
    unsigned int cmod_flags;
} cmdmod_T;

#define FAIL 1
#define CMOD_LOCKMARKS 0x01
#define INVERTED 1
#define BL_WHITE 0x01
#define BL_FIX 0x02

extern buf_T *curbuf;
extern win_T *curwin;
extern cmdmod_T cmdmod;
extern pos_T saved_cursor;

int u_save(linenr_T from, linenr_T to);
void format_lines(int line_count, int keep_cursor);
void redraw_curbuf_later(int flags);
void beginline(int flags);
void msgmore(long count);

#define FOR_ALL_WINDOWS(wp) for (wp = dummy_windows; wp < dummy_windows + 1; wp++)
extern win_T dummy_windows[1];