#include <stdlib.h>

#define ALPHABET_SIZE 256

typedef struct r_trie_node {
	struct r_trie_node *child[ALPHABET_SIZE];
} RTrieNode;

#define R_FREE(x) free(x)