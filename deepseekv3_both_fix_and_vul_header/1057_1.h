#include <stdint.h>
#include <stdbool.h>

typedef struct node {
    struct node *car;
    struct node *cdr;
    int nint;
} node;

typedef struct codegen_scope {
    // dummy definition
} codegen_scope;

#define GEN_VAL_STACK_MAX 0
#define GEN_LIT_ARY_MAX 0
#define NODE_KW_REST_ARGS 0

#define OP_HASH 0
#define OP_HASHADD 0
#define OP_HASHCAT 0

#define FALSE false
#define TRUE true

typedef bool mrb_bool;

static int cursp(void);
static void pop_n(int n);
static void pop(void);
static void push(void);
static void genop_2(codegen_scope *s, int op, int sp, int len);
static void genop_1(codegen_scope *s, int op, int sp);
static void codegen(codegen_scope *s, node *tree, int val);

static int nint(struct node *n) {
    return n->nint;
}