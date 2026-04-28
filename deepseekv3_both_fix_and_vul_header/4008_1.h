#include <string.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned int word32;

#define WOLFSSL_ASYNC_CRYPT
#define WOLFSSL_DTLS13
#define WOLFSSL_CALLBACKS
#define WOLFSSL_DEBUG_TLS
#define WOLFSSL_TLS13_MIDDLEBOX_COMPAT
#define WOLFSSL_QUIC
#define HAVE_SECRET_CALLBACK
#define HAVE_SESSION_TICKET
#define HAVE_NULL_CIPHER
#define HAVE_ECH
#define OPENSSL_EXTRA
#define HAVE_WEBSERVER
#define WOLFSSL_WPAS_SMALL
#define NO_PSK

#define OPAQUE16_LEN 2
#define OPAQUE8_LEN 1
#define RAN_LEN 32
#define ENUM_LEN 1
#define ID_LEN 32
#define SECRET_LEN 48
#define MAX_PSK_KEY_LEN 64

#define TLSv1_2_MINOR 3
#define DTLSv1_2_MINOR 2
#define DTLS_BOGUS_MINOR 0xFF
#define DTLS_MAJOR 254

#define BAD_FUNC_ARG -1
#define MEMORY_E -2
#define BUFFER_ERROR -3
#define VERSION_ERROR -4
#define DUPLICATE_MSG_E -5
#define INVALID_PARAMETER -6
#define MATCH_SUITE_ERROR -7
#define SESSION_SECRET_CB_E -8
#define INPUT_CASE_ERROR -9
#define WC_NOT_PENDING_E -10
#define WC_PENDING_E -11
#define EXT_MISSING -12

#define alert_fatal 2
#define wolfssl_alert_protocol_version 70

#define WC_FUNC_SERVER_HELLO_DO 0
#define DYNAMIC_TYPE_ASYNC 0
#define DYNAMIC_TYPE_DTLS_MSG 0

#define TLS_ASYNC_BEGIN 0
#define TLS_ASYNC_BUILD 1
#define TLS_ASYNC_DO 2
#define TLS_ASYNC_FINALIZE 3

#define SERVER_HELLO_COMPLETE 0
#define SERVER_HELLO_RETRY_REQUEST_COMPLETE 1

#define SSL_OP_NO_TLSv1_2 0

#define ECC_BYTE 0xC0
#define TLS_SHA256_SHA256 0x3C
#define TLS_SHA384_SHA384 0x3D
#define TLS13_BYTE 0x13

#define hello_retry_request 0
#define server_hello 1

#define FALL_THROUGH

typedef struct WOLFSSL WOLFSSL;
typedef struct WOLFSSL_ASYNC WOLFSSL_ASYNC;
typedef struct Dsh13Args Dsh13Args;
typedef struct TLSX TLSX;
typedef struct PreSharedKey PreSharedKey;

struct WOLFSSL_ASYNC {
    void* args;
    void (*freeArgs)(void*);
};

struct PreSharedKey {
    int chosen;
    PreSharedKey* next;
};

struct TLSX {
    void* data;
    TLSX* next;
};

struct Dsh13Args {
    word32 idx;
    word32 begin;
    word32 totalExtSz;
    word32 serverRandomOffset;
    byte extMsgType;
    byte sessIdSz;
    const byte* sessId;
    struct {
        byte major;
        byte minor;
    } pv;
};

