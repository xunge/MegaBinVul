#include <stdio.h>
#include <stdlib.h>

typedef struct CMS_ContentInfo CMS_ContentInfo;
typedef struct CMS_SignerInfo CMS_SignerInfo;
typedef struct X509_store_st X509_STORE;
typedef struct X509_crl_st X509_CRL;
typedef struct bio_st BIO;
typedef struct stack_st STACK;
typedef struct x509_st X509;

#define STACK_OF(type) STACK
#define sk_CMS_SignerInfo_num(sk) sk_num((STACK *)sk)
#define sk_CMS_SignerInfo_value(sk, i) (CMS_SignerInfo *)sk_value((STACK *)sk, i)
#define sk_X509_num(sk) sk_num((STACK *)sk)
#define sk_X509_value(sk, i) (X509 *)sk_value((STACK *)sk, i)
#define sk_X509_CRL_num(sk) sk_num((STACK *)sk)
#define sk_X509_CRL_value(sk, i) (X509_CRL *)sk_value((STACK *)sk, i)
#define sk_X509_pop_free(sk, free_func) sk_pop_free((STACK *)sk, (void (*)(void *))free_func)
#define sk_X509_CRL_pop_free(sk, free_func) sk_pop_free((STACK *)sk, (void (*)(void *))free_func)

#define CMS_F_CMS_VERIFY 0
#define CMS_R_NO_SIGNERS 0
#define CMS_R_SIGNER_CERTIFICATE_NOT_FOUND 0
#define CMS_R_SMIME_TEXT_ERROR 0
#define CMS_R_CONTENT_VERIFY_ERROR 0
#define CMS_NO_SIGNER_CERT_VERIFY 0
#define CMS_NOCRL 0
#define CMS_NO_ATTR_VERIFY 0
#define SMIME_BINARY 0
#define CMS_TEXT 0
#define SMIME_TEXT 0
#define CMS_NO_CONTENT_VERIFY 0
#define BIO_TYPE_MEM 0
#define ERR_R_MALLOC_FAILURE 0

int sk_num(const STACK *sk);
void *sk_value(const STACK *sk, int idx);
void sk_pop_free(STACK *sk, void (*func)(void *));

int check_content(CMS_ContentInfo *cms);
STACK *CMS_get0_SignerInfos(CMS_ContentInfo *cms);
void CMS_SignerInfo_get0_algs(CMS_SignerInfo *si, void *pk, X509 **signer, void *pdig, void *psig);
int CMS_set1_signers_certs(CMS_ContentInfo *cms, STACK *certs, unsigned int flags);
STACK *CMS_get1_certs(CMS_ContentInfo *cms);
STACK *CMS_get1_crls(CMS_ContentInfo *cms);
int cms_signerinfo_verify_cert(CMS_SignerInfo *si, X509_STORE *store, STACK *certs, STACK *crls, unsigned int flags);
int CMS_signed_get_attr_count(const CMS_SignerInfo *si);
int CMS_SignerInfo_verify(CMS_SignerInfo *si);
BIO *CMS_dataInit(CMS_ContentInfo *cms, BIO *icont);
int SMIME_crlf_copy(BIO *in, BIO *out, int flags);
int SMIME_text(BIO *in, BIO *out);
int cms_copy_content(BIO *out, BIO *cmsbio, unsigned int flags);
int CMS_SignerInfo_verify_content(CMS_SignerInfo *si, BIO *chain);
void do_free_upto(BIO *f, BIO *upto);
BIO *cms_get_text_bio(BIO *out, unsigned int flags);
void CMSerr(int f, int r);
long BIO_get_mem_data(BIO *b, char **pp);
BIO *BIO_new_mem_buf(const void *buf, int len);
int BIO_method_type(const BIO *b);
void BIO_free_all(BIO *a);
void BIO_free(BIO *a);
void X509_free(X509 *a);
void X509_CRL_free(X509_CRL *a);