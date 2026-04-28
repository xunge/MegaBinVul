typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_DATA_st X509_POLICY_DATA;

struct X509_POLICY_CACHE_st {
    void *data;
};

typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;

int sk_X509_POLICY_DATA_num(void *sk);
X509_POLICY_DATA *sk_X509_POLICY_DATA_value(void *sk, int idx);

static int tree_link_matching_nodes_3(X509_POLICY_LEVEL *curr, X509_POLICY_DATA *data, X509_POLICY_TREE *tree);
static int tree_link_matching_nodes_2(X509_POLICY_LEVEL *curr, X509_POLICY_DATA *data);