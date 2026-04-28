#include <stddef.h>
#include <limits.h>

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define MAXCOL INT_MAX
#define VREPLACE_FLAG (1 << 0)
#define INSERT (1 << 1)
#define SIN_CHANGED (1 << 0)
#define INDENT_SET 0
#define INDENT_DEC 1
#define BL_WHITE 0

typedef unsigned char char_u;
typedef int colnr_T;

struct window {
    int w_p_list;
    colnr_T w_virtcol;
    struct cursor {
        colnr_T col;
        int lnum;
    } w_cursor;
    int w_set_curswant;
};

struct window *curwin;

struct {
    int lnum;
    colnr_T col;
} Insstart;

int State;
int ai_col;

char_u *ml_get_curline(void);
char_u *vim_strsave(char_u *);
colnr_T getvcol_nolist(struct cursor *);
void beginline(int);
colnr_T get_indent(void);
int set_indent(int, int);
void shift_line(int, int, int, int);
int has_mbyte;
int (*mb_ptr2len)(char_u *);
int lbr_chartabsize(char_u *, char_u *, colnr_T);
void ins_str(char_u *);
char_u *alloc(int);
void vim_free(void *);
void changed_cline_bef_curs(void);
void replace_join(int);
void replace_push(int);
void backspace_until_column(int);
void ins_bytes(char_u *);
void ml_replace(int, char_u *, int);

#define REPLACE_NORMAL(s) ((s) & (1 << 2))