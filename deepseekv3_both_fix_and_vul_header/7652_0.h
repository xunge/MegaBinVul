#include <stdlib.h>

typedef struct OPENSSL_LH_NODE {
    struct OPENSSL_LH_NODE *next;
} OPENSSL_LH_NODE;

typedef struct OPENSSL_LHASH {
    OPENSSL_LH_NODE **b;
    unsigned int num_nodes;
    unsigned int num_items;
} OPENSSL_LHASH;

void OPENSSL_free(void *ptr);