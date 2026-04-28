#include <stddef.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int word32;
typedef unsigned short word16;

typedef struct WOLFSSL WOLFSSL;
typedef struct buffer buffer;
typedef struct Dcv13Args Dcv13Args;
typedef struct Key Key;
typedef struct Buffers Buffers;
typedef struct Options Options;
typedef struct Async Async;
typedef struct Keys Keys;
typedef struct MsgsReceived MsgsReceived;
typedef struct TimeoutInfo TimeoutInfo;

struct buffer {
    byte* buffer;
    word32 length;
};

struct Dcv13Args {
    int hashAlgo;
    int sigAlgo;
    word32 idx;
    word32 begin;
    word16 sz;
    byte* sigData;
    word16 sigDataSz;
    byte* output;
    word32 sendSz;
};

struct Key {
    void* key;
};

struct Buffers {
    buffer sig;
    Key peerRsaKey;
    Key peerEccDsaKey;
    Key peerEd25519Key;
    Key peerEd448Key;
};

struct Options {
    int asyncState;
    int havePeerVerify;
    int side;
    int serverState;
    int hsInfoOn;
    int toInfoOn;
};

struct Async {
    void* args;
    void (*freeArgs)(WOLFSSL*, Dcv13Args*);
};

struct Keys {
    word32 padSz;
};

struct MsgsReceived {
    int got_certificate_verify;
};

struct TimeoutInfo {
    int dummy;
};

struct WOLFSSL {
    Buffers buffers;
    Options options;
    Async async;
    Keys keys;
    MsgsReceived msgsReceived;
    TimeoutInfo timeoutInfo;
    void* heap;
    int peerEd25519KeyPresent;
    int peerEd448KeyPresent;
    int peerEccDsaKeyPresent;
    int peerFalconKeyPresent;
    int peerRsaKeyPresent;
    Key* peerRsaKey;
    Key* peerEccDsaKey;
    Key* peerEd25519Key;
    Key* peerEd448Key;
    Key* peerFalconKey;
};

enum {
    sha_mac,
    anonymous_sa_algo,
    ed25519_sa_algo,
    ed448_sa_algo,
    ecc_dsa_sa_algo,
    falcon_level1_sa_algo,
    falcon_level5_sa_algo,
    rsa_sa_algo,
    rsa_pss_sa_algo
};

#define ENUM_LEN 2
#define OPAQUE16_LEN 2
#define ENCRYPT_LEN 65535
#define MAX_SIG_DATA_SZ 1024

#define WC_FUNC_CERTIFICATE_VERIFY_DO 0
#define WC_NOT_PENDING_E 0
#define TLS_ASYNC_BEGIN 0
#define TLS_ASYNC_BUILD 1
#define TLS_ASYNC_DO 2
#define TLS_ASYNC_VERIFY 3
#define TLS_ASYNC_FINALIZE 4
#define TLS_ASYNC_END 5
#define WOLFSSL_CLIENT_END 0
#define SERVER_CERT_VERIFY_COMPLETE 0
#define WC_PENDING_E 0
#define alert_fatal 0
#define decrypt_error 0

#define BUFFER_ERROR 0
#define MEMORY_E 0
#define SIG_VERIFY_E 0
#define INVALID_PARAMETER 0
#define INPUT_CASE_ERROR 0

#define DYNAMIC_TYPE_SIGNATURE 0
#define DYNAMIC_TYPE_ECC 0
#define DYNAMIC_TYPE_ED25519 0
#define DYNAMIC_TYPE_ED448 0
#define DYNAMIC_TYPE_FALCON 0
#define DYNAMIC_TYPE_RSA 0

#define FALL_THROUGH

static void WOLFSSL_START(int);
static void WOLFSSL_ENTER(const char*);
static void WOLFSSL_LEAVE(const char*, int);
static void WOLFSSL_END(int);
static void WOLFSSL_MSG(const char*);
static void ERROR_OUT(int, int);
static int DecodeTls13SigAlg(byte*, int*, int*);
static void ato16(byte*, word16*);
static void* XMALLOC(size_t, void*, int);
static void XMEMSET(void*, int, size_t);
static void XMEMCPY(void*, const void*, size_t);
static int CreateSigData(WOLFSSL*, byte*, word16*, int);
static int CreateECCEncodedSig(byte*, word16, int);
static int RsaVerify(WOLFSSL*, byte*, word32, byte**, int, int, void*, void*);
static int EccVerify(WOLFSSL*, byte*, word16, byte*, word16, void*, void*);
static int Ed25519Verify(WOLFSSL*, byte*, word16, byte*, word16, void*, void*);
static int Ed448Verify(WOLFSSL*, byte*, word16, byte*, word16, void*, void*);
static int wc_falcon_verify_msg(byte*, word16, byte*, word16, int*, void*);
static int CheckRSASignature(WOLFSSL*, int, int, byte*, word32);
static void FreeKey(WOLFSSL*, int, void**);
static void FreeDcv13Args(WOLFSSL*, Dcv13Args*);
static void FreeKeyExchange(WOLFSSL*);
static int SendAlert(WOLFSSL*, int, int);
static int wolfSSL_AsyncPop(WOLFSSL*, int*);
static void AddPacketName(WOLFSSL*, const char*);
static void AddLateName(const char*, void*);

#define ERROR_OUT(code, label) do { ret = code; goto label; } while(0)