#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef int gboolean;
typedef size_t gsize;
typedef unsigned char guchar;
typedef uint32_t guint32;
typedef uint16_t guint16;

typedef struct {
    guint16 length;
    guint16 offset;
} NTLMString;

#define NTLM_CHALLENGE_DOMAIN_STRING_OFFSET 16
#define NTLM_CHALLENGE_NONCE_OFFSET 24
#define NTLM_CHALLENGE_NONCE_LENGTH 8
#define NTLM_CHALLENGE_FLAGS_OFFSET 20
#define NTLM_CHALLENGE_TARGET_INFORMATION_OFFSET 40

#define NTLM_FLAGS_NEGOTIATE_NTLMV2 (1 << 19)
#define NTLM_FLAGS_NEGOTIATE_TARGET_INFORMATION (1 << 9)

#define GUINT_FROM_LE(x) (x)
#define GUINT16_FROM_LE(x) (x)

#define FALSE 0
#define TRUE 1