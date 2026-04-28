#include <stddef.h>
#include <string.h>

#define NO_CERTS
#define WOLFSSL_NO_CLIENT_AUTH
#define WC_MAX_DIGEST_SIZE 64
#define NO_SNIFF 0
#define BUFFER_E -1
#define BUFFER_ERROR -2
#define VERIFY_FINISHED_ERROR -3
#define NO_PEER_CERT -4
#define alert_fatal 2
#define decrypt_error 51
#define WOLFSSL_SERVER_END 1
#define WOLFSSL_CLIENT_END 0
#define DECRYPT_SIDE_ONLY 0
#define no_key 0
#define no_early_data 0
#define WC_FUNC_FINISHED_DO 0
#define NO_WOLFSSL_CLIENT
#define NO_WOLFSSL_SERVER
#define WOLFSSL_CALLBACKS
#define WOLFSSL_EARLY_DATA
#define OPENSSL_ALL
#define WOLFSSL_HAPROXY
#define WOLFSSL_WPAS

typedef unsigned char byte;
typedef unsigned int word32;

typedef struct {
    word32 padSz;
    byte* client_write_MAC_secret;
    byte* server_write_MAC_secret;
} Keys;

typedef struct {
    int side;
    int mutualAuth;
    int failNoCert;
    int havePeerVerify;
    int resuming;
    int handShakeDone;
    int serverState;
    int clientState;
    int handShakeState;
} Options;

typedef struct {
    byte* clientSecret;
    byte* serverSecret;
    byte serverFinished[WC_MAX_DIGEST_SIZE];
    byte clientFinished[WC_MAX_DIGEST_SIZE];
    word32 serverFinished_len;
    word32 clientFinished_len;
    int earlyData;
    int hsInfoOn;
    int toInfoOn;
    void* timeoutInfo;
    Keys keys;
    Options options;
} WOLFSSL;

#define WOLFSSL_START(x)
#define WOLFSSL_ENTER(x)
#define WOLFSSL_LEAVE(x, y)
#define WOLFSSL_END(x)
#define WOLFSSL_MSG(x)
#define XMEMCPY(d, s, l) memcpy(d, s, l)
#define XMEMCMP(s1, s2, n) memcmp(s1, s2, n)

int DeriveFinishedSecret(WOLFSSL* ssl, byte* secret, byte* out);
int BuildTls13HandshakeHmac(WOLFSSL* ssl, byte* secret, byte* mac, word32* sz);
int DoCertFatalAlert(WOLFSSL* ssl, int ret);
int SendAlert(WOLFSSL* ssl, int level, int description);
int DeriveTls13Keys(WOLFSSL* ssl, int key, int side, int early);
int SetKeysSide(WOLFSSL* ssl, int side);
void AddPacketName(WOLFSSL* ssl, const char* name);
void AddLateName(const char* name, void* info);