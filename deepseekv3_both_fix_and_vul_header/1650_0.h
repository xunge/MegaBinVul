#include <stddef.h>

typedef struct buf_T buf_T;
typedef struct win_T win_T;

extern buf_T *curbuf;
extern win_T *curwin;
extern win_T *firstwin;
extern buf_T *firstbuf;

struct buf_T {
    buf_T *b_next;
    int b_p_bl;
    struct {
        void *ml_mfp;
    } b_ml;
    int b_scanned;
};

struct win_T {
    win_T *w_next;
    buf_T *w_buffer;
};