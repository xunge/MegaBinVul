#include <stddef.h>

typedef struct typval_S typval_T;
#define UNUSED
#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define NUMBUFLEN 50
#define FEAT_CMDHIST

typedef char char_u;

struct typval_S {
    union {
        int v_number;
    } vval;
};

int check_restricted(void);
int check_secure(void);
char_u *tv_get_string_chk(typval_T *);
int get_histtype(char_u *);
char_u *tv_get_string_buf(typval_T *, char_u *);
void init_history(void);
void add_to_history(int, char_u *, int, char);