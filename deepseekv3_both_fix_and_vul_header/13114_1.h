#include <stdlib.h>
#include <string.h>

#define ERR_LIB_X509V3 0
#define ERR_R_MALLOC_FAILURE 0
#define NID_any_policy 0

typedef struct X509_POLICY_NODE_st X509_POLICY_NODE;
typedef struct X509_POLICY_DATA_st X509_POLICY_DATA;
typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct ASN1_OBJECT_st ASN1_OBJECT;

struct X509_POLICY_NODE_st {
    X509_POLICY_DATA *data;
    X509_POLICY_NODE *parent;
    int nchild;
};

struct X509_POLICY_LEVEL_st {
    void *nodes;
    X509_POLICY_NODE *anyPolicy;
};

struct X509_POLICY_TREE_st {
    void *extra_data;
    int node_count;
    int node_maximum;
};

struct X509_POLICY_DATA_st {
    ASN1_OBJECT *valid_policy;
};

void *OPENSSL_zalloc(size_t size);
void ERR_raise(int lib, int reason);
int OBJ_obj2nid(ASN1_OBJECT *obj);
void *ossl_policy_node_cmp_new(void);
int sk_X509_POLICY_NODE_push(void *sk, X509_POLICY_NODE *node);
void *sk_X509_POLICY_DATA_new_null(void);
int sk_X509_POLICY_DATA_push(void *sk, X509_POLICY_DATA *data);
void ossl_policy_node_free(X509_POLICY_NODE *node);