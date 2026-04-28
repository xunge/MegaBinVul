#include <stdlib.h>

typedef struct X509_POLICY_NODE_st {
    struct X509_POLICY_DATA_st *data;
    struct X509_POLICY_NODE_st *parent;
    int nchild;
} X509_POLICY_NODE;

typedef struct X509_POLICY_DATA_st {
    int valid_policy;
} X509_POLICY_DATA;

typedef struct X509_POLICY_LEVEL_st {
    X509_POLICY_NODE *anyPolicy;
    void *nodes;
} X509_POLICY_LEVEL;

typedef struct X509_POLICY_TREE_st {
    int node_maximum;
    int node_count;
    void *extra_data;
} X509_POLICY_TREE;

#define OPENSSL_zalloc(size) calloc(1, size)
#define X509V3err(a, b)
#define ERR_R_MALLOC_FAILURE 0
#define X509V3_F_LEVEL_ADD_NODE 0
#define NID_any_policy 0
#define OBJ_obj2nid(a) (a)

void *policy_node_cmp_new(void);
void policy_node_free(X509_POLICY_NODE *node);
int sk_X509_POLICY_NODE_push(void *sk, X509_POLICY_NODE *node);
void *sk_X509_POLICY_DATA_new_null(void);
int sk_X509_POLICY_DATA_push(void *sk, X509_POLICY_DATA *data);