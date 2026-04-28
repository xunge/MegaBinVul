typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_DATA_st X509_POLICY_DATA;

struct X509_POLICY_CACHE_st {
    void *data;
};

struct stack_st_X509_POLICY_DATA;
typedef struct stack_st_X509_POLICY_DATA STACK_OF_X509_POLICY_DATA;

int sk_X509_POLICY_DATA_num(STACK_OF_X509_POLICY_DATA *sk);
X509_POLICY_DATA *sk_X509_POLICY_DATA_value(STACK_OF_X509_POLICY_DATA *sk, int idx);

static int tree_link_matching_nodes(X509_POLICY_LEVEL *curr, X509_POLICY_DATA *data, ...);