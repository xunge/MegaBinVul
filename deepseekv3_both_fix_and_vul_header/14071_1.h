#include <stdint.h>
#include <stddef.h>

#define MBEDTLS_X509_MAX_INTERMEDIATE_CA 8
#define MBEDTLS_MD_MAX_SIZE 64

typedef struct mbedtls_x509_crt mbedtls_x509_crt;
typedef struct mbedtls_x509_crl mbedtls_x509_crl;
typedef struct mbedtls_x509_crt_profile mbedtls_x509_crt_profile;
typedef struct mbedtls_md_info_t mbedtls_md_info_t;
typedef struct mbedtls_pk_context {
    int dummy;
} mbedtls_pk_context;

struct mbedtls_x509_name {
    char *p;
    size_t len;
};

struct mbedtls_x509_time {
    int year, mon, day, hour, min, sec;
};

struct mbedtls_x509_buf {
    unsigned char *p;
    size_t len;
};

struct mbedtls_x509_crt {
    mbedtls_x509_crt *next;
    int max_pathlen;
    struct mbedtls_x509_buf tbs;
    struct mbedtls_x509_buf sig;
    mbedtls_pk_context pk;
    int sig_md;
    int sig_pk;
    void *sig_opts;
    struct mbedtls_x509_name issuer;
    struct mbedtls_x509_name subject;
    struct mbedtls_x509_time valid_from;
    struct mbedtls_x509_time valid_to;
};

enum {
    MBEDTLS_ERR_X509_FATAL_ERROR = -0x3000,
    MBEDTLS_ERR_X509_CERT_VERIFY_FAILED = -0x2700,
    MBEDTLS_X509_BADCERT_EXPIRED = 0x01,
    MBEDTLS_X509_BADCERT_FUTURE = 0x02,
    MBEDTLS_X509_BADCERT_BAD_MD = 0x04,
    MBEDTLS_X509_BADCERT_BAD_PK = 0x08,
    MBEDTLS_X509_BADCERT_BAD_KEY = 0x10,
    MBEDTLS_X509_BADCERT_NOT_TRUSTED = 0x20
};

const mbedtls_md_info_t *mbedtls_md_info_from_type(int md_type);
int mbedtls_md(const mbedtls_md_info_t *md_info, const unsigned char *input, size_t ilen, unsigned char *output);
unsigned char mbedtls_md_get_size(const mbedtls_md_info_t *md_info);
int mbedtls_pk_verify_ext(int type, void *options, mbedtls_pk_context *ctx, int md_alg, const unsigned char *hash, size_t hash_len, const unsigned char *sig, size_t sig_len);
int mbedtls_x509_time_is_past(const struct mbedtls_x509_time *time);
int mbedtls_x509_time_is_future(const struct mbedtls_x509_time *time);
int x509_name_cmp(const struct mbedtls_x509_name *a, const struct mbedtls_x509_name *b);
int x509_profile_check_md_alg(const mbedtls_x509_crt_profile *profile, int md_alg);
int x509_profile_check_pk_alg(const mbedtls_x509_crt_profile *profile, int pk_alg);
int x509_profile_check_key(const mbedtls_x509_crt_profile *profile, int pk_alg, const mbedtls_pk_context *pk);
int x509_crt_check_parent(const mbedtls_x509_crt *child, const mbedtls_x509_crt *parent, int top, int path_cnt);
int x509_crt_verify_top(mbedtls_x509_crt *child, mbedtls_x509_crt *parent, mbedtls_x509_crl *ca_crl, const mbedtls_x509_crt_profile *profile, int path_cnt, int self_cnt, uint32_t *flags, int (*f_vrfy)(void *, mbedtls_x509_crt *, int, uint32_t *), void *p_vrfy);
uint32_t x509_crt_verifycrl(mbedtls_x509_crt *child, mbedtls_x509_crt *parent, mbedtls_x509_crl *ca_crl, const mbedtls_x509_crt_profile *profile);