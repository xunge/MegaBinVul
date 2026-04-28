struct X509_algor_st;
struct ASN1_BIT_STRING_st;
struct ASN1_ITEM_st;
struct evp_pkey_st;

struct X509_cinf_st {
    struct X509_algor_st *signature;
};

struct X509_st {
    struct X509_algor_st *sig_alg;
    struct ASN1_BIT_STRING_st *signature;
    struct X509_cinf_st *cert_info;
};

typedef struct X509_algor_st X509_ALGOR;
typedef struct X509_cinf_st X509_CINF;
typedef struct X509_st X509;
typedef struct evp_pkey_st EVP_PKEY;
typedef struct ASN1_ITEM_st ASN1_ITEM;
typedef struct ASN1_BIT_STRING_st ASN1_BIT_STRING;

extern const ASN1_ITEM X509_CINF_it;

#define ASN1_ITEM_rptr(type) (&type##_it)

int X509_ALGOR_cmp(const X509_ALGOR *a, const X509_ALGOR *b);
int ASN1_item_verify(const ASN1_ITEM *it, X509_ALGOR *a,
                     ASN1_BIT_STRING *signature, void *asn, EVP_PKEY *pkey);