#include <stdlib.h>
#include <string.h>

#define ERR_LIB_X509V3 0
#define ERR_R_MALLOC_FAILURE 0
#define NID_any_policy 0

typedef struct ASN1_OBJECT_st ASN1_OBJECT;
typedef struct stack_st_X509_POLICY_NODE STACK_OF_X509_POLICY_NODE;
typedef struct stack_st_X509_POLICY_DATA STACK_OF_X509_POLICY_DATA;

typedef struct X509_POLICY_NODE_st {
    struct X509_POLICY_DATA_st *data;
    struct X509_POLICY_NODE_st *parent;
    int nchild;
} X509_POLICY_NODE;

typedef struct X509_POLICY_LEVEL_st {
    STACK_OF_X509_POLICY_NODE *nodes;
    X509_POLICY_NODE *anyPolicy;
} X509_POLICY_LEVEL;

typedef struct X509_POLICY_DATA_st {
    ASN1_OBJECT *valid_policy;
} X509_POLICY_DATA;

typedef struct X509_POLICY_TREE_st {
    STACK_OF_X509_POLICY_DATA *extra_data;
    int node_count;
    int node_maximum;
} X509_POLICY_TREE;

void *OPENSSL_zalloc(size_t size);
void ERR_raise(int lib, int reason);
int OBJ_obj2nid(ASN1_OBJECT *o);
STACK_OF_X509_POLICY_NODE *ossl_policy_node_cmp_new(void);
int sk_X509_POLICY_NODE_push(STACK_OF_X509_POLICY_NODE *sk, X509_POLICY_NODE *ptr);
STACK_OF_X509_POLICY_DATA *sk_X509_POLICY_DATA_new_null(void);
int sk_X509_POLICY_DATA_push(STACK_OF_X509_POLICY_DATA *sk, X509_POLICY_DATA *ptr);
void ossl_policy_node_free(X509_POLICY_NODE *node);