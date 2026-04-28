#include <stdlib.h>

typedef struct X509_STORE_CTX {
    struct X509_STORE_CTX *parent;
    int bare_ta_signed;
    struct stack_st_X509 *chain;
    void *tree;
    int explicit_policy;
    struct {
        void *policies;
        unsigned long flags;
    } *param;
    struct X509 *current_cert;
    int error;
    int (*verify_cb)(int, struct X509_STORE_CTX *);
} X509_STORE_CTX;

typedef struct X509 {
    unsigned long ex_flags;
} X509;

typedef struct stack_st_X509 {
    // Stack implementation details would go here
} stack_st_X509;

#define X509_PCY_TREE_INTERNAL 1
#define X509_PCY_TREE_INVALID 2
#define X509_PCY_TREE_FAILURE 3
#define X509_PCY_TREE_VALID 4

#define EXFLAG_INVALID_POLICY 0x1000
#define X509_V_ERR_INVALID_POLICY_EXTENSION 1
#define X509_V_ERR_NO_EXPLICIT_POLICY 2
#define X509_V_ERR_OUT_OF_MEM 3
#define X509_V_FLAG_NOTIFY_POLICY 0x100

#define ERR_LIB_X509 11
#define ERR_R_MALLOC_FAILURE 1
#define ERR_R_INTERNAL_ERROR 2

#define CB_FAIL_IF(test, ctx, x, i, err) \
    if (test) { \
        (ctx)->current_cert = (x); \
        (ctx)->error = (err); \
        if (!(ctx)->verify_cb(0, (ctx))) \
            return 0; \
    }

int X509_policy_check(void **tree, int *explicit_policy, stack_st_X509 *chain, void *policies, unsigned long flags);
int sk_X509_push(stack_st_X509 *sk, X509 *x);
X509 *sk_X509_pop(stack_st_X509 *sk);
int sk_X509_num(stack_st_X509 *sk);
X509 *sk_X509_value(stack_st_X509 *sk, int idx);
void ERR_raise(int lib, int reason);