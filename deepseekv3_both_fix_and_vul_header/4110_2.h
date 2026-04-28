#include <string.h>
#include <stdlib.h>

#define SHA_DIGEST_LENGTH 20

typedef struct srp_user_pwd_st SRP_user_pwd;
typedef struct srp_vbase_st SRP_VBASE;
typedef struct bignum_st BIGNUM;
typedef struct stack_st_SRP_user_pwd STACK_OF_SRP_user_pwd;

struct evp_md_ctx_st {
    void *digest;
    void *engine;
    unsigned long flags;
    void *md_data;
};

typedef struct evp_md_ctx_st EVP_MD_CTX;

struct srp_vbase_st {
    STACK_OF_SRP_user_pwd *users_pwd;
    char *seed_key;
    BIGNUM *default_g;
    BIGNUM *default_N;
};

struct srp_user_pwd_st {
    char *id;
    BIGNUM *s;
    BIGNUM *v;
    const BIGNUM *g;
    const BIGNUM *N;
};

const void *EVP_sha1(void);

int sk_SRP_user_pwd_num(STACK_OF_SRP_user_pwd *sk);
SRP_user_pwd *sk_SRP_user_pwd_value(STACK_OF_SRP_user_pwd *sk, int idx);
SRP_user_pwd *SRP_user_pwd_new(void);
void SRP_user_pwd_free(SRP_user_pwd *user_pwd);
int SRP_user_pwd_set_gN(SRP_user_pwd *user, const BIGNUM *g, const BIGNUM *N);
int SRP_user_pwd_set_ids(SRP_user_pwd *user, const char *id, const char *info);
int SRP_user_pwd_set_sv_BN(SRP_user_pwd *user, BIGNUM *s, BIGNUM *v);
int RAND_pseudo_bytes(unsigned char *buf, int num);
void EVP_MD_CTX_init(EVP_MD_CTX *ctx);
int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const void *type, void *impl);
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx);
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret);