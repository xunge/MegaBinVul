#include <stdio.h>
#include <stdlib.h>

#define CMS_F_CMS_DECRYPT 0
#define CMS_R_TYPE_NOT_ENVELOPED_DATA 0
#define NID_pkcs7_enveloped 0
#define CMS_DEBUG_DECRYPT 0

typedef struct CMS_ContentInfo CMS_ContentInfo;
typedef struct EVP_PKEY EVP_PKEY;
typedef struct X509 X509;
typedef struct BIO BIO;

struct CMS_ContentInfo {
    union {
        struct CMS_EnvelopedData *envelopedData;
    } d;
};

struct CMS_EnvelopedData {
    struct CMS_EncryptedContentInfo *encryptedContentInfo;
};

struct CMS_EncryptedContentInfo {
    int debug;
    int havenocert;
};

void CMSerr(int a, int b);
int OBJ_obj2nid(int a);
int CMS_get0_type(CMS_ContentInfo *a);
int check_content(CMS_ContentInfo *a);
int CMS_decrypt_set1_pkey(CMS_ContentInfo *a, EVP_PKEY *b, X509 *c);
BIO *CMS_dataInit(CMS_ContentInfo *a, BIO *b);
int cms_copy_content(BIO *a, BIO *b, unsigned int c);
void do_free_upto(BIO *a, BIO *b);