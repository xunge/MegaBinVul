#include <stddef.h>

typedef unsigned char char_u;
typedef long colnr_T;

typedef struct {
    int regname;
} oparg_T;

typedef struct {
    oparg_T *oap;
    int nchar;
    int count1;
    int ncharC1;
    int ncharC2;
} cmdarg_T;

typedef struct {
    long lnum;
    colnr_T col;
} pos_T;

typedef struct {
    int b_p_et;
    pos_T b_op_start;
    pos_T b_op_end;
} buf_T;

typedef struct {
    pos_T w_cursor;
    int w_set_curswant;
} win_T;

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define NUL 0
#define DEL 127
#define Ctrl_V 22
#define Ctrl_E 5
#define Ctrl_Y 25
#define CAR '\r'
#define NL '\n'
#define ESC 27
#define TAB '\t'
#define REPLACE_CR_NCHAR (-1)
#define REPLACE_NL_NCHAR (-2)

extern buf_T *curbuf;
extern win_T *curwin;
extern int got_int;
extern int VIsual_active;
extern int has_mbyte;
extern int p_sta;
extern int p_sm;
extern int msg_silent;
extern int State;
#define REPLACE 1

static int checkclearop(oparg_T *oap) { return 0; }
static int prompt_curpos_editable() { return 0; }
static void clearopbeep(oparg_T *oap) {}
static int get_literal(int arg) { return 0; }
#define IS_SPECIAL(c) 0
static void reset_VIsual() {}
static void nv_operator(cmdarg_T *cap) {}
static int virtual_active() { return 0; }
static int u_save_cursor() { return 0; }
static int gchar_cursor() { return 0; }
static void coladvance_force(colnr_T col) {}
static int getviscol() { return 0; }
static char_u *ml_get_cursor() { return NULL; }
#define STRLEN(s) 0
static int mb_charlen(char_u *s) { return 0; }
static void stuffnumReadbuff(long n) {}
static void stuffcharReadbuff(int c) {}
static int del_chars(long n, int arg) { return 0; }
static void invoke_edit(cmdarg_T *cap, int arg1, int arg2, int arg3) {}
static void prep_redo(int regname, long count, int c1, int c2, int c3, int ctrl_v, int nchar) {}
static void AppendCharToRedobuff(int c) {}
static int ins_copychar(long lnum) { return 0; }
static void ins_char(int c) {}
static void showmatch(int c) {}
static int netbeans_active() { return 0; }
static void netbeans_removed(buf_T *buf, long lnum, colnr_T start, long count) {}
static void netbeans_inserted(buf_T *buf, long lnum, colnr_T start, char_u *s, int count) {}
static void changed_bytes(long lnum, colnr_T col) {}
static void mb_adjust_cursor() {}
static void set_last_insert(int c) {}
static char_u *ml_get_buf(buf_T *buf, long lnum, int arg) { return NULL; }
static int bt_prompt(buf_T *buf) { return 0; }