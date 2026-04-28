#include <string.h>
#include <stddef.h>

#define SSL_F_SSL2_GENERATE_KEY_MATERIAL 0
#define ERR_R_INTERNAL_ERROR 0

typedef struct ssl_st SSL;
typedef struct ssl_session_st SSL_SESSION;
typedef struct ssl2_state_st SSL2_STATE;
typedef struct evp_md_ctx_st {
    void *md_data;
    void *engine;
    unsigned int flags;
    void *digest;
} EVP_MD_CTX;
typedef struct env_md_st EVP_MD;

struct ssl_st {
    SSL_SESSION *session;
    SSL2_STATE *s2;
};

struct ssl_session_st {
    unsigned char master_key[48];
    int master_key_length;
};

struct ssl2_state_st {
    unsigned char key_material[512];
    unsigned int key_material_length;
    unsigned char challenge[32];
    unsigned int challenge_length;
    unsigned char conn_id[16];
    unsigned int conn_id_length;
};

void SSLerr(int a, int b);
const EVP_MD *EVP_md5(void);
int EVP_MD_size(const EVP_MD *md);
void EVP_MD_CTX_init(EVP_MD_CTX *ctx);
void EVP_DigestInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, void *impl);
void EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
void EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md, unsigned int *s);
void EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx);
void OPENSSL_assert(int expr);