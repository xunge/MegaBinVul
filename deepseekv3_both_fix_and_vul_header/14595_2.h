#include <stdint.h>
#include <stdbool.h>

typedef struct node {
    struct node *car;
    struct node *cdr;
    int nint;
} node;

typedef struct codegen_scope {
    // placeholder for codegen_scope structure
} codegen_scope;

typedef bool mrb_bool;

#define GEN_VAL_STACK_MAX 0
#define GEN_LIT_ARY_MAX 0
#define NODE_KW_REST_ARGS 0

#define OP_HASH 0
#define OP_HASHADD 0
#define OP_HASHCAT 0

#define FALSE false
#define TRUE true

static inline int nint(struct node *n) { return n->nint; }
static inline int cursp(void) { return 0; }
static inline void pop_n(int n) {}
static inline void pop(void) {}
static inline void push(void) {}
static inline void genop_2(codegen_scope *s, int op, int sp, int len) {}
static inline void genop_1(codegen_scope *s, int op, int sp) {}
static inline void codegen(codegen_scope *s, node *tree, int val) {}