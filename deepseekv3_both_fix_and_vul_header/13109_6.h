#include <stddef.h>

typedef struct X509_POLICY_NODE_st X509_POLICY_NODE;
typedef struct X509_POLICY_DATA_st {
    void *valid_policy;
} X509_POLICY_DATA;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_LEVEL_st {
    struct X509_POLICY_LEVEL_st *prev;
    struct X509_POLICY_LEVEL_st *next;
    X509_POLICY_NODE *anyPolicy;
    struct stack_st_X509_POLICY_NODE *nodes;
} X509_POLICY_LEVEL;

typedef struct stack_st_X509_POLICY_NODE STACK_OF_X509_POLICY_NODE;

int sk_X509_POLICY_NODE_num(const STACK_OF_X509_POLICY_NODE *sk);
X509_POLICY_NODE *sk_X509_POLICY_NODE_value(const STACK_OF_X509_POLICY_NODE *sk, int idx);

int ossl_policy_node_match(X509_POLICY_LEVEL *level, X509_POLICY_NODE *node, void *valid_policy);
X509_POLICY_NODE *ossl_policy_level_add_node(X509_POLICY_LEVEL *level,
                                           X509_POLICY_DATA *data,
                                           X509_POLICY_NODE *parent,
                                           X509_POLICY_TREE *tree,
                                           ...);