#include <stdint.h>
#include <string.h>

#define PJ_DEF(x) x
#define PJSIP_AUTH_HAS_DIGEST_SHA256 1
#define PJSIP_SHA256STRLEN 64
#define PASSWD_MASK 0x0F
#define PJSIP_CRED_DATA_PLAIN_PASSWD 0x01
#define PJSIP_CRED_DATA_DIGEST 0x02
#define PJ_EINVAL 22
#define PJ_SUCCESS 0
#define THIS_FILE "pjsip_auth.c"
#define AUTH_TRACE_(x)

typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pjsip_cred_info {
    pj_str_t username;
    pj_str_t data;
    int data_type;
} pjsip_cred_info;

typedef int pj_status_t;

typedef struct SHA256_CTX {
    uint64_t length;
    uint32_t state[8];
    uint32_t curlen;
    unsigned char buf[64];
} SHA256_CTX;

void SHA256_Init(SHA256_CTX *ctx);
void SHA256_Update(SHA256_CTX *ctx, const void *data, size_t len);
void SHA256_Final(unsigned char *digest, SHA256_CTX *ctx);
void digestNtoStr(const unsigned char *digest, int len, char *out);
void pj_assert(const char *expr);
void pj_bzero(void *s, int n);
void pj_memcpy(void *dst, const void *src, int n);