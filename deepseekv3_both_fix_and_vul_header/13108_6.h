#define X509_PCY_TREE_VALID 1
#define X509_PCY_TREE_INTERNAL 2
#define X509_V_FLAG_INHIBIT_ANY 0x1000
#define TREE_PRINT(s, t, c)

struct X509_POLICY_LEVEL_st {
    struct X509_st *cert;
    int flags;
    struct X509_POLICY_LEVEL_st *next;
};

struct X509_POLICY_TREE_st {
    struct X509_POLICY_LEVEL_st *levels;
    int nlevel;
};

typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;
typedef struct X509_st X509;

extern const X509_POLICY_CACHE *ossl_policy_cache_set(X509 *cert);
extern int tree_link_nodes_2(X509_POLICY_LEVEL *curr, const X509_POLICY_CACHE *cache);
extern int tree_link_nodes_3(X509_POLICY_LEVEL *curr, const X509_POLICY_CACHE *cache, X509_POLICY_TREE *tree);
extern int tree_link_any(X509_POLICY_LEVEL *curr, const X509_POLICY_CACHE *cache, X509_POLICY_TREE *tree);
extern int tree_prune(X509_POLICY_TREE *tree, X509_POLICY_LEVEL *curr);