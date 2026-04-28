#include <stddef.h>

typedef unsigned char char_u;

typedef struct typval_S {
    int v_type;
    union {
        long v_number;
        char_u *v_string;
        void *v_other;
    } vval;
} typval_T;

typedef struct evalarg_S evalarg_T;
typedef struct growarray garray_T;

#define FALSE 0
#define TRUE 1
#define OK 1
#define FAIL 0

#define EVAL_EVALUATE 1

struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    void *ga_data;
};

struct evalarg_S {
    garray_T eval_ga;
    garray_T eval_freega;
    int eval_flags;
    void *eval_cookie;
    void *eval_cctx;
    char_u *eval_tofree;
    char_u *eval_tofree_lambda;
};

int in_vim9script(void);
char_u *skipwhite(char_u *);
int eval1(char_u **, typval_T *, evalarg_T *);
void ga_init2(garray_T *, int, int);
int ga_grow(garray_T *, int);
void ga_clear(garray_T *);
char_u *ga_concat_strings(garray_T *, char *);
void ga_clear_strings(garray_T *);
void vim_free(void *);
size_t STRLEN(const char_u *);