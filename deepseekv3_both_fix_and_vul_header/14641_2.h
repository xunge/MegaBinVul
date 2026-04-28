#include <stddef.h>

#define FALSE 0
#define NUL '\0'
#define ML_EMPTY (1 << 0)
#define FDO_UNDO (1 << 0)
#define NOT_VALID 0

typedef unsigned char char_u;
typedef long time_T;

typedef struct u_header u_header_T;
struct u_header {
    time_T uh_time;
    long uh_seq;
    union {
        struct u_header *ptr;
    } uh_next;
};

typedef struct {
    int ml_flags;
} ml_T;

typedef struct {
    ml_T b_ml;
    u_header_T *b_u_curhead;
    u_header_T *b_u_newhead;
} buf_T;

typedef struct window_S win_T;
struct window_S {
    buf_T *w_buffer;
    int w_p_cole;
    win_T *w_next;
};

extern buf_T *curbuf;
extern int u_newcount;
extern int u_oldcount;
extern int global_busy;
extern int KeyTyped;
extern int fdo_flags;
extern int FEAT_FOLDING;
extern int FEAT_CONCEAL;
extern int VIsual_active;
extern win_T VIsual;
extern const char *msgstr;
extern int messaging(void);
extern void foldOpenCursor(void);
extern void redraw_win_later(win_T *, int);
extern void check_pos(buf_T *, win_T *);
extern void smsg_attr_keep(int, const char *, ...);
extern void add_time(char *, size_t, time_T);
extern const char *N_(const char *);
extern const char *_(const char *);

#define FOR_ALL_WINDOWS(wp) \
    for (wp = first_window; wp != NULL; wp = wp->w_next)
extern win_T *first_window;