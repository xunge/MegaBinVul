#include <stddef.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned short word16;
typedef unsigned int word32;

#define WOLFSSL_ENTER(s)
#define WOLFSSL_LEAVE(s, r)
#define WOLFSSL_MSG(s)
#define ERROR_OUT(e, l) ret = e; goto l
#define FALL_THROUGH
#define BAD_FUNC_ARG -1
#define BAD_STATE_E -2
#define BUFFER_E -3
#define MEMORY_E -4
#define WC_NOT_PENDING_E -5
#define WC_PENDING_E -6
#define RECORD_HEADER_SZ 5
#define MAX_IV_SZ 16
#define AESGCM_EXP_IV_SZ 4
#define DTLS_RECORD_EXTRA 8
#define TRUNCATED_HMAC_SZ 10
#define WC_MAX_DIGEST_SIZE 64
#define BUILD_MSG_BEGIN 0
#define BUILD_MSG_SIZE 1
#define BUILD_MSG_HASH 2
#define BUILD_MSG_VERIFY_MAC 3
#define BUILD_MSG_ENCRYPT 4
#define BUILD_MSG_ENCRYPTED_VERIFY_MAC 5
#define PREV_ORDER 0
#define CUR_ORDER 1
#define ENCRYPT_SIDE_ONLY 0
#define SCR_CACHE_NULL 0
#define SCR_CACHE_NEEDED 1
#define DYNAMIC_TYPE_SALT 0
#define DYNAMIC_TYPE_DIGEST 0
#define block 0
#define aead 1
#define handshake 22
#define KEYS 0
#define SCR 1

#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct BuildMsgArgs {
    word32 sz;
    word16 idx;
    word16 headerSz;
    word16 digestSz;
    word16 ivSz;
    word16 pad;
    word16 size;
    byte* iv;
} BuildMsgArgs;

typedef struct WOLFSSL WOLFSSL;
typedef struct WOLFSSL_CTX WOLFSSL_CTX;

struct WOLFSSL_CTX {
    int (*MacEncryptCb)(WOLFSSL*, byte*, byte*, int, int, int, byte*, byte*, int, void*);
    int (*EncryptMacCb)(WOLFSSL*, byte*, int, int, byte*, byte*, int, void*);
};

struct WOLFSSL {
    int (*hmac)(WOLFSSL*, byte*, byte*, int, int, int, int, int);
    void* heap;
    struct {
        int dtls;
        int tls1_1;
        int tls1_3;
        int startedETMWrite;
        int buildMsgState;
    } options;
    struct {
        int cipher_type;
        int bulk_cipher_algorithm;
        int hash_size;
        int aead_mac_size;
        int block_size;
    } specs;
    struct {
        byte* aead_exp_IV;
        word16 dtls_epoch;
        word16 dtls_sequence_number_hi;
        word32 dtls_sequence_number_lo;
        word16 dtls_prev_sequence_number_hi;
        word32 dtls_prev_sequence_number_lo;
    } keys;
    struct {
        int src;
    } encrypt;
    struct {
        int cache_status;
        struct {
            word16 dtls_epoch;
        } tmp_keys;
    } *secure_renegotiation;
    WOLFSSL_CTX* ctx;
    void* rng;
    int truncated_hmac;
    BuildMsgArgs async;
    void* MacEncryptCtx;
};

int BuildTls13Message(WOLFSSL*, byte*, int, const byte*, int, int, int, int, int);
int HashOutput(WOLFSSL*, byte*, int, int);
int SetKeysSide(WOLFSSL*, int);
int DtlsSCRKeysSet(WOLFSSL*);
int DtlsUseSCRKeys(WOLFSSL*);
void DtlsSEQIncrement(WOLFSSL*, int);
int wc_RNG_GenerateBlock(void*, byte*, int);
void AddRecordHeader(byte*, word16, byte, WOLFSSL*, int);
int Encrypt(WOLFSSL*, byte*, byte*, word16, int);
void FreeBuildMsgArgs(WOLFSSL*, BuildMsgArgs*);
void* XMALLOC(size_t, void*, int);
void XFREE(void*, void*, int);
void XMEMSET(void*, int, size_t);
void XMEMCPY(void*, const void*, size_t);