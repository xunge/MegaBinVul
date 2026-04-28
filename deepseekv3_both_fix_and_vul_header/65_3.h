#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define NUL '\0'
#define MAX_MCO 6
#define BO_BS 0
#define BS_START 0
#define BS_INDENT 0
#define BS_EOL 0
#define BS_NOSTOP 0
#define BACKSPACE_CHAR 0
#define BACKSPACE_WORD 0
#define BACKSPACE_WORD_NOT_SPACE 0
#define BACKSPACE_LINE 0
#define REPLACE_FLAG 0
#define VREPLACE_FLAG 0
#define MODE_NORMAL 0
#define CPO_BACKSPACE 0
#define FO_AUTO 0
#define FO_WHITE_PAR 0
#define TAB '\t'
#define BL_WHITE 0

typedef int linenr_T;
typedef int colnr_T;
typedef unsigned char char_u;

struct cursor {
    linenr_T lnum;
    colnr_T col;
    colnr_T coladd;
    colnr_T virtcol;
};

struct window {
    struct cursor w_cursor;
    int w_p_ai;
    colnr_T w_virtcol;
};

struct buf {
    int b_p_ai;
    int b_p_vsts_array;
};

extern struct window *curwin;
extern struct buf *curbuf;
extern int State;
extern int arrow_used;
extern int ai_col;
extern int did_ai;
extern int did_si;
extern int can_si;
extern int can_si_back;
extern int cindent_on;
extern int can_cindent;
extern int p_sta;
extern int p_deco;
extern int enc_utf8;
extern int has_mbyte;
extern int revins_on;
extern int revins_chars;
extern int revins_legal;
extern int dollar_vcol;
extern int orig_line_count;
extern char *p_cpo;
extern struct cursor Insstart;
extern struct cursor Insstart_orig;
extern int end_comment_pending;

#define STRLEN strlen
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')

int BUFEMPTY();
int can_bs(int);
int inindent(int);
int stop_arrow();
int has_format_option(int);
int vim_isspace(int);
int vim_iswordc(int);
int gchar_cursor();
int do_join(int, int, int, int, int);
int del_char(int);
int utfc_ptr2char(char_u *, int *);
int mb_get_class(char_u *);
int get_sw_value(struct buf *);
int get_sts_value();
int tabstop_count(int);
colnr_T tabstop_start(colnr_T, int, int);
void vim_beep(int);
void inc_cursor();
void dec_cursor();
void getvcol(struct window *, struct cursor *, colnr_T *, colnr_T *, colnr_T *);
void ins_char(int);
void ins_str(char_u *);
void replace_push(int);
void replace_do_bs(int);
void replace_pop_ins();
void mb_replace_pop_ins(int);
void beginline(int);
void fix_indent();
void AppendCharToRedobuff(int);
void foldOpenCursor();
char_u *ml_get(linenr_T);
char_u *ml_get_buf(struct buf *, linenr_T, int);
char_u *ml_get_cursor();
int u_save(linenr_T, linenr_T);
int replace_pop();
int ins_bs_one(colnr_T *);
char *vim_strchr(const char *, int);

// Fix for cindent_on usage
#define cindent_on() (cindent_on)