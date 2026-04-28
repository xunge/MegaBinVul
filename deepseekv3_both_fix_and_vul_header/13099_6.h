#define X509_PCY_TREE_VALID 1
#define X509_PCY_TREE_INTERNAL 2
#define X509_V_FLAG_INHIBIT_ANY 0x100

typedef struct X509_st X509;

struct X509_POLICY_LEVEL {
    X509 *cert;
    unsigned long flags;
    struct X509_POLICY_LEVEL *next;
};

struct X509_POLICY_TREE {
    struct X509_POLICY_LEVEL *levels;
    int nlevel;
};

struct X509_POLICY_CACHE {
    /* cache structure members */
};

typedef struct X509_POLICY_LEVEL X509_POLICY_LEVEL;
typedef struct X509_POLICY_TREE X509_POLICY_TREE;
typedef struct X509_POLICY_CACHE X509_POLICY_CACHE;

extern const X509_POLICY_CACHE *policy_cache_set(X509 *cert);
extern int tree_link_nodes_2(X509_POLICY_LEVEL *curr, const X509_POLICY_CACHE *cache);
extern int tree_link_nodes_3(X509_POLICY_LEVEL *curr, const X509_POLICY_CACHE *cache, X509_POLICY_TREE *tree);
extern int tree_link_any(X509_POLICY_LEVEL *curr, const X509_POLICY_CACHE *cache, X509_POLICY_TREE *tree);
extern int tree_prune(X509_POLICY_TREE *tree, X509_POLICY_LEVEL *curr);
#ifdef OPENSSL_POLICY_DEBUG
extern void tree_print(const char *str, X509_POLICY_TREE *tree, X509_POLICY_LEVEL *curr);
#endif