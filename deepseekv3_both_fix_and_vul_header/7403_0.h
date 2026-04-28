#include <stddef.h>
#include <string.h>

#define PJ_DEF(x) x
#define PJSIP_MD5STRLEN 32
#define PASSWD_MASK 0x0F
#define PJSIP_CRED_DATA_PLAIN_PASSWD 0x01
#define PJSIP_CRED_DATA_DIGEST 0x02
#define PJ_EINVAL 22
#define PJ_SUCCESS 0
#define THIS_FILE __FILE__

typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pjsip_cred_info {
    pj_str_t username;
    pj_str_t data;
    int data_type;
} pjsip_cred_info;

typedef struct pj_md5_context {
    unsigned char buf[64];
    unsigned int state[4];
    unsigned int bits[2];
    unsigned char in[64];
} pj_md5_context;

typedef int pj_status_t;

#define AUTH_TRACE_(x)
#define MD5_APPEND(ctx, data, len) pj_md5_update(ctx, (const unsigned char*)data, len)

void pj_md5_init(pj_md5_context *ctx);
void pj_md5_update(pj_md5_context *ctx, const unsigned char *data, unsigned int len);
void pj_md5_final(pj_md5_context *ctx, unsigned char digest[16]);
void pj_bzero(void *s, size_t n);
void pj_memcpy(void *dst, const void *src, size_t n);
void pj_assert(int expr);
void digestNtoStr(const unsigned char *digest, int len, char *out);