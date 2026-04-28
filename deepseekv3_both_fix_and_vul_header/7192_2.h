typedef struct OTHERNAME_st {
    void *value;
} OTHERNAME;

typedef struct GENERAL_NAME_st {
    int type;
    union {
        OTHERNAME *otherName;
        void *directoryName;
        void *dNSName;
        void *rfc822Name;
        void *uniformResourceIdentifier;
        void *iPAddress;
    } d;
} GENERAL_NAME;

#define GEN_OTHERNAME 0
#define GEN_DIRNAME 1
#define GEN_DNS 2
#define GEN_EMAIL 3
#define GEN_URI 4
#define GEN_IPADD 5

#define X509_V_ERR_UNSUPPORTED_CONSTRAINT_TYPE 1000

int nc_email_eai(void *a, void *b);
int nc_dn(void *a, void *b);
int nc_dns(void *a, void *b);
int nc_email(void *a, void *b);
int nc_uri(void *a, void *b);
int nc_ip(void *a, void *b);