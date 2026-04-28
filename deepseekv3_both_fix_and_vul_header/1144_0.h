#include <stdint.h>

typedef struct node {
    struct node *car;
    struct node *cdr;
} node;

typedef struct codegen_scope {
    // dummy definition, actual fields unknown
} codegen_scope;

#define NOVAL 0
#define NODE_SPLAT 0
#define GEN_VAL_STACK_MAX 0
#define GEN_LIT_ARY_MAX 0
#define OP_LOADNIL 0
#define OP_ARRAY 0
#define OP_ARYPUSH 0
#define OP_ARYCAT 0

static int cursp(void);
static void pop_n(int n);
static void pop(void);
static void push(void);
static void codegen(codegen_scope *s, node *t, int val);
static int nint(node *n);
static void genop_1(codegen_scope *s, int op, int arg);
static void genop_2(codegen_scope *s, int op, int arg1, int arg2);