#include <stddef.h>

typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_NODE_st X509_POLICY_NODE;
typedef struct X509_POLICY_DATA_st X509_POLICY_DATA;
typedef struct ASN1_OBJECT_st ASN1_OBJECT;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;

struct X509_POLICY_LEVEL_st {
    void *nodes;
    X509_POLICY_NODE *anyPolicy;
};

struct X509_POLICY_DATA_st {
    ASN1_OBJECT *valid_policy;
};

int sk_X509_POLICY_NODE_num(void *sk);
X509_POLICY_NODE *sk_X509_POLICY_NODE_value(void *sk, int idx);

static int policy_node_match(X509_POLICY_LEVEL *level, X509_POLICY_NODE *node, ASN1_OBJECT *oid);
static X509_POLICY_NODE *level_add_node(X509_POLICY_LEVEL *level, X509_POLICY_DATA *data,
                                        X509_POLICY_NODE *parent, X509_POLICY_TREE *tree, ...);