struct WOLFSSL {
    struct {
        byte* serverRandom;
        byte sessionID[ID_LEN];
        word32 sessionIDSz;
        byte psk_key[MAX_PSK_KEY_LEN];
        word32 psk_keySz;
        byte* clientRandom;
    }* arrays;
    struct {
        int dtls;
        int tls1_3;
        int resuming;
        int pskNegotiated;
        int haveSessionId;
        int haveEMS;
        int useDtlsCID;
        int useEch;
        int tls13MiddleBoxCompat;
        int minDowngrade;
        int mask;
        int downgrade;
        word32 asyncState;
        byte cipherSuite;
        byte cipherSuite0;
        int serverState;
    } options;
    WOLFSSL_ASYNC* async;
    struct {
        byte* dtls13ClientHello;
        word32 dtls13ClientHelloSz;
    };
    struct {
        int got_server_hello;
        int got_hello_retry_request;
    } msgsReceived;
    struct {
        byte masterSecret[SECRET_LEN];
        byte sessionID[ID_LEN];
        word32 sessionIDSz;
        word32 namedGroup;
#ifdef HAVE_SESSION_TICKET
        word32 ticketLen;
#endif
    }* session;
    void* heap;
    void* sessionSecretCtx;
    int (*sessionSecretCb)(WOLFSSL*, byte*, int*, void*);
    int (*echCheckAcceptance)(WOLFSSL*, const byte*, word32, word32);
    int (*setupPskKey)(WOLFSSL*, PreSharedKey*, int);
    int (*restartHandshakeHash)(WOLFSSL*);
    int (*sendAlert)(WOLFSSL*, int, int);
    int (*completeServerHello)(WOLFSSL*);
    int (*dtls13DoDowngrade)(WOLFSSL*);
    int (*dtlsCIDOnExtensionsParsed)(WOLFSSL*);
    int (*tlsxParseVersion)(WOLFSSL*, const byte*, word32, byte, int*);
    int (*tlsxParse)(WOLFSSL*, const byte*, word32, byte, void*);
    TLSX* (*tlsxFind)(TLSX*, int);
    void (*freeAsyncCtx)(WOLFSSL*, int);
    struct {
        byte major;
        byte minor;
    } version, chVersion;
    struct {
        int encryptionOn;
    } keys;
#ifdef WOLFSSL_CALLBACKS
    int hsInfoOn;
    int toInfoOn;
    struct {
        void (*addPacketName)(WOLFSSL*, const char*);
        void (*addLateName)(const char*, void*);
    };
#endif
};

extern const byte helloRetryRequestRandom[RAN_LEN];

#define WOLFSSL_START(x)
#define WOLFSSL_ENTER(x)
#define WOLFSSL_LEAVE(x, y)
#define WOLFSSL_END(x)
#define WOLFSSL_MSG(x)
#define WOLFSSL_ERROR_VERBOSE(x)
#define WOLFSSL_ASSERT_SIZEOF_GE(x, y)

#define XMEMCPY(d, s, n) memcpy(d, s, n)
#define XMEMSET(d, v, n) memset(d, v, n)
#define XMEMCMP(s1, s2, n) memcmp(s1, s2, n)
#define XMALLOC(s, h, t) malloc(s)
#define XFREE(p, h, t) free(p)
#define ato16(p, w) 
#define IsAtLeastTLSv1_3(v) ((v).minor >= TLSv1_2_MINOR)
#define FindSuiteSSL(ssl, suite) 1
#define SetupPskKey(ssl, psk, b) 0
#define RestartHandshakeHash(ssl) 0
#define SendAlert(ssl, level, desc) 0
#define CompleteServerHello(ssl) 0
#define Dtls13DoDowngrade(ssl) 0
#define DtlsCIDOnExtensionsParsed(ssl) 0
#define TLSX_ParseVersion(ssl, p, l, t, f) 0
#define TLSX_Parse(ssl, p, l, t, u) 0
#define TLSX_Find(e, t) NULL
#define FreeAsyncCtx(ssl, b)
#define EchCheckAcceptance(ssl, p, o, l) 0
#define GetCipherNameInternal(a, b) ""
#define AddPacketName(ssl, name)
#define AddLateName(name, info)
#define WOLFSSL_IS_QUIC(ssl) 0
#define wolfSSL_AsyncPop(ssl, state) 0
#define DoServerHello(ssl, input, idx, sz) 0
#define SetCipherSpecs(ssl) 0