#include <stdbool.h>

typedef int colnr_T;
typedef unsigned char char_u;

struct cursor_pos {
    colnr_T col;
};

struct window {
    struct cursor_pos w_cursor;
    int w_wrow;
    int w_wcol;
    int w_width;
    int w_virtcol;
};

extern struct window *curwin;
extern bool has_mbyte;
extern int dollar_vcol;
extern bool FALSE;

int redrawing(void);
void cursor_off(void);
char_u *ml_get_curline(void);
int (*mb_head_off)(char_u *p, char_u *s);
void curs_columns(bool compute);
void edit_putchar(char c, bool invert);