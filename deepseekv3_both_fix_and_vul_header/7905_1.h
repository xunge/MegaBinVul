#include <string.h>
#include <stdint.h>

typedef int INT;
typedef uint8_t guint8;
typedef uint32_t guint;
typedef uint32_t guint32;
typedef int32_t gint;
typedef uint8_t BOOLEAN;
#define TRUE 1
#define FALSE 0

#define AIRPDCAP_WPA_NONCE_LEN 32
#define AIRPDCAP_MAC_LEN 6
#define SHA256_DIGEST_LEN 32
#define AIRPDCAP_RET_SUCCESS 0
#define AIRPDCAP_RET_UNSUCCESS -1
#define AIRPDCAP_DEBUG_LEVEL_3 3
#define AIRPDCAP_WPA_KEY_VER_AES_CCMP 2

typedef struct {
    void *ctx;
} sha256_hmac_context;

typedef struct {
    void *ctx;
} aes_cmac_ctx;

typedef struct {
    guint8 nonce[AIRPDCAP_WPA_NONCE_LEN];
    guint8 ptk[48];
    guint8 key_ver;
} AIRPDCAP_WPA_PTK;

typedef struct {
    AIRPDCAP_WPA_PTK wpa;
    BOOLEAN validKey;
} AIRPDCAP_SEC_ASSOCIATION;

typedef AIRPDCAP_SEC_ASSOCIATION *PAIRPDCAP_SEC_ASSOCIATION;

#define AIRPDCAP_GET_TK(ptk) ((ptk) + 32)
#define AIRPDCAP_DEBUG_PRINT_LINE(func, msg, level) ((void)0)

void sha256_starts(void *ctx);
void sha256_update(void *ctx, const guint8 *input, guint32 length);
void sha256_finish(void *ctx, guint8 digest[SHA256_DIGEST_LEN]);
void sha256_hmac_starts(sha256_hmac_context *ctx, const guint8 *key, guint32 keylen);
void sha256_hmac_update(sha256_hmac_context *ctx, const guint8 *input, guint32 length);
void sha256_hmac_finish(sha256_hmac_context *ctx, guint8 digest[SHA256_DIGEST_LEN]);
void aes_cmac_encrypt_starts(aes_cmac_ctx *ctx, const guint8 *key, guint32 keylen);
void aes_cmac_encrypt_update(aes_cmac_ctx *ctx, const guint8 *input, guint32 length);
void aes_cmac_encrypt_finish(aes_cmac_ctx *ctx, guint8 digest[16]);