#include <stddef.h>

#define POLICY_DATA_FLAG_SHARED_QUALIFIERS 0x1

typedef struct ASN1_OBJECT_st ASN1_OBJECT;

typedef struct X509_POLICY_DATA_st {
    void *valid_policy;
    void *qualifier_set;
    unsigned int flags;
} X509_POLICY_DATA;

typedef struct X509_POLICY_NODE_st {
    X509_POLICY_DATA *data;
} X509_POLICY_NODE;

typedef struct X509_POLICY_CACHE_st {
    struct {
        void *qualifier_set;
    } *anyPolicy;
} X509_POLICY_CACHE;

typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;

X509_POLICY_DATA *ossl_policy_data_new(void *, const ASN1_OBJECT *, int);
void ossl_policy_data_free(X509_POLICY_DATA *);
X509_POLICY_NODE *ossl_policy_level_add_node(X509_POLICY_LEVEL *, X509_POLICY_DATA *, X509_POLICY_NODE *, X509_POLICY_TREE *, ...);
int node_critical(X509_POLICY_NODE *);