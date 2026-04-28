#include <stddef.h>

typedef long linenr_T;

#define FAIL 1
#define OK 0
#define MAXLNUM 0
#define FALSE 0
#define TRUE 1

enum {
    ADDR_LINES,
    ADDR_OTHER,
    ADDR_LOADED_BUFFERS,
    ADDR_BUFFERS,
    ADDR_WINDOWS,
    ADDR_TABS,
    ADDR_TABS_RELATIVE,
    ADDR_UNSIGNED,
    ADDR_QUICKFIX,
    ADDR_ARGUMENTS,
    ADDR_QUICKFIX_VALID,
    ADDR_NONE
};

#define LAST_WIN_NR 0
#define LAST_TAB_NR 0
#define CPO_STAR 0
#define IS_USER_CMDIDX(x) 0
#define ARGCOUNT 0
#define FEAT_QUICKFIX 0

typedef struct pos {
    linenr_T lnum;
} pos_T;

typedef struct buf {
    struct buf *b_next;
    struct buf *b_prev;
    struct {
        void *ml_mfp;
        linenr_T ml_line_count;
    } b_ml;
    int b_fnum;
} buf_T;

typedef struct window {
    pos_T w_cursor;
} win_T;

typedef struct exarg {
    char *cmd;
    linenr_T line1;
    linenr_T line2;
    int addr_type;
    int skip;
    int addr_count;
    int cmdidx;
} exarg_T;

extern buf_T *firstbuf;
extern buf_T *lastbuf;
extern buf_T *curbuf;
extern win_T *curwin;
extern char *p_cpo;
extern char *e_invalid_range;

char *_(const char *str);
char *skipwhite(char *s);
char *vim_strchr(const char *str, int c);
linenr_T default_address(exarg_T *eap);
linenr_T get_address(exarg_T *eap, char **cmd, int addr_type, int skip, int silent, int first_addr, int addr_count);
int check_mark(pos_T *fp);
pos_T *getmark(int c, int force);
void check_cursor(void);
int qf_get_valid_size(exarg_T *eap);