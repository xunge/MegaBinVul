#include <string.h>
#include <stdlib.h>

#define ASN1_MAX_NAME_SIZE 64

typedef struct asn1_node_st *asn1_node;
struct asn1_node_st {
    char *name;
    unsigned int name_hash;
    asn1_node right;
    asn1_node down;
};

unsigned int hash_pjw_bare(const char *str, unsigned int len);
int _asn1_str_cpy(char *dest, size_t dest_size, const char *src);