#include <stddef.h>
#include <limits.h>
#include <ctype.h>

typedef long linenr_T;
typedef unsigned char char_u;

typedef struct {
    linenr_T lnum;
    int col;
    int coladd;
} pos_T;

typedef struct buf_T {
    struct buf_T *b_prev;
    int b_fnum;
    struct {
        int ml_line_count;
        void *ml_mfp;
    } b_ml;
} buf_T;

typedef struct win_T {
    pos_T w_cursor;
    int w_arg_idx;
} win_T;

typedef struct {
    int unused;
} exarg_T;

typedef enum {
    ADDR_LINES,
    ADDR_WINDOWS,
    ADDR_ARGUMENTS,
    ADDR_LOADED_BUFFERS,
    ADDR_BUFFERS,
    ADDR_TABS,
    ADDR_TABS_RELATIVE,
    ADDR_UNSIGNED,
    ADDR_OTHER,
    ADDR_NONE,
    ADDR_QUICKFIX,
    ADDR_QUICKFIX_VALID
} cmd_addr_T;

#define MAXLNUM LONG_MAX
#define NUL '\0'
#define MAXCOL INT_MAX
#define CURRENT_WIN_NR 0
#define LAST_WIN_NR 0
#define CURRENT_TAB_NR 0
#define LAST_TAB_NR 0
#define ARGCOUNT 0
#define FAIL 1
#define SEARCH_HIS 0
#define SEARCH_MSG 0
#define RE_SUBST 0
#define RE_SEARCH 0
#define FORWARD 0
#define BACKWARD 1
#define VIM_ISDIGIT(c) isdigit((unsigned char)(c))

#define UNUSED __attribute__((unused))

extern win_T *curwin;
extern buf_T *curbuf;
extern buf_T *lastbuf;
extern int searchcmdlen;
extern const char *e_backslash_should_be_followed_by;
extern const char *e_line_number_out_of_range;
extern const char *e_invalid_range;

extern int magic_isset(void);
extern char_u *skipwhite(char_u *);
extern char_u *skip_regexp(char_u *, int, int);
extern int do_search(char_u *, int, int, char_u *, long, int, void *);
extern int searchit(win_T *, buf_T *, pos_T *, void *, int, char_u *, long, int, int, void *);
extern int hasFolding(linenr_T, linenr_T *, linenr_T *);
extern int check_mark(pos_T *);
extern pos_T *getmark(int, int);
extern void addr_error(cmd_addr_T);
extern void emsg(const char *);
extern linenr_T getdigits(char_u **);
extern linenr_T compute_buffer_local_count(cmd_addr_T, linenr_T, long);
extern linenr_T qf_get_cur_idx(exarg_T *);
extern linenr_T qf_get_cur_valid_idx(exarg_T *);
extern linenr_T qf_get_size(exarg_T *);
extern linenr_T qf_get_valid_size(exarg_T *);