#include <stddef.h>
#include <stdint.h>

typedef unsigned char byte;
typedef uint16_t word16;

#define OPAQUE16_LEN 2
#define BUFFER_ERROR -1
#define BAD_KEY_SHARE_DATA -2
#define SANITY_MSG_E -3
#define WC_PENDING_E -4
#define NO_DH
#define HAVE_PQC
#define WOLFSSL_ASYNC_CRYPT
#define WOLFSSL_NAMED_GROUP_IS_PQC(x) 0

enum {
    client_hello,
    server_hello,
    hello_retry_request
};

typedef struct WOLFSSL WOLFSSL;
typedef struct WOLFSSL_SESSION WOLFSSL_SESSION;
typedef struct KeyShareEntry KeyShareEntry;
typedef struct TLSX TLSX;

struct WOLFSSL {
    TLSX* extensions;
    word16 namedGroup;
    int error;
    WOLFSSL_SESSION* session;
};

struct WOLFSSL_SESSION {
    word16 namedGroup;
};

struct KeyShareEntry {
    byte* key;
    byte* privKey;
};

int TLSX_KeyShare_Parse_ClientHello(WOLFSSL*, const byte*, word16, TLSX**);
int TLSX_SupportedGroups_Find(WOLFSSL*, word16, TLSX*);
int TLSX_KeyShare_Find(WOLFSSL*, word16);
int TLSX_KeyShareEntry_Parse(WOLFSSL*, const byte*, word16, KeyShareEntry**, TLSX**);
int TLSX_KeyShare_Process(WOLFSSL*, KeyShareEntry*);
int TLSX_KeyShare_Empty(WOLFSSL*);
int TLSX_KeyShare_Use(WOLFSSL*, word16, int, byte*, byte*, TLSX**);
void WOLFSSL_ERROR_VERBOSE(int);
void ato16(const byte*, word16*);