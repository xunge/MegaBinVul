#include <stdlib.h>

typedef struct node {
    int type;
    struct node *car;
    struct node *cdr;
} node;

typedef struct codegen_scope {
    int sp;
    int mrb;
} codegen_scope;

typedef int mrb_sym;

#define NODE_GVAR 1
#define NODE_ARG 2
#define NODE_LVAR 3
#define NODE_IVAR 4
#define NODE_CVAR 5
#define NODE_CONST 6
#define NODE_NIL 7
#define NODE_MASGN 8
#define NODE_COLON2 9
#define NODE_CALL 10
#define NODE_SCALL 11
#define NODE_NVAR 12

#define OP_SETGV 1
#define OP_SETIV 2
#define OP_SETCV 3
#define OP_SETCONST 4
#define OP_SETMCNST 5
#define OP_JMPNIL 6
#define OP_ARRAY 7
#define OP_ARYPUSH 8
#define OP_SETIDX 9
#define OP_SSEND 10
#define OP_SEND 11

#define VAL 1
#define aref "[]"

static int nint(struct node *n) { return n->type; }
static int nsym(node *n) { return 0; }
static int lv_idx(codegen_scope *s, int sym) { return 0; }
static int new_sym(codegen_scope *s, int sym) { return 0; }
static int attrsym(codegen_scope *s, int mid) { return 0; }
static int MRB_OPSYM_2(int mrb, const char *name) { return 0; }
static int cursp() { return 0; }
static void pop() {}
static void pop_n(int n) {}
static void push() {}
static void codegen(codegen_scope *s, node *n, int val) {}
static void gen_setxv(codegen_scope *s, int op, int sp, int sym, int val) {}
static void gen_setupvar(codegen_scope *s, int sp, int sym) {}
static void gen_move(codegen_scope *s, int dst, int src, int val) {}
static void genop_1(codegen_scope *s, int op, int sp) {}
static void genop_2(codegen_scope *s, int op, int sp, int arg) {}
static void genop_3(codegen_scope *s, int op, int sp, int arg1, int arg2) {}
static int genjmp2_0(codegen_scope *s, int op, int sp, int val) { return 0; }
static void dispatch(codegen_scope *s, int skip) {}
static int gen_values(codegen_scope *s, node *n, int val, int max) { return 0; }
static void gen_hash(codegen_scope *s, node *n, int val, int flag) {}
static void gen_vmassignment(codegen_scope *s, node *n, int sp, int val) {}
static void codegen_error(codegen_scope *s, const char *msg) {}