#include <stdlib.h>
#include <stddef.h>

typedef struct X509_STORE_CTX {
    int parent;
    int bare_ta_signed;
    struct stack_st_X509 *chain;
    void *tree;
    int explicit_policy;
    struct {
        void *policies;
        int flags;
    } *param;
    int error;
    struct X509 *current_cert;
    int (*verify_cb)(int, struct X509_STORE_CTX *);
} X509_STORE_CTX;

typedef struct X509 {
    int ex_flags;
} X509;

typedef struct stack_st_X509 {
    int dummy;
} STACK_OF_X509;

#define X509_F_CHECK_POLICY 0
#define ERR_R_MALLOC_FAILURE 0
#define X509_V_ERR_OUT_OF_MEM 0
#define X509_PCY_TREE_INTERNAL 0
#define X509_PCY_TREE_INVALID 0
#define X509_PCY_TREE_FAILURE 0
#define X509_PCY_TREE_VALID 0
#define EXFLAG_INVALID_POLICY 0
#define X509_V_ERR_INVALID_POLICY_EXTENSION 0
#define X509_V_ERR_NO_EXPLICIT_POLICY 0
#define X509_V_FLAG_NOTIFY_POLICY 0

static int X509_policy_check(void **tree, int *explicit_policy, 
                           struct stack_st_X509 *chain, 
                           void *policies, int flags) {
    return 0;
}

static int verify_cb_cert(X509_STORE_CTX *ctx, X509 *x, int i, int err) {
    return 0;
}

static int sk_X509_push(struct stack_st_X509 *sk, X509 *x) {
    return 0;
}

static X509 *sk_X509_pop(struct stack_st_X509 *sk) {
    return NULL;
}

static int sk_X509_num(struct stack_st_X509 *sk) {
    return 0;
}

static X509 *sk_X509_value(struct stack_st_X509 *sk, int i) {
    return NULL;
}

#define X509err(a, b)