#include <wchar.h>

#define LTC_ARGCHK(cond) do { if (!(cond)) return CRYPT_INVALID_ARG; } while(0)

#define CRYPT_OK                0
#define CRYPT_INVALID_ARG       1
#define CRYPT_INVALID_PACKET    2
#define CRYPT_BUFFER_OVERFLOW   3

int der_decode_asn1_length(const unsigned char *in, unsigned long *inlen, unsigned long *outlen);