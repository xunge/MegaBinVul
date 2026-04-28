#include <stdlib.h>

typedef struct x509_st {
    int references;
} X509;

typedef struct x509_store_ctx_st {
    X509 *cert;
    struct stack_st_X509 *chain;
    struct stack_st_X509 *untrusted;
    int last_untrusted;
    struct x509_verify_param_st *param;
    int (*verify_cb)(int, struct x509_store_ctx_st *);
    int (*check_issued)(struct x509_store_ctx_st *, X509 *, X509 *);
    int (*get_issuer)(X509 **, struct x509_store_ctx_st *, X509 *);
    int (*verify)(struct x509_store_ctx_st *);
    int (*check_revocation)(struct x509_store_ctx_st *);
    int (*check_policy)(struct x509_store_ctx_st *);
    int error;
    X509 *current_cert;
    int error_depth;
} X509_STORE_CTX;

typedef struct x509_verify_param_st {
    int depth;
    int flags;
    int trust;
} X509_VERIFY_PARAM;

typedef struct stack_st_X509 {
    X509 **data;
    int num;
} STACK_OF_X509;

#define STACK_OF(X509) STACK_OF_X509
#define sk_X509_new_null() ((STACK_OF_X509 *)calloc(1, sizeof(STACK_OF_X509)))
#define sk_X509_push(sk, x) ((sk)->data = realloc((sk)->data, ++(sk)->num * sizeof(X509 *)), (sk)->data[(sk)->num-1] = (x), 1)
#define sk_X509_num(sk) ((sk) ? (sk)->num : 0)
#define sk_X509_value(sk, i) ((sk)->data[i])
#define sk_X509_dup(sk) ({ STACK_OF_X509 *new_sk = malloc(sizeof(STACK_OF_X509)); if(new_sk) { new_sk->num = (sk)->num; new_sk->data = malloc((sk)->num * sizeof(X509 *)); memcpy(new_sk->data, (sk)->data, (sk)->num * sizeof(X509 *)); } new_sk; })
#define sk_X509_delete_ptr(sk, x) ({ int i; for(i=0; i<(sk)->num; i++) { if((sk)->data[i] == (x)) { memmove(&(sk)->data[i], &(sk)->data[i+1], ((sk)->num-i-1)*sizeof(X509 *)); (sk)->num--; return i; } } -1; })
#define sk_X509_pop(sk) ((sk)->data[--(sk)->num])
#define sk_X509_set(sk, i, x) ((sk)->data[i] = (x), 1)
#define sk_X509_free(sk) free((sk)->data), free(sk)

#define X509_F_X509_VERIFY_CERT 0
#define X509_R_NO_CERT_SET_FOR_US_TO_VERIFY 0
#define ERR_R_MALLOC_FAILURE 0
#define CRYPTO_LOCK_X509 0
#define X509_V_FLAG_NO_ALT_CHAINS 0
#define X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT 0
#define X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY 0
#define X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT 0
#define X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN 0
#define X509_V_FLAG_POLICY_CHECK 0
#define OPENSSL_NO_RFC3779

static void X509err(int a, int b) {}
static void CRYPTO_add(int *a, int b, int c) { *a += b; }
static void X509_free(X509 *a) { free(a); }
static int X509_cmp(X509 *a, X509 *b) { return a != b; }
static int find_issuer(X509_STORE_CTX *ctx, STACK_OF_X509 *sk, X509 *x) { return 0; }
static int check_chain_extensions(X509_STORE_CTX *ctx) { return 1; }
static int check_name_constraints(X509_STORE_CTX *ctx) { return 1; }
static int check_trust(X509_STORE_CTX *ctx) { return 1; }
static void X509_get_pubkey_parameters(void *a, STACK_OF_X509 *b) {}
static int internal_verify(X509_STORE_CTX *ctx) { return 1; }
static int v3_asid_validate_path(X509_STORE_CTX *ctx) { return 1; }
static int v3_addr_validate_path(X509_STORE_CTX *ctx) { return 1; }