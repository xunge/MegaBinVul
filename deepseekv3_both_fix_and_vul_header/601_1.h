#include <stdint.h>

#define WOLFSSL_ENTER(x)
#define WOLFSSL_MSG(x)
#define BUFFER_E (-1)
#define ASN_PARSE_E (-2)

#define ASN_CONSTRUCTED 0x20
#define ASN_CONTEXT_SPECIFIC 0x80
#define ASN_BOOLEAN 0x01

#define OCSP_NONCE_OID 0
#define oidOcspType 0

typedef uint32_t word32;
typedef unsigned char byte;

typedef struct {
    byte* nonce;
    word32 nonceSz;
} OcspResponse;

int GetLength(byte* source, word32* idx, int* length, word32 sz);
int GetSequence(byte* source, word32* idx, int* length, word32 sz);
int GetObjectId(byte* source, word32* idx, word32* oid, int oidType, word32 sz);
int GetBoolean(byte* source, word32* idx, word32 sz);
int GetOctetString(byte* source, word32* idx, int* length, word32 sz);