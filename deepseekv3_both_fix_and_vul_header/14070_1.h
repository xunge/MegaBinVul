#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef struct mbedtls_x509_buf {
    size_t len;
    unsigned char *p;
} mbedtls_x509_buf;

typedef struct mbedtls_x509_name {
    mbedtls_x509_buf oid;
    mbedtls_x509_buf val;
    struct mbedtls_x509_name *next;
} mbedtls_x509_name;

typedef struct mbedtls_x509_sequence {
    mbedtls_x509_buf buf;
    struct mbedtls_x509_sequence *next;
} mbedtls_x509_sequence;

typedef struct mbedtls_x509_time {
    int year, mon, day;
    int hour, min, sec;
} mbedtls_x509_time;

typedef struct mbedtls_pk_context {
    void *pk_info;
    void *pk_ctx;
} mbedtls_pk_context;

typedef struct mbedtls_x509_crt {
    mbedtls_x509_buf raw;
    mbedtls_x509_buf tbs;
    int version;
    mbedtls_x509_buf serial;
    mbedtls_x509_buf sig_oid;
    mbedtls_x509_buf issuer_raw;
    mbedtls_x509_buf subject_raw;
    mbedtls_x509_name issuer;
    mbedtls_x509_name subject;
    mbedtls_x509_time valid_from;
    mbedtls_x509_time valid_to;
    mbedtls_pk_context pk;
    mbedtls_x509_buf sig;
    mbedtls_x509_buf sig_opts;
    mbedtls_x509_sequence subject_alt_names;
    int ext_types;
    int ca_istrue;
    int max_pathlen;
    struct mbedtls_x509_crt *next;
} mbedtls_x509_crt;

typedef struct mbedtls_x509_crl {
    mbedtls_x509_buf raw;
    mbedtls_x509_buf tbs;
    int version;
    mbedtls_x509_buf sig_oid;
    mbedtls_x509_name issuer;
    mbedtls_x509_time this_update;
    mbedtls_x509_time next_update;
    mbedtls_x509_sequence revoked_certificates;
    mbedtls_x509_buf sig;
    struct mbedtls_x509_crl *next;
} mbedtls_x509_crl;

typedef struct mbedtls_x509_crt_profile {
    uint32_t allowed_mds;
    uint32_t allowed_pks;
    uint32_t allowed_curves;
    uint32_t rsa_min_bitlen;
} mbedtls_x509_crt_profile;

typedef enum {
    MBEDTLS_PK_NONE=0,
    MBEDTLS_PK_RSA,
    MBEDTLS_PK_ECKEY,
    MBEDTLS_PK_ECKEY_DH,
    MBEDTLS_PK_ECDSA,
    MBEDTLS_PK_RSA_ALT,
    MBEDTLS_PK_RSASSA_PSS,
} mbedtls_pk_type_t;

#define MBEDTLS_ERR_X509_BAD_INPUT_DATA -0x2800
#define MBEDTLS_ERR_X509_CERT_VERIFY_FAILED -0x2700
#define MBEDTLS_X509_BADCERT_CN_MISMATCH 0x01
#define MBEDTLS_X509_BADCERT_BAD_PK 0x02
#define MBEDTLS_X509_BADCERT_BAD_KEY 0x04
#define MBEDTLS_X509_EXT_SUBJECT_ALT_NAME 0x01
#define MBEDTLS_OID_AT_CN NULL
#define MBEDTLS_OID_CMP(a, b) 0

static int x509_memcasecmp(const char *s1, const char *s2, size_t len) { return 0; }
static int x509_check_wildcard(const char *cn, const mbedtls_x509_buf *name) { return 0; }
static int x509_profile_check_pk_alg(const mbedtls_x509_crt_profile *profile, mbedtls_pk_type_t pk_alg) { return 0; }
static int x509_profile_check_key(const mbedtls_x509_crt_profile *profile, mbedtls_pk_type_t pk_alg, const mbedtls_pk_context *pk) { return 0; }
static int x509_crt_check_parent(const mbedtls_x509_crt *child, const mbedtls_x509_crt *parent, int top, int bottom) { return 0; }
static int x509_crt_verify_top(mbedtls_x509_crt *crt, mbedtls_x509_crt *trust_ca, mbedtls_x509_crl *ca_crl, const mbedtls_x509_crt_profile *profile, int pathlen, int selfsigned, uint32_t *flags, int (*f_vrfy)(void *, mbedtls_x509_crt *, int, uint32_t *), void *p_vrfy) { return 0; }
static int x509_crt_verify_child(mbedtls_x509_crt *crt, mbedtls_x509_crt *parent, mbedtls_x509_crt *trust_ca, mbedtls_x509_crl *ca_crl, const mbedtls_x509_crt_profile *profile, int pathlen, int selfsigned, uint32_t *flags, int (*f_vrfy)(void *, mbedtls_x509_crt *, int, uint32_t *), void *p_vrfy) { return 0; }
static mbedtls_pk_type_t mbedtls_pk_get_type(const mbedtls_pk_context *pk) { return MBEDTLS_PK_NONE; }