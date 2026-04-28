#include <stddef.h>

#define WOLFSSL_ERROR(ret) (void)0

enum {
    bad_certificate,
    certificate_expired,
    unknown_ca,
    certificate_revoked,
    certificate_required,
    handshake_failure,
    alert_fatal
};

enum {
    ASN_AFTER_DATE_E = 1,
    ASN_BEFORE_DATE_E = 2,
    ASN_NO_SIGNER_E = 3,
    CRL_CERT_REVOKED = 4,
    NO_PEER_CERT = 5
};

typedef struct {
    struct {
        int tls1_3;
        int isClosed;
    } options;
} WOLFSSL;

void SendAlert(WOLFSSL* ssl, int type, int reason);