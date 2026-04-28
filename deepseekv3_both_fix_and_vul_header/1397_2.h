#include <stddef.h>

typedef int linenr_T;
typedef unsigned char char_u;
typedef int varnumber_T;

typedef struct typval_S {
    int v_type;
    union {
        varnumber_T v_number;
        char_u *v_string;
        void *v_pointer;
    } vval;
} typval_T;

typedef struct qfline_S {
    struct qfline_S *qf_next;
    int qf_fnum;
} qfline_T;

typedef struct {
    qfline_T *qf_start;
    int qf_count;
} qf_list_T;

typedef struct listitem_S {
    struct listitem_S *li_next;
    typval_T li_tv;
} listitem_T;

typedef struct {
    listitem_T *lv_first;
} list_T;

typedef struct {
    int ml_flags;
    linenr_T ml_line_count;
} memline_T;

typedef struct buf_S {
    memline_T b_ml;
    int b_p_ma;
} buf_T;

extern buf_T *curbuf;
extern int KeyTyped;
extern int curbuf_lock;
extern int keep_filetype;

#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define NUL '\0'
#define MAXPATHL 256
#define ML_EMPTY 0x01
#define UPD_NOT_VALID 0
#define OPT_LOCAL 0

enum {
    EVENT_BUFREADPOST,
    EVENT_BUFWINENTER
};

#define internal_error(msg) (void)0
#define ml_delete(lnum) (0)
#define call_qftf_func(qfl, winid, start, count) (NULL)
#define tv_get_string_chk(tv) (NULL)
#define qf_buf_add_line(buf, lnum, qfp, dirname, new_file, qftf_str) (0)
#define check_lnums(force) (void)0
#define set_option_value_give_err(name, numval, stringval, opt_flags) (void)0
#define apply_autocmds(event, fname, fname_io, force, buf) (void)0
#define redraw_curbuf_later(flags) (void)0