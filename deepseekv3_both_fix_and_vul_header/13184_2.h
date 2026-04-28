#include <stdlib.h>

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
    struct X509 *current_cert;
    int error;
    int (*verify_cb)(int, struct X509_STORE_CTX *);
} X509_STORE_CTX;

typedef struct X509 {
    int ex_flags;
} X509;

typedef struct stack_st_X509 {
    // Stack implementation details would go here
    // For compilation we just need the type definition
} sk_X509;

#define CB_FAIL_IF(test, ctx, x, i, err) \
    if (test) { \
        (ctx)->current_cert = (x); \
        (ctx)->error = (err); \
        if (!(ctx)->verify_cb(0, (ctx))) \
            return 0; \
    }

#define EXFLAG_INVALID_POLICY 0x1000

#define X509_PCY_TREE_INTERNAL -1
#define X509_PCY_TREE_INVALID 0
#define X509_PCY_TREE_FAILURE 1
#define X509_PCY_TREE_VALID 2

#define X509_V_ERR_INVALID_POLICY_EXTENSION 146
#define X509_V_ERR_NO_EXPLICIT_POLICY 147
#define X509_V_ERR_OUT_OF_MEM 11
#define X509_V_OK 0

#define ERR_LIB_X509 11
#define ERR_R_MALLOC_FAILURE 64
#define ERR_R_INTERNAL_ERROR 66

#define X509_V_FLAG_NOTIFY_POLICY 0x1000

int X509_policy_check(void **tree, int *explicit_policy, sk_X509 *chain, void *policies, int flags);
int sk_X509_push(sk_X509 *sk, X509 *x);
X509 *sk_X509_pop(sk_X509 *sk);
int sk_X509_num(sk_X509 *sk);
X509 *sk_X509_value(sk_X509 *sk, int idx);
void ERR_raise(int lib, int reason);