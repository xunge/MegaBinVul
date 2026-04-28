#include <stddef.h>

typedef struct ASN1_OBJECT_st ASN1_OBJECT;

typedef struct X509_POLICY_NODE_st {
    int dummy;
} X509_POLICY_NODE;

typedef struct stack_st_X509_POLICY_NODE {
    X509_POLICY_NODE **data;
    int num;
} STACK_OF_X509_POLICY_NODE;

typedef struct X509_POLICY_LEVEL_st {
    STACK_OF_X509_POLICY_NODE *nodes;
    X509_POLICY_NODE *anyPolicy;
} X509_POLICY_LEVEL;

typedef struct X509_POLICY_DATA_st {
    ASN1_OBJECT *valid_policy;
} X509_POLICY_DATA;

typedef struct X509_POLICY_TREE_st {
    int dummy;
} X509_POLICY_TREE;

int sk_X509_POLICY_NODE_num(const STACK_OF_X509_POLICY_NODE *sk);
X509_POLICY_NODE *sk_X509_POLICY_NODE_value(const STACK_OF_X509_POLICY_NODE *sk, int idx);

int ossl_policy_node_match(const X509_POLICY_LEVEL *level,
                          const X509_POLICY_NODE *node, const ASN1_OBJECT *oid);
X509_POLICY_NODE *ossl_policy_level_add_node(X509_POLICY_LEVEL *level,
                                            X509_POLICY_DATA *data,
                                            X509_POLICY_NODE *parent,
                                            X509_POLICY_TREE *tree, ...);