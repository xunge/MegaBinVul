#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef long linenr_T;

typedef struct {
    int lnum;
    int col;
    int coladd;
} pos_T;

typedef struct {
    int motion_type;
    bool inclusive;
    int op_type;
} oparg_T;

typedef struct {
    pos_T w_cursor;
    bool w_set_curswant;
} win_T;

typedef struct {
    oparg_T *oap;
    int nchar;
    int cmdchar;
    int count0;
    int count1;
    int arg;
} cmdarg_T;

#define MCHAR 0
#define FALSE 0
#define TRUE 1
#define OP_NOP 0
#define FORWARD 1
#define BACKWARD 0
#define FIND_IDENT 0
#define FIND_DEFINE 1
#define FIND_ANY 2
#define ACTION_SHOW 0
#define ACTION_SHOW_ALL 1
#define ACTION_GOTO 2
#define PUT_FIXINDENT 0
#define FAIL 1
#define MAXLNUM 0
#define BL_WHITE 1
#define BL_FIX 2
#define FDO_BLOCK 1
#define FDO_SEARCH 2
#define K_RIGHTRELEASE 100
#define K_LEFTMOUSE 101

extern win_T *curwin;
extern int fdo_flags;
extern int KeyTyped;

static char_u *vim_strchr(char_u *str, int c);
static void nv_gotofile(cmdarg_T *cap);
static void clearop(oparg_T *oap);
static int find_ident_under_cursor(char_u **ptr, int what);
static void find_pattern_in_path(char_u *ptr, int len1, int len2, int whole, int skip_comments, int type, int action, int count, linenr_T lnum, linenr_T maxlnum);
static void nv_bracket_block(cmdarg_T *cap, pos_T *old_pos);
static int findpar(bool *inclusive, int dir, int count, int what, int both);
static void clearopbeep(oparg_T *oap);
static void beginline(int flags);
static void foldOpenCursor(void);
static void nv_put_opt(cmdarg_T *cap, bool adjust);
static pos_T *getnextmark(pos_T *pos, int dir, bool linewise);
static void nv_cursormark(cmdarg_T *cap, bool linewise, pos_T *pos);
static int do_mouse(oparg_T *oap, int c, int dir, int count, int flags);
static int foldMoveTo(bool create, int dir, int count);
static int diff_move_to(int dir, int count);
static void setpcmark(void);
static int spell_move_to(win_T *wp, int dir, bool allwords, bool curbuf, pos_T *startpos);