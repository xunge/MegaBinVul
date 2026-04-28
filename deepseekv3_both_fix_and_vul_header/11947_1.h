#include <stdbool.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define NUL '\0'

#define VV_EXITING 0
#define VAR_NUMBER 0
#define EVENT_BUFWINLEAVE 0
#define EVENT_BUFUNLOAD 0
#define EVENT_VIMLEAVEPRE 0
#define EVENT_VIMLEAVE 0

typedef struct bufref_T bufref_T;
typedef struct buf_T buf_T;
typedef struct win_T win_T;
typedef struct tabpage_T tabpage_T;
typedef struct gui_T gui_T;

extern bool exiting;
extern bool exmode_active;
extern int ex_exitval;
extern int v_dying;
extern int did_emsg;
extern int no_wait_return;
extern int p_verbose;
extern char *p_viminfo;
extern buf_T *curbuf;
extern tabpage_T *first_tabpage;
extern bool garbage_collect_at_exit;
extern int msg_didany;
extern gui_T gui;
extern buf_T *firstbuf;

struct buf_T {
    char *b_fname;
    int changedtick;
    struct {
        void *ml_mfp;
    } b_ml;
    buf_T *b_next;
};

struct win_T {
    buf_T *w_buffer;
    win_T *w_next;
};

struct tabpage_T {
    tabpage_T *tp_next;
    win_T *tp_firstwin;
};

struct bufref_T {
    buf_T *br_buf;
};

struct gui_T {
    bool in_use;
};

#define CHANGEDTICK(buf) ((buf)->changedtick)
#define Rows 25

#define FOR_ALL_WINDOWS_IN_TAB(tp, wp) \
    for ((wp) = (tp)->tp_firstwin; (wp) != NULL; (wp) = (wp)->w_next)

#define FOR_ALL_BUFFERS(buf) \
    for ((buf) = firstbuf; (buf) != NULL; (buf) = (buf)->b_next)

void ch_log(void *, const char *);
void set_vim_var_type(int, int);
void set_vim_var_nr(int, int);
void windgoto(int, int);
bool is_not_a_term_or_gui(void);
void invoke_all_defer(void);
void hash_debug_results(void);
void set_bufref(bufref_T *, buf_T *);
bool bufref_valid(bufref_T *);
void apply_autocmds(int, char *, char *, bool, buf_T *);
bool is_autocmd_blocked(void);
void unblock_autocmds(void);
void block_autocmds(void);
void wait_return(bool);
void write_viminfo(void *, bool);
void profile_dump(void);
void job_stop_on_exit(void);
void lua_end(void);
void mzscheme_end(void);
void tcl_end(void);
void ruby_end(void);
void python_end(void);
void python3_end(void);
void perl_end(void);
void netbeans_end(void);
void cs_end(void);
void garbage_collect(bool);
void mch_exit(int);