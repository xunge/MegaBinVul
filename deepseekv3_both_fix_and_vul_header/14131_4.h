#include <stddef.h>
#include <limits.h>
#include <ctype.h>

typedef long linenr_T;
typedef unsigned char char_u;
typedef struct exarg exarg_T;
typedef enum {
    ADDR_LINES,
    ADDR_OTHER,
    ADDR_WINDOWS,
    ADDR_ARGUMENTS,
    ADDR_LOADED_BUFFERS,
    ADDR_BUFFERS,
    ADDR_TABS,
    ADDR_TABS_RELATIVE,
    ADDR_UNSIGNED,
    ADDR_NONE,
    ADDR_QUICKFIX,
    ADDR_QUICKFIX_VALID
} cmd_addr_T;

typedef struct {
    linenr_T lnum;
    int col;
    int coladd;
} pos_T;

typedef struct window_S {
    pos_T w_cursor;
    int w_arg_idx;
} win_T;

typedef struct file_buffer {
    struct file_buffer *b_prev;
    int b_fnum;
    struct {
        int ml_line_count;
        void *ml_mfp;
    } b_ml;
} buf_T;

#define MAXLNUM LONG_MAX
#define MAXCOL INT_MAX
#define CURRENT_WIN_NR 0
#define LAST_WIN_NR 0
#define CURRENT_TAB_NR 0
#define LAST_TAB_NR 0
#define ARGCOUNT 0
#define NUL '\0'
#define FAIL 0
#define RE_SUBST 0
#define RE_SEARCH 0
#define BACKWARD 0
#define FORWARD 1
#define SEARCH_HIS 0
#define SEARCH_MSG 0
#define FEAT_QUICKFIX
#define FEAT_FOLDING
#define VIM_ISDIGIT(c) isdigit((unsigned char)(c))

#define _(x) x
#define e_backslash_should_be_followed_by "E10: \\ should be followed by /, ? or &"
#define e_invalid_range "E16: Invalid range"

extern win_T *curwin;
extern buf_T *curbuf;
extern buf_T *lastbuf;
extern int searchcmdlen;

char_u *skipwhite(char_u *p);
char_u *skip_regexp(char_u *p, int delim, int magic);
int magic_isset(void);
int do_search(char_u *pat, int dirc, int patlen, char_u *str, long count, int options, pos_T *pos);
int searchit(win_T *win, buf_T *buf, pos_T *pos, pos_T *end_pos, int dir, char_u *pat, long count, int options, int search_type, pos_T *start_pos);
void addr_error(cmd_addr_T addr_type);
pos_T *getmark(int c, int to_other_file);
int check_mark(pos_T *fp);
linenr_T qf_get_cur_idx(exarg_T *eap);
linenr_T qf_get_cur_valid_idx(exarg_T *eap);
linenr_T qf_get_size(exarg_T *eap);
linenr_T qf_get_valid_size(exarg_T *eap);
int hasFolding(linenr_T lnum, linenr_T *lnum_p, linenr_T *lnum_p2);
linenr_T compute_buffer_local_count(cmd_addr_T addr_type, linenr_T lnum, long n);
long getdigits(char_u **pp);
void emsg(const char *s);

#define UNUSED __attribute__((unused))