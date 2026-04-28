typedef struct X509_POLICY_TREE_st X509_POLICY_TREE;
typedef struct X509_POLICY_LEVEL_st X509_POLICY_LEVEL;
typedef struct X509_POLICY_CACHE_st X509_POLICY_CACHE;

struct X509_POLICY_TREE_st {
    int nlevel;
    X509_POLICY_LEVEL *levels;
};

struct X509_POLICY_LEVEL_st {
    int flags;
    void *cert;
};

#define X509_PCY_TREE_VALID 1
#define X509_PCY_TREE_INTERNAL 2
#define X509_V_FLAG_INHIBIT_ANY 0x40

#define TREE_PRINT(str, tree, curr)