#include <stddef.h>

typedef unsigned char byte;

typedef struct buffer {
    /* buffer structure definition */
} buffer;

typedef struct CertStatus {
    /* CertStatus structure definition */
} CertStatus;

typedef struct OcspEntry {
    /* OcspEntry structure definition */
} OcspEntry;

typedef struct OcspRequest {
    /* OcspRequest structure definition */
} OcspRequest;

typedef struct WOLFSSL_CERT_MANAGER {
    int ocspEnabled;
    void* ocsp;
    /* other members */
} WOLFSSL_CERT_MANAGER;

#define WOLFSSL_API
#define WOLFSSL_ENTER(x)
#define BAD_FUNC_ARG (-1)
#define WOLFSSL_SUCCESS 0

int CheckOcspResponse(void* ocsp, byte* response, int responseSz, buffer* responseBuffer,
                     CertStatus* status, OcspEntry* entry, OcspRequest* ocspRequest);