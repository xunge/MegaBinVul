typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_CACHE_st {
    void *data;
} X509_POLICY_CACHE;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_DATA_st X509_POLICY_DATA;

int sk_X509_POLICY_DATA_num(void *sk);
X509_POLICY_DATA *sk_X509_POLICY_DATA_value(void *sk, int idx);

int tree_link_matching_nodes_3args(X509_POLICY_LEVEL *curr, X509_POLICY_DATA *data, X509_POLICY_TREE *tree);
int tree_link_matching_nodes_2args(X509_POLICY_LEVEL *curr, X509_POLICY_DATA *data);