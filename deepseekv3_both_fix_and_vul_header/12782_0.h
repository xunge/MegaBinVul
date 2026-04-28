#include <stdlib.h>
#include <string.h>

#define NUMOF_CIPHERS 45
#define SCH_USE_STRONG_CRYPTO 0x00400000
#define CURLE_OK 0
#define CURLE_SSL_CIPHER 1

typedef unsigned int ALG_ID;
typedef int CURLcode;

typedef struct {
    ALG_ID *palgSupportedAlgs;
    unsigned int cSupportedAlgs;
    unsigned long dwFlags;
} SCHANNEL_CRED;

extern ALG_ID get_alg_id_by_name(const char *name);