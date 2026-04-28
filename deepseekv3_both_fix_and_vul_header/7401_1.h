#include <stdint.h>
#include <string.h>

typedef int pj_status_t;
typedef uint8_t pj_uint8_t;
typedef struct pj_pool_t pj_pool_t;
typedef struct pj_str_t {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct pjsip_digest_challenge {
    pj_str_t algorithm;
    pj_str_t nonce;
    pj_str_t realm;
} pjsip_digest_challenge;

typedef struct pjsip_cred_info {
    int data_type;
    pj_str_t data;
    struct {
        struct {
            pj_str_t k;
            pj_str_t op;
            pj_str_t amf;
        } aka;
    } ext;
} pjsip_cred_info;

typedef struct pjsip_digest_credential {
    pj_str_t response;
    pj_str_t nonce;
    pj_str_t nc;
    pj_str_t cnonce;
    pj_str_t qop;
    pj_str_t uri;
    pj_str_t realm;
} pjsip_digest_credential;

#define PJSIP_AKA_KLEN 16
#define PJSIP_AKA_OPLEN 16
#define PJSIP_AKA_AMFLEN 2
#define PJSIP_AKA_RESLEN 8
#define PJSIP_AKA_CKLEN 16
#define PJSIP_AKA_IKLEN 16
#define PJSIP_AKA_AKLEN 6
#define PJSIP_AKA_SQNLEN 6
#define PJSIP_AKA_MACLEN 8
#define PJSIP_AKA_RANDLEN 16
#define PJSIP_AKA_AUTNLEN 14

#define PJSIP_CRED_DATA_PLAIN_PASSWD 0
#define PJSIP_EINVALIDALGORITHM (-1)
#define PJSIP_EAUTHINNONCE (-2)
#define PJ_SUCCESS 0
#define PJ_EBUG (-3)

#define PJ_BASE64_TO_BASE256_LEN(len) (((len) * 3) / 4)
#define PJ_BASE256_TO_BASE64_LEN(len) (((len) * 4 + 2) / 3)
#define PJ_ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

#define PJ_DEF(type) type

void pj_bzero(void *s, size_t n);
void pj_memcpy(void *dest, const void *src, size_t n);
int pj_memcmp(const void *s1, const void *s2, size_t n);
int pj_stricmp(const pj_str_t *s1, const pj_str_t *s2);
int pj_stricmp2(const pj_str_t *s1, const char *s2);
pj_status_t pj_base64_decode(const pj_str_t *input, uint8_t *out, int *out_len);
pj_status_t pj_base64_encode(const uint8_t *input, int in_len, char *out, int *out_len);
void pj_hmac_md5(const uint8_t *key, int key_len, const uint8_t *text, int text_len, uint8_t *digest);
void *pj_pool_alloc(pj_pool_t *pool, int size);
void f2345(const uint8_t *k, const uint8_t *rand, uint8_t *res, uint8_t *ck, uint8_t *ik, uint8_t *ak, const uint8_t *op);
void f1(const uint8_t *k, const uint8_t *rand, const uint8_t *sqn, const uint8_t *amf, uint8_t *mac, const uint8_t *op);
pj_status_t pjsip_auth_create_digest(pj_str_t *response, const pj_str_t *nonce, const pj_str_t *nc, const pj_str_t *cnonce, const pj_str_t *qop, const pj_str_t *uri, const pj_str_t *realm, const pjsip_cred_info *cred, const pj_str_t *method);