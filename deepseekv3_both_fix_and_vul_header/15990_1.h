#include <stddef.h>

typedef long linenr_T;
typedef unsigned char char_u;

typedef struct {
    int b_nwindows;
    int b_changed;
} buf_T;

typedef struct {
    buf_T *curbuf;
    struct {
        linenr_T lnum;
    } w_cursor;
} win_T;

typedef struct {
    int count1;
    int nchar;
    void *oap;
} cmdarg_T;

#define FALSE 0
#define OK 1
#define ECMD_LAST 0
#define ECMD_HIDE 0
#define BL_SOL 0
#define BL_FIX 0
#define FEAT_PROP_POPUP
#define ERROR_IF_TERM_POPUP_WINDOW 0

extern win_T *curwin;
extern buf_T *curbuf;