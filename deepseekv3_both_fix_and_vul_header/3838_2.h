#include <stddef.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int word32;
typedef unsigned short word16;

#define RECORD_HEADER_SZ 5
#define DTLS_RECORD_HEADER_SZ 13
#define ENUM_LEN 1
#define VERSION_SZ 2
#define OPAQUE16_LEN 2
#define OPAQUE32_LEN 4
#define LENGTH_SZ 2
#define MAX_RECORD_SIZE 16384
#define MAX_COMP_EXTRA 1024
#define MAX_MSG_EXTRA 1024

#define WOLFSSL_DTLS
#define WOLFSSL_TLS13
#define HAVE_FUZZER
#define WOLFSSL_MULTICAST
#define WOLFSSL_MYSQL_COMPATIBLE

#define SEQUENCE_ERROR 1
#define VERSION_ERROR 2
#define LENGTH_ERROR 3
#define UNKNOWN_RECORD_TYPE 4

#define alert_fatal 2
#define wc_protocol_version 70
#define protocol_version 70
#define record_overflow 22

#define FUZZ_HEAD 1

#define WOLFSSL_SERVER_END 0
#define WOLFSSL_CLIENT_END 1
#define FIRST_REPLY_DONE 1
#define ACCEPT_FIRST_REPLY_DONE 1

typedef enum {
    handshake,
    change_cipher_spec,
    application_data,
    alert,
    no_type
} ContentType;

typedef struct {
    ContentType type;
    byte pvMajor;
    byte pvMinor;
    byte length[2];
} RecordLayerHeader;

typedef struct {
    byte major;
    byte minor;
} ProtocolVersion;

typedef struct {
    word16 curEpoch;
    word16 curPeerId;
    word16 curSeq_hi;
    word32 curSeq_lo;
    byte decryptedCur;
} Keys;

typedef struct {
    int dtls;
    int haveMcast;
    int side;
    int acceptState;
    int downgrade;
    int connectState;
} Options;

struct WOLFSSL;

typedef int (*fuzzer_cb)(struct WOLFSSL* ssl, const byte* input, word32 sz, int type, void* ctx);

typedef struct WOLFSSL {
    Options options;
    ProtocolVersion version;
    Keys keys;
    fuzzer_cb fuzzerCb;
    void* fuzzerCtx;
    word16 max_fragment;
} WOLFSSL;

#define XMEMCPY(dest, src, n) memcpy(dest, src, n)
#define WOLFSSL_MSG(msg)
#define WOLFSSL_LEAVE(func, ret)
#define SendAlert(ssl, level, desc) 0
#define IsDtlsNotSctpMode(ssl) 0
#define DtlsCheckWindow(ssl) 1
#define IsAtLeastTLSv1_3(ver) 0
#define TLSv1_2_MINOR 3

static void ato16(const byte* in, word16* out) {
    *out = (in[0] << 8) | in[1];
}

static void ato32(const byte* in, word32* out) {
    *out = (in[0] << 24) | (in[1] << 16) | (in[2] << 8) | in[3];
}