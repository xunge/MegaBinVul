#include <stddef.h>

#define POLICY_DATA_FLAG_SHARED_QUALIFIERS 0x1

typedef struct ASN1_OBJECT_st ASN1_OBJECT;

typedef struct X509_POLICY_NODE_st {
    struct X509_POLICY_DATA_st *data;
} X509_POLICY_NODE;

typedef struct X509_POLICY_DATA_st {
    const ASN1_OBJECT *valid_policy;
    void *qualifier_set;
    unsigned int flags;
} X509_POLICY_DATA;

typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;

typedef struct X509_POLICY_CACHE_st {
    struct {
        void *qualifier_set;
    } *anyPolicy;
} X509_POLICY_CACHE;

X509_POLICY_DATA *policy_data_new(void *a, const ASN1_OBJECT *b, int c);
void policy_data_free(X509_POLICY_DATA *data);
int node_critical(X509_POLICY_NODE *node);
X509_POLICY_NODE *level_add_node(X509_POLICY_LEVEL *curr, X509_POLICY_DATA *data,
                                X509_POLICY_NODE *parent, X509_POLICY_TREE *tree,
                                ...);