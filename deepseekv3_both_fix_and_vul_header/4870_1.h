#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct asn1_object_st {
    const char *sn;
    const char *ln;
    int nid;
    int length;
    unsigned char *data;
    int flags;
} ASN1_OBJECT;

#define ASN1_OBJECT_FLAG_DYNAMIC 0x01
#define ASN1_OBJECT_FLAG_DYNAMIC_DATA 0x02

#define ASN1_F_C2I_ASN1_OBJECT 0
#define ASN1_R_INVALID_OBJECT_ENCODING 0
#define ERR_R_MALLOC_FAILURE 0

void ASN1err(int a, int b);
ASN1_OBJECT *ASN1_OBJECT_new(void);
void ASN1_OBJECT_free(ASN1_OBJECT *a);
void *OPENSSL_malloc(size_t size);
void OPENSSL_free(void *ptr);