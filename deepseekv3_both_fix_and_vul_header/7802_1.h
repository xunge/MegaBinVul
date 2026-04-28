#include <stddef.h>

typedef long linenr_T;
typedef int colnr_T;

typedef struct {
    linenr_T lnum;
    colnr_T col;
    int coladd;
} pos_T;

typedef struct {
    int b_fnum;
} buf_T;

typedef struct {
    pos_T w_cursor;
    int w_set_curswant;
} win_T;

#define GETF_ALT 0x01
#define GETF_SETMARK 0x02
#define GETF_SWITCH 0x04

#define SWB_USEOPEN 0x01
#define SWB_USETAB 0x02
#define SWB_VSPLIT 0x04
#define SWB_SPLIT 0x08
#define SWB_NEWTAB 0x10

#define WSP_VERT 0x01

#define OK 1
#define FAIL 0
#define TRUE 1

extern buf_T *curbuf;
extern win_T *curwin;
extern int RedrawingDisabled;
extern int swb_flags;
extern int p_sol;

extern const char *e_no_alternate_file;
extern const char *e_buffer_nr_not_found;

#define _(x) x

extern buf_T *buflist_findnr(int n);
extern pos_T *buflist_findfpos(buf_T *buf);
extern void emsg(const char *msg);
extern void semsg(const char *msg, int n);
extern int text_locked(void);
extern void text_locked_msg(void);
extern int curbuf_locked(void);
extern win_T *buf_jump_open_win(buf_T *buf);
extern win_T *buf_jump_open_tab(buf_T *buf);
extern void tabpage_new(void);
extern int win_split(int size, int flags);
extern void RESET_BINDING(win_T *wp);
extern int GETFILE_SUCCESS(int status);
extern int getfile(int fnum, char *fname, char *sfname, int setmark, linenr_T lnum, int forceit);
extern void check_cursor_col(void);
extern int BUFEMPTY(void);