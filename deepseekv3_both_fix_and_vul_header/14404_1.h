#include <stddef.h>
#include <stdint.h>

typedef unsigned int colnr_T;
typedef int bool;

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define TAB '\t'
#define MAXCOL ((colnr_T)-1)
#define CT_CELL_MASK 0x03
#define FEAT_VARTABS
#define FEAT_LINEBREAK
#define NORMAL 1

typedef unsigned char char_u;

typedef struct {
    int tab1;
} lcs_chars_T;

typedef struct {
    char_u *b_p_vts_array;
    int b_p_ts;
} buf_T;

typedef struct {
    buf_T *w_buffer;
    bool w_p_list;
    bool w_p_lbr;
    bool w_p_bri;
    bool w_p_wrap;
    lcs_chars_T w_lcs_chars;
} win_T;

typedef struct {
    colnr_T col;
    colnr_T lnum;
} pos_T;

extern char_u *ml_get_buf(buf_T *buf, colnr_T lnum, bool will_change);
extern int mb_head_off(char_u *line, char_u *posptr);
extern bool has_mbyte;
extern bool enc_utf8;
extern unsigned char g_chartab[];
extern int win_lbr_chartabsize(win_T *wp, char_u *line, char_u *ptr, colnr_T vcol, int *head);
extern bool in_win_border(win_T *wp, colnr_T vcol);
extern int utf_ptr2cells(char_u *ptr);
extern int MB_BYTE2LEN(int c);
extern void MB_PTR_ADV(char_u *ptr);
extern int State;
extern bool virtual_active();
extern bool VIsual_active;
extern char *p_sel;
extern pos_T VIsual;
#define LTOREQ_POS(a, b) ((a).lnum < (b).lnum || ((a).lnum == (b).lnum && (a).col <= (b).col))
extern char_u *get_showbreak_value(win_T *wp);
extern int tabstop_padding(colnr_T vcol, int ts, int *vts);