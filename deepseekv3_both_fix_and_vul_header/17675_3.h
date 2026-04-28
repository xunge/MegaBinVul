#include <stddef.h>

#define NUMBUFLEN 30
#define FALSE 0
#define TRUE 1
#define OPT_LOCAL 0

typedef struct typval_S typval_T;
typedef struct buf_S buf_T;
typedef char char_u;

struct buf_S {
    /* incomplete type */
};

struct typval_S {
    /* incomplete type */
};

typedef struct {
    /* incomplete type */
} aco_save_T;

extern int check_restricted(void);
extern int check_secure(void);
extern long tv_get_number(typval_T *);
extern char_u *tv_get_string_chk(typval_T *);
extern buf_T *tv_get_buf(typval_T *, int);
extern long tv_get_number_chk(typval_T *, int *);
extern char_u *tv_get_string_buf_chk(typval_T *, char_u *);
extern void set_option_value(char_u *, long, char_u *, int);
extern void aucmd_prepbuf(aco_save_T *, buf_T *);
extern void aucmd_restbuf(aco_save_T *);
extern char_u *alloc(unsigned);
extern void set_var(char_u *, typval_T *, int);
extern void vim_free(void *);

#define STRCPY(d, s) __builtin_strcpy(d, s)

extern buf_T *curbuf;

#define UNUSED __attribute__((unused))