#include <stdio.h>
#include <string.h>

#define UNUSED
#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define MAXPATHL 256
#define FEAT_STL_OPT
#define FEAT_QUICKFIX
#define FEAT_TERMINAL
#define FEAT_CMDL_INFO

typedef struct window_S win_T;
typedef struct buffer_S buf_T;
typedef unsigned char char_u;

struct window_S {
    int w_redr_status;
    int w_status_height;
    int w_width;
    int w_wincol;
    int w_vsep_width;
    buf_T *w_buffer;
    char *w_p_stl;
    int w_p_pvw;
};

struct buffer_S {
    int b_p_ro;
    char *b_p_stl;
};

extern int statusline_row(win_T *wp);
extern int redrawing(void);
extern int pum_visible(void);
extern void redraw_custom_statusline(win_T *wp);
extern int fillchar_status(int *attr, win_T *wp);
extern void get_trans_bufname(buf_T *buf);
extern int bt_help(buf_T *buf);
extern int bufIsChanged(buf_T *buf);
extern int bt_terminal(buf_T *buf);
extern int has_mbyte;
extern int mb_string2cells(char_u *p, int len);
extern int (*mb_ptr2len)(char_u *p);
extern int (*mb_ptr2cells)(char_u *p);
extern void screen_puts(char_u *p, int row, int col, int attr);
extern void screen_fill(int start_row, int end_row, int start_col, int end_col, int fillchar1, int fillchar2, int attr);
extern int get_keymap_str(win_T *wp, char_u *fmt, char_u *buf, int len);
extern void win_redr_ruler(win_T *wp, int flag, int ignore_pum);
extern int stl_connected(win_T *wp);
extern int fillchar_vsep(int *attr);
extern void screen_putchar(int c, int row, int col, int attr);
extern int W_ENDCOL(win_T *wp);

extern char_u NameBuff[MAXPATHL];
extern int redraw_cmdline;
extern int ru_col;
extern int Columns;
extern char *p_stl;
extern char *_(const char *str);
extern int vim_snprintf(char *str, size_t size, const char *format, ...);
#define STRLEN strlen