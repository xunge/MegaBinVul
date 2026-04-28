#include <stdint.h>
#include <string.h>

typedef struct mbedtls_asn1_buf {
    int tag;
    size_t len;
    unsigned char *p;
} mbedtls_asn1_buf;

typedef struct mbedtls_x509_name {
    mbedtls_asn1_buf oid;
    mbedtls_asn1_buf val;
    struct mbedtls_x509_name *next;
} mbedtls_x509_name;

typedef struct mbedtls_x509_sequence {
    mbedtls_asn1_buf buf;
    struct mbedtls_x509_sequence *next;
} mbedtls_x509_sequence;

typedef struct mbedtls_x509_crt {
    mbedtls_x509_name subject;
    mbedtls_x509_sequence subject_alt_names;
    int ext_types;
} mbedtls_x509_crt;

#define MBEDTLS_X509_EXT_SUBJECT_ALT_NAME (1 << 0)
#define MBEDTLS_X509_BADCERT_CN_MISMATCH (1 << 0)
#define MBEDTLS_OID_AT_CN NULL

#define MBEDTLS_OID_CMP(oid, buf) 0

static int x509_crt_check_cn(const mbedtls_asn1_buf *buf, const char *cn, size_t cn_len) {
    return 0;
}