#include <string.h>

#define WOLFSSL_ENTER(x)
#define WOLFSSL_MSG(x)
#define OCSP_DIGEST_SIZE 32
#ifndef WOLFSSL_FORCE_OCSP_NONCE_CHECK
#endif

typedef struct OcspEntry {
    struct OcspStatus* status;
    unsigned char issuerHash[OCSP_DIGEST_SIZE];
    unsigned char issuerKeyHash[OCSP_DIGEST_SIZE];
    struct OcspEntry* next;
} OcspEntry;

typedef struct OcspStatus {
    unsigned char* serial;
    int serialSz;
} OcspStatus;

typedef struct OcspRequest {
    unsigned char* nonce;
    int nonceSz;
    unsigned char* serial;
    int serialSz;
    unsigned char issuerHash[OCSP_DIGEST_SIZE];
    unsigned char issuerKeyHash[OCSP_DIGEST_SIZE];
} OcspRequest;

typedef struct OcspResponse {
    OcspEntry* single;
    unsigned char* nonce;
    int nonceSz;
} OcspResponse;

#define XMEMCMP memcpy