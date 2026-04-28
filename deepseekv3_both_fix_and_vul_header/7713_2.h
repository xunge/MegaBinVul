#include <string.h>
#include <stddef.h>

typedef unsigned char char_u;

typedef struct pos_S {
    long lnum;
    long col;
    long coladd;
} pos_T;

typedef struct window_S {
    pos_T w_cursor;
} window_T;

typedef struct memline_S {
    long ml_line_count;
} memline_T;

typedef struct buf_S {
    memline_T b_ml;
    pos_T b_op_start;
    pos_T b_op_start_orig;
    pos_T b_op_end;
} buf_T;

#define STRLEN(s) strlen((const char *)(s))
#define NUL '\0'
#define FAIL (-1)
#define TRUE 1
#define FALSE 0
#define CPO_INDENT 'I'
#define FO_AUTO (1 << 0)
#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')

extern int did_restart_edit;
extern int new_insert_skip;
extern int arrow_used;
extern int ins_need_undo;
extern int did_ai;
extern int VIsual_active;
extern pos_T VIsual;
extern pos_T Insstart;
extern pos_T Insstart_orig;
extern char_u *last_insert;
extern int last_insert_skip;
extern char *p_cpo;
extern window_T *curwin;
extern buf_T *curbuf;

static void stop_redo_ins(void);
static void replace_flush(void);
static char_u *get_inserted(void);
static void vim_free(char_u *ptr);
static int has_format_option(int option);
static int gchar_cursor(void);
static void dec_cursor(void);
static void auto_format(int a, int b);
static void inc_cursor(void);
static void check_auto_format(int a);
static int del_char(int a);
static void check_cursor_col(void);
static char *vim_strchr(const char *s, int c);
static char_u *ml_get_curline(void);
static int gchar_pos(pos_T *pos);