#include <stdlib.h>

#define R_API
#define R_FREE(x) { free(x); x = NULL; }

typedef struct r_anal_block_t RAnalBlock;

struct r_anal_block_t {
    struct r_anal_cond_t *cond;
    char *fingerprint;
    struct r_anal_diff_t *diff;
    unsigned char *op_bytes;
    struct r_anal_switch_op_t *switch_op;
    char *label;
    int *op_pos;
    char *parent_reg_arena;
    RAnalBlock *prev;
    RAnalBlock *jumpbb;
    RAnalBlock *failbb;
    RAnalBlock *next;
};

void r_anal_cond_free(struct r_anal_cond_t *cond);
void r_anal_diff_free(struct r_anal_diff_t *diff);
void r_anal_switch_op_free(struct r_anal_switch_op_t *op);