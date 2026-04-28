#include <stdlib.h>

#define R_API
#define R_FREE(x) free(x)

typedef struct r_trie_node_t RTrieNode;
typedef struct r_trie_t {
    RTrieNode *root;
} RTrie;

void r_trie_node_free(RTrieNode *node);