#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_ONELINE_MAX 1024
#define CHARSET_EBCDIC

typedef struct X509_NAME_ENTRY_st {
    struct asn1_object_st *object;
    struct asn1_string_st *value;
} X509_NAME_ENTRY;

typedef struct stack_st_X509_NAME_ENTRY {
    X509_NAME_ENTRY **data;
    int num;
} STACK_OF_X509_NAME_ENTRY;

typedef struct X509_NAME_st {
    STACK_OF_X509_NAME_ENTRY *entries;
} X509_NAME;

typedef struct BUF_MEM {
    size_t length;
    char *data;
    size_t max;
} BUF_MEM;

typedef struct asn1_object_st ASN1_OBJECT;
typedef struct asn1_string_st {
    int type;
    int length;
    unsigned char *data;
} ASN1_STRING;

#define NID_undef 0
#define V_ASN1_GENERALSTRING 27
#define V_ASN1_VISIBLESTRING 26
#define V_ASN1_PRINTABLESTRING 19
#define V_ASN1_TELETEXSTRING 20
#define V_ASN1_IA5STRING 22

#define X509_F_X509_NAME_ONELINE 0
#define X509_R_NAME_TOO_LONG 0
#define ERR_R_MALLOC_FAILURE 0

extern const unsigned char os_toascii[256];

BUF_MEM *BUF_MEM_new(void);
void BUF_MEM_free(BUF_MEM *a);
int BUF_MEM_grow(BUF_MEM *str, size_t len);
void OPENSSL_free(void *addr);
int sk_X509_NAME_ENTRY_num(STACK_OF_X509_NAME_ENTRY *sk);
X509_NAME_ENTRY *sk_X509_NAME_ENTRY_value(STACK_OF_X509_NAME_ENTRY *sk, int idx);
int OBJ_obj2nid(const ASN1_OBJECT *o);
const char *OBJ_nid2sn(int n);
int i2t_ASN1_OBJECT(char *buf, int buf_len, const ASN1_OBJECT *a);
void X509err(int f, int r);
void ascii2ebcdic(char *dest, const unsigned char *src, int len);