#include <stdlib.h>

typedef struct bio_st BIO;
typedef struct asn1_value_st ASN1_VALUE;

typedef struct asn1_item_st {
    const struct asn1_aux_st *funcs;
} ASN1_ITEM;

typedef struct asn1_aux_st {
    int (*asn1_cb)(int, ASN1_VALUE **, const ASN1_ITEM *, void *);
} ASN1_AUX;

typedef struct ndef_aux_st {
    ASN1_VALUE *val;
    const ASN1_ITEM *it;
    BIO *ndef_bio;
    unsigned char *boundary;
    BIO *out;
} NDEF_SUPPORT;

typedef struct asn1_stream_arg_st {
    BIO *out;
    BIO *ndef_bio;
    unsigned char *boundary;
} ASN1_STREAM_ARG;

typedef void *asn1_ps_func;

#define ERR_LIB_ASN1 13
#define ASN1_R_STREAMING_NOT_SUPPORTED 100
#define ASN1_OP_STREAM_PRE 0
#define BIO_C_SET_EX_ARG 119

extern void *ndef_prefix;
extern void *ndef_prefix_free;
extern void *ndef_suffix;
extern void *ndef_suffix_free;

void ERR_raise(int lib, int reason);
void *OPENSSL_zalloc(size_t size);
void OPENSSL_free(void *ptr);
BIO *BIO_new(void *method);
BIO *BIO_push(BIO *b, BIO *append);
void BIO_free(BIO *a);
int BIO_ctrl(BIO *bp, int cmd, long larg, void *parg);
void *BIO_f_asn1(void);
int BIO_asn1_set_prefix(BIO *b, asn1_ps_func *prefix, asn1_ps_func *prefix_free);
int BIO_asn1_set_suffix(BIO *b, asn1_ps_func *suffix, asn1_ps_func *suffix_free);