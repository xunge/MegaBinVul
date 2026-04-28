#include <stdlib.h>
#include <string.h>

#define NUMOF_CIPHERS 64
#define SCH_USE_STRONG_CRYPTO 0x00400000

typedef unsigned long ALG_ID;

typedef struct {
    ALG_ID *palgSupportedAlgs;
    unsigned long cSupportedAlgs;
    unsigned long dwFlags;
} SCHANNEL_CRED;

typedef enum {
    CURLE_OK,
    CURLE_SSL_CIPHER
} CURLcode;

static ALG_ID get_alg_id_by_name(char *name);