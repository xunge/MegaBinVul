#include <stddef.h>

typedef struct window_S win_T;

struct window_S {
    int w_skipcol;
    int w_width;
};

int win_col_off(win_T *wp);
int win_col_off2(win_T *wp);