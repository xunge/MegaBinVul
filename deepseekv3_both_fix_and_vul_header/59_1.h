#include <stddef.h>

#define FALSE 0
#define TRUE 1
#define FAIL 0
#define OK 1
#define MAXLNUM 0
#define LAST_WIN_NR 0
#define LAST_TAB_NR 0
#define CPO_STAR 0
#define FEAT_QUICKFIX 0

#define ADDR_LINES 0
#define ADDR_OTHER 1
#define ADDR_LOADED_BUFFERS 2
#define ADDR_BUFFERS 3
#define ADDR_WINDOWS 4
#define ADDR_TABS 5
#define ADDR_TABS_RELATIVE 6
#define ADDR_UNSIGNED 7
#define ADDR_QUICKFIX 8
#define ADDR_ARGUMENTS 9
#define ADDR_QUICKFIX_VALID 10
#define ADDR_NONE 11

typedef unsigned int linenr_T;

typedef struct buf_T {
    int b_fnum;
    struct buf_T *b_next;
    struct buf_T *b_prev;
    struct {
        void *ml_mfp;
        int ml_line_count;
    } b_ml;
} buf_T;

typedef struct {
    linenr_T lnum;
} pos_T;

typedef struct {
    int addr_type;
    int addr_count;
    int line1;
    int line2;
    char *cmd;
    int cmdidx;
    int skip;
} exarg_T;

typedef struct win_T {
    pos_T w_cursor;
} win_T;

extern buf_T *firstbuf;
extern buf_T *lastbuf;
extern buf_T *curbuf;
extern win_T *curwin;
extern char *p_cpo;
extern int ARGCOUNT;
extern char *e_invalid_range;
extern char *_(const char *str);

int default_address(exarg_T *eap);
char *skipwhite(char *p);
linenr_T get_address(exarg_T *eap, char **cmd, int addr_type, int skip, int silent, int first_addr, int addr_count);
int check_mark(pos_T *fp);
pos_T *getmark(int c, int force);
void check_cursor(void);
int qf_get_valid_size(exarg_T *eap);
char *vim_strchr(const char *string, int c);
int IS_USER_CMDIDX(int cmdidx);