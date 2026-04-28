#include <string.h>

typedef unsigned char byte;
typedef unsigned int word32;

#define NO_SNIFF 0
#define BUFFER_E -1
#define BUFFER_ERROR -2
#define VERIFY_FINISHED_ERROR -3
#define NO_PEER_CERT -4
#define WC_MAX_DIGEST_SIZE 64
#define WC_FUNC_FINISHED_DO 0
#define DECRYPT_SIDE_ONLY 0
#define no_key 0
#define no_early_data 0
#define alert_fatal 0
#define decrypt_error 0

enum {
    WOLFSSL_CLIENT_END,
    WOLFSSL_SERVER_END
};

enum {
    SERVER_FINISHED_COMPLETE,
    CLIENT_FINISHED_COMPLETE,
    HANDSHAKE_DONE
};

struct Keys {
    byte* client_write_MAC_secret;
    byte* server_write_MAC_secret;
    word32 padSz;
};

struct Options {
    int side;
    int resuming;
    int mutualAuth;
    int failNoCert;
    int havePeerCert;
    int havePeerVerify;
    int handShakeDone;
    int serverState;
    int clientState;
    int handShakeState;
};

typedef struct WOLFSSL {
    struct Options options;
    struct Keys keys;
    byte* clientSecret;
    byte* serverSecret;
    byte serverFinished[WC_MAX_DIGEST_SIZE];
    byte clientFinished[WC_MAX_DIGEST_SIZE];
    word32 serverFinished_len;
    word32 clientFinished_len;
    int hsInfoOn;
    int toInfoOn;
    int earlyData;
    void* timeoutInfo;
} WOLFSSL;

#define WOLFSSL_START(x)
#define WOLFSSL_ENTER(x)
#define WOLFSSL_LEAVE(x, y)
#define WOLFSSL_END(x)
#define WOLFSSL_MSG(x)
#define XMEMCPY(d, s, l) memcpy(d, s, l)
#define XMEMCMP(s1, s2, n) memcmp(s1, s2, n)

int DeriveFinishedSecret(WOLFSSL*, byte*, byte**);
int BuildTls13HandshakeHmac(WOLFSSL*, byte*, byte*, word32*);
void DoCertFatalAlert(WOLFSSL*, int);
void SendAlert(WOLFSSL*, int, int);
void AddPacketName(WOLFSSL*, const char*);
void AddLateName(const char*, void*);
int DeriveTls13Keys(WOLFSSL*, int, int, int);
int SetKeysSide(WOLFSSL*, int);