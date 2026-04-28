#include <stddef.h>

typedef struct window_S win_T;
typedef struct frame_S frame_T;

struct frame_S {
    int fr_layout;
    int fr_width;
    int fr_height;
    win_T *fr_win;
    frame_T *fr_child;
    frame_T *fr_next;
    frame_T *fr_parent;
    int fr_newwidth;
    int fr_newheight;
};

struct window_S {
    int w_winrow;
    int w_wincol;
};

#define FR_LEAF 0
#define FR_ROW 1
#define FR_COL 2

#define FALSE 0
#define NOWIN NULL
#define UPD_NOT_VALID 0

extern int Columns;
extern int cmdline_row;
extern int p_wmw;
extern int p_wiw;
extern int p_wmh;
extern int p_wh;
extern int p_ls;

#define FOR_ALL_FRAMES(fr, start) for ((fr) = (start); (fr) != NULL; (fr) = (fr)->fr_next)

static int frame_minwidth(frame_T *fr, win_T *next_curwin);
static int frame_has_win(frame_T *fr, win_T *win);
static int frame_fixed_width(frame_T *fr);
static int frame_fixed_height(frame_T *fr);
static int frame_minheight(frame_T *fr, win_T *next_curwin);
static void frame_new_height(frame_T *fr, int height, int topfirst, int noheight);
static void frame_new_width(frame_T *fr, int width, int leftfirst, int nowidth);
static void redraw_all_later(int type);