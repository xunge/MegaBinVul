#include <ctype.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PLUS 1
#define MINUS -1

typedef struct bc_struct *bc_num;
struct bc_struct {
    int n_sign;
    char *n_value;
};

extern bc_num _zero_;
extern void bc_free_num(bc_num *num);
extern bc_num bc_copy_num(bc_num num);
extern bc_num bc_new_num(int length, int scale);
extern int bc_is_zero(bc_num num);
#define CH_VAL(c) ((c) - '0')
#define BCG(var) var