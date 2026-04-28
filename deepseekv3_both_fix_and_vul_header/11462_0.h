#include <stddef.h>

typedef struct i_ctx_s i_ctx_t;
typedef int (*es_ptr);

extern i_ctx_t *i_ctx_p;
extern es_ptr esp;
extern int zswapcolors(i_ctx_t *);
extern int zsetcolor(i_ctx_t *);
extern void check_estack(int);
extern void push_op_estack(int);
extern int setstrokecolor_cont;
extern int o_push_estack;