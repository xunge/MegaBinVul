typedef struct cert_st {
    unsigned long mask_a;
    unsigned long mask_k;
    unsigned long mask_ssl;
    int valid;
} CERT;

typedef struct srp_ctx_st {
    unsigned long srp_Mask;
} SRP_CTX;

typedef struct ssl_st {
    CERT *cert;
    void *kssl_ctx;
    void *psk_client_callback;
    SRP_CTX srp_ctx;
} SSL;

#define SSL_CLIENT_USE_TLS1_2_CIPHERS(s) 0
#define SSL_TLSV1_2 0
#define SSL_SECOP_SIGALG_MASK 0
#define SSL_aRSA 0x01
#define SSL_kDHr 0x02
#define SSL_kECDHr 0x04
#define SSL_aDSS 0x08
#define SSL_kDHd 0x10
#define SSL_aECDSA 0x20
#define SSL_kECDHe 0x40
#define SSL_aKRB5 0x80
#define SSL_kKRB5 0x100
#define SSL_aPSK 0x200
#define SSL_kPSK 0x400
#define SSL_aSRP 0x800
#define SSL_kSRP 0x1000
#define OPENSSL_NO_KRB5
#define OPENSSL_NO_PSK
#define OPENSSL_NO_SRP

void ssl_set_sig_mask(unsigned long *mask, SSL *s, int op);