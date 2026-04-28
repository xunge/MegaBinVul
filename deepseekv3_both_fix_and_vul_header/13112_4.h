#include <stddef.h>

#define POLICY_DATA_FLAG_SHARED_QUALIFIERS 0x1

typedef struct X509_POLICY_DATA_st X509_POLICY_DATA;
typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;
typedef struct X509_POLICY_NODE_st X509_POLICY_NODE;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct ASN1_OBJECT_st ASN1_OBJECT;

struct X509_POLICY_DATA_st {
    const ASN1_OBJECT *valid_policy;
    void *qualifier_set;
    unsigned int flags;
};

struct X509_POLICY_NODE_st {
    X509_POLICY_DATA *data;
};

struct X509_POLICY_CACHE_st {
    struct {
        void *qualifier_set;
    } *anyPolicy;
};

static int node_critical(X509_POLICY_NODE *node) { return 0; }
static X509_POLICY_DATA *ossl_policy_data_new(void *a, const ASN1_OBJECT *b, int c) { return NULL; }
static void ossl_policy_data_free(X509_POLICY_DATA *data) {}
static void *ossl_policy_level_add_node(X509_POLICY_LEVEL *curr, X509_POLICY_DATA *data, X509_POLICY_NODE *node, X509_POLICY_TREE *tree, ...) { return NULL; }