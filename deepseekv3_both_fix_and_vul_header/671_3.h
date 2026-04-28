#include <stddef.h>

typedef struct pam_handle_t pam_handle_t;
typedef struct PKCS11_KEY PKCS11_KEY;
typedef struct EVP_MD_CTX EVP_MD_CTX;
typedef struct EVP_MD EVP_MD;
typedef struct EVP_PKEY EVP_PKEY;

#define LOG_DEBUG 7
#define PAM_ERROR_MSG 3

const EVP_MD *EVP_sha1(void);
EVP_MD_CTX *EVP_MD_CTX_new(void);
int EVP_SignInit(EVP_MD_CTX *ctx, const EVP_MD *type);
int EVP_SignUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
int EVP_SignFinal(EVP_MD_CTX *ctx, unsigned char *sig, unsigned int *s, EVP_PKEY *pkey);
int EVP_VerifyInit(EVP_MD_CTX *ctx, const EVP_MD *type);
int EVP_VerifyUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
int EVP_VerifyFinal(EVP_MD_CTX *ctx, const unsigned char *sigbuf, unsigned int siglen, EVP_PKEY *pkey);
int EVP_MD_CTX_reset(EVP_MD_CTX *ctx);
void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
void EVP_PKEY_free(EVP_PKEY *pkey);
EVP_PKEY *PKCS11_get_private_key(PKCS11_KEY *key);
EVP_PKEY *PKCS11_get_public_key(PKCS11_KEY *key);
unsigned long ERR_get_error(void);
const char *ERR_reason_error_string(unsigned long e);
int randomize(pam_handle_t *pamh, unsigned char *buf, size_t len);
void pam_syslog(pam_handle_t *pamh, int priority, const char *fmt, ...);
void prompt(int flags, pam_handle_t *pamh, int style, const char *name, const char *fmt, ...);
const char *_(const char *msg);