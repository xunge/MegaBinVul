#include <string.h>

typedef int pj_status_t;
typedef long pj_ssize_t;

typedef struct pj_str_t {
    char *ptr;
    pj_ssize_t slen;
} pj_str_t;

typedef struct pjsip_cred_info {
    pj_str_t username;
    pj_str_t realm;
} pjsip_cred_info;

typedef struct pjsip_digest_credential {
    pj_str_t username;
    pj_str_t realm;
    pj_str_t nonce;
    pj_str_t nc;
    pj_str_t cnonce;
    pj_str_t qop;
    pj_str_t uri;
    pj_str_t response;
} pjsip_digest_credential;

typedef struct pjsip_authorization_hdr {
    pj_str_t scheme;
    union {
        pjsip_digest_credential digest;
    } credential;
} pjsip_authorization_hdr;

#define PJSIP_MD5STRLEN 32
#define PJ_SUCCESS 0
#define PJ_EINVALIDOP (-1)
#define PJSIP_EAUTHINVALIDDIGEST (-2)
#define PJSIP_EINVALIDAUTHSCHEME (-3)

static const pj_str_t pjsip_DIGEST_STR = { "Digest", 6 };

#define PJ_ASSERT_RETURN(expr, ret) do { \
    if (!(expr)) return (ret); \
} while (0)

static int pj_stricmp(const pj_str_t *str1, const pj_str_t *str2) {
    return strncasecmp(str1->ptr, str2->ptr, str1->slen < str2->slen ? str1->slen : str2->slen);
}

static int pj_strcmp(const pj_str_t *str1, const pj_str_t *str2) {
    int result = strncmp(str1->ptr, str2->ptr, str1->slen < str2->slen ? str1->slen : str2->slen);
    if (result == 0) {
        return (int)(str1->slen - str2->slen);
    }
    return result;
}

static void pj_assert(const char *expr) {
    (void)expr;
    /* assertion failed */
}

static pj_status_t pjsip_auth_create_digest(pj_str_t *digest,
                                          const pj_str_t *nonce,
                                          const pj_str_t *nc,
                                          const pj_str_t *cnonce,
                                          const pj_str_t *qop,
                                          const pj_str_t *uri,
                                          const pj_str_t *realm,
                                          const pjsip_cred_info *cred_info,
                                          const pj_str_t *method) {
    /* dummy implementation */
    return PJ_SUCCESS;
}