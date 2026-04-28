#include <stddef.h>

typedef struct EVP_PKEY EVP_PKEY;
typedef struct bio_st BIO;

typedef int VALUE;
typedef VALUE (*ossl_pem_passwd_cb_t)(char *, int, int, void *);

extern VALUE ossl_pem_passwd_value(VALUE);
extern BIO *ossl_obj2bio(VALUE *);
extern void OSSL_BIO_reset(BIO *);
extern VALUE ossl_pkey_new(EVP_PKEY *);
extern VALUE ePKeyError;
extern void ossl_raise(VALUE, const char *);
extern void BIO_free(BIO *);
extern EVP_PKEY *d2i_PrivateKey_bio(BIO *, EVP_PKEY **);
extern EVP_PKEY *PEM_read_bio_PrivateKey(BIO *, EVP_PKEY **, ossl_pem_passwd_cb_t, void *);
extern EVP_PKEY *d2i_PUBKEY_bio(BIO *, EVP_PKEY **);
extern EVP_PKEY *PEM_read_bio_PUBKEY(BIO *, EVP_PKEY **, ossl_pem_passwd_cb_t, void *);
extern void rb_scan_args(int, VALUE *, const char *, ...);

extern ossl_pem_passwd_cb_t ossl_pem_passwd_cb;