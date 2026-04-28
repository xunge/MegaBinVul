typedef struct ASN1_STRING_st ASN1_STRING;
typedef struct ASN1_OBJECT_st ASN1_OBJECT;
typedef struct ASN1_OCTET_STRING_st ASN1_OCTET_STRING;
typedef struct ASN1_TYPE_st ASN1_TYPE;
typedef struct X509_NAME_st X509_NAME;
typedef struct EDIPartyName_st EDIPartyName;
typedef struct OTHERNAME_st OTHERNAME;

typedef struct GENERAL_NAME_st {
    int type;
    union {
        ASN1_STRING *ia5;
        ASN1_OCTET_STRING *ip;
        ASN1_OBJECT *rid;
        X509_NAME *dirn;
        ASN1_TYPE *x400Address;
        EDIPartyName *ediPartyName;
        OTHERNAME *otherName;
    } d;
} GENERAL_NAME;

#define GEN_OTHERNAME 0
#define GEN_EMAIL 1
#define GEN_DNS 2
#define GEN_X400 3
#define GEN_DIRNAME 4
#define GEN_EDIPARTY 5
#define GEN_URI 6
#define GEN_IPADD 7
#define GEN_RID 8

int ASN1_TYPE_cmp(ASN1_TYPE *a, ASN1_TYPE *b);
int edipartyname_cmp(EDIPartyName *a, EDIPartyName *b);
int OTHERNAME_cmp(OTHERNAME *a, OTHERNAME *b);
int ASN1_STRING_cmp(ASN1_STRING *a, ASN1_STRING *b);
int X509_NAME_cmp(X509_NAME *a, X509_NAME *b);
int ASN1_OCTET_STRING_cmp(ASN1_OCTET_STRING *a, ASN1_OCTET_STRING *b);
int OBJ_cmp(ASN1_OBJECT *a, ASN1_OBJECT *b);