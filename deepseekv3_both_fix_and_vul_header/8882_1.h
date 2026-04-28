#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ZRTP_PACKET_HEADER_LENGTH 12
#define ZRTP_MESSAGE_HEADER_LENGTH 8
#define ZRTP_HELLOMESSAGE_FIXED_LENGTH 84
#define ZRTP_HELLOACKMESSAGE_FIXED_LENGTH 8
#define ZRTP_COMMITMESSAGE_FIXED_LENGTH 72
#define ZRTP_DHPARTMESSAGE_FIXED_LENGTH 72
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define BZRTP_PARSER_ERROR_INVALIDMESSAGE -1
#define BZRTP_PARSER_ERROR_UNEXPECTEDMESSAGE -2
#define BZRTP_PARSER_ERROR_UNMATCHINGHASHCHAIN -3
#define BZRTP_PARSER_ERROR_UNMATCHINGMAC -4
#define BZRTP_PARSER_ERROR_INVALIDCONTEXT -5
#define BZRTP_PARSER_ERROR_UNMATCHINGCONFIRMMAC -6
#define BZRTP_PARSER_ERROR_UNMATCHINGHVI -7

#define MSGTYPE_HELLO 1
#define MSGTYPE_HELLOACK 2
#define MSGTYPE_COMMIT 3
#define MSGTYPE_DHPART1 4
#define MSGTYPE_DHPART2 5
#define MSGTYPE_CONFIRM1 6
#define MSGTYPE_CONFIRM2 7
#define MSGTYPE_CONF2ACK 8
#define MSGTYPE_PING 9

#define HELLO_MESSAGE_STORE_ID 0
#define COMMIT_MESSAGE_STORE_ID 1
#define DHPART_MESSAGE_STORE_ID 2

#define ZRTP_HASH_TYPE 1
#define ZRTP_CIPHERBLOCK_TYPE 2
#define ZRTP_AUTHTAG_TYPE 3
#define ZRTP_KEYAGREEMENT_TYPE 4
#define ZRTP_SAS_TYPE 5

#define ZRTP_KEYAGREEMENT_DH2k 1
#define ZRTP_KEYAGREEMENT_EC25 2
#define ZRTP_KEYAGREEMENT_DH3k 3
#define ZRTP_KEYAGREEMENT_EC38 4
#define ZRTP_KEYAGREEMENT_EC52 5
#define ZRTP_KEYAGREEMENT_Prsh 6
#define ZRTP_KEYAGREEMENT_Mult 7

#define RESPONDER 0
#define INITIATOR 1

typedef struct bzrtpContext_t bzrtpContext_t;
typedef struct bzrtpChannelContext_t bzrtpChannelContext_t;
typedef struct bzrtpPacket_t bzrtpPacket_t;
typedef struct bzrtpHelloMessage_t bzrtpHelloMessage_t;
typedef struct bzrtpCommitMessage_t bzrtpCommitMessage_t;
typedef struct bzrtpDHPartMessage_t bzrtpDHPartMessage_t;
typedef struct bzrtpConfirmMessage_t bzrtpConfirmMessage_t;
typedef struct bzrtpPingMessage_t bzrtpPingMessage_t;

struct bzrtpHelloMessage_t {
    uint8_t version[4];
    uint8_t clientIdentifier[16];
    uint8_t H3[32];
    uint8_t ZID[12];
    uint8_t S;
    uint8_t M;
    uint8_t P;
    uint8_t hc;
    uint8_t cc;
    uint8_t ac;
    uint8_t kc;
    uint8_t sc;
    uint8_t supportedHash[7];
    uint8_t supportedCipher[7];
    uint8_t supportedAuthTag[7];
    uint8_t supportedKeyAgreement[7];
    uint8_t supportedSas[7];
    uint8_t MAC[8];
};

struct bzrtpCommitMessage_t {
    uint8_t H2[32];
    uint8_t ZID[12];
    uint8_t hashAlgo;
    uint8_t cipherAlgo;
    uint8_t authTagAlgo;
    uint8_t keyAgreementAlgo;
    uint8_t sasAlgo;
    uint8_t nonce[16];
    uint8_t keyID[8];
    uint8_t hvi[32];
    uint8_t MAC[8];
};

struct bzrtpDHPartMessage_t {
    uint8_t H1[32];
    uint8_t rs1ID[8];
    uint8_t rs2ID[8];
    uint8_t auxsecretID[8];
    uint8_t pbxsecretID[8];
    uint8_t *pv;
    uint8_t MAC[8];
};

struct bzrtpConfirmMessage_t {
    uint8_t H0[32];
    uint8_t confirm_mac[8];
    uint8_t CFBIV[16];
    uint16_t sig_len;
    uint8_t E;
    uint8_t V;
    uint8_t A;
    uint8_t D;
    uint32_t cacheExpirationInterval;
    uint8_t signatureBlockType[4];
    uint8_t *signatureBlock;
};

struct bzrtpPingMessage_t {
    uint8_t version[4];
    uint8_t endpointHash[8];
};

struct bzrtpPacket_t {
    uint8_t messageType;
    uint16_t messageLength;
    void *messageData;
    uint8_t *packetString;
};

struct bzrtpChannelContext_t {
    uint8_t role;
    uint8_t *zrtpkeyi;
    uint8_t *mackeyi;
    uint8_t *zrtpkeyr;
    uint8_t *mackeyr;
    uint8_t keyAgreementAlgo;
    uint16_t hashLength;
    void (*hmacFunction)(const uint8_t *, uint16_t, const uint8_t *, uint16_t, uint8_t, uint8_t *);
    void (*cipherDecryptionFunction)(const uint8_t *, const uint8_t *, const uint8_t *, uint16_t, uint8_t *);
    void (*hashFunction)(const uint8_t *, uint16_t, uint8_t, uint8_t *);
    bzrtpPacket_t *peerPackets[3];
    bzrtpPacket_t *selfPackets[3];
};

int cryptoAlgoTypeStringToInt(const uint8_t *input, int type);
void addMandatoryCryptoTypesIfNeeded(int type, uint8_t *supported, uint8_t *count);
uint16_t computeKeyAgreementPrivateValueLength(uint8_t algo);
void bctoolbox_sha256(const uint8_t *input, uint16_t inputLength, uint8_t outputLength, uint8_t *output);
void bctoolbox_hmacSha256(const uint8_t *key, uint16_t keyLength, const uint8_t *input, uint16_t inputLength, uint8_t outputLength, uint8_t *output);