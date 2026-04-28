#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define FORWARD 1
#define BACKWARD 0
#define MAXWLEN 256
#define FEAT_SYN_HL
#define NUL '\0'
#define HLF_COUNT 0
#define HLF_SPB 1

typedef unsigned char char_u;
typedef int linenr_T;
typedef int colnr_T;
typedef int hlf_T;

typedef struct {
    linenr_T lnum;
    colnr_T col;
    int coladd;
} pos_T;

typedef struct window_S win_T;
typedef struct buf_T {
    struct {
        int ml_line_count;
    } b_ml;
} buf_T;

struct window_S {
    buf_T *w_buffer;
    pos_T w_cursor;
};

extern win_T *curwin;
extern int p_ws;
extern int got_int;

#define CLEAR_POS(p) memset((p), 0, sizeof(pos_T))
#define STRLEN strlen
#define STRCPY strcpy
#define vim_free free
#define alloc malloc
#define ml_get_buf(buf, lnum, copy) NULL
#define no_spell_checking(wp) 0
#define spell_check(wp, p, attr, capcol, docap) 0
#define syntax_present(wp) 0
#define syn_get_id(wp, lnum, col, trans, can_spell, keep_state) 0
#define getwhitecols(line) 0
#define check_need_cap(lnum, col) 0
#define spell_cat_line(dest, src, maxlen)
#define shortmess(flag) 0
#define give_warning(msg, attr)
#define line_breakcheck()
#define skipwhite(p) (p)
#define _(msg) msg
static const char *top_bot_msg = "search hit TOP without match for";
static const char *bot_top_msg = "search hit BOTTOM without match for";