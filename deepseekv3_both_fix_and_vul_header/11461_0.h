#include <stddef.h>

typedef struct i_ctx_s i_ctx_t;
typedef int (*es_ptr);

extern int esp;
extern int o_push_estack;
extern int setstrokecolorspace_cont;

int zswapcolors(i_ctx_t *i_ctx_p);
int zsetcolorspace(i_ctx_t *i_ctx_p);
void check_estack(int n);
void push_op_estack(int op);