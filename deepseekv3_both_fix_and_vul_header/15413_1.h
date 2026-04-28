#include <string.h>

#define MAX_INPUT_PACKET_SIZE 2048
#define LC_ASSERT(expr) ((void)0)

static int AppVersionQuad[4];
static int ServerMajorVersion;
static int cipherInitialized;
static unsigned char currentAesIv[16];

struct {
    const char* remoteInputAesKey;
} StreamConfig;

struct EVP_CIPHER_CTX {
    int dummy;
};
struct EVP_CIPHER_CTX cipherContext;

#define EVP_aes_128_gcm() NULL
#define EVP_aes_128_cbc() NULL
#define EVP_CTRL_GCM_SET_IVLEN 0
#define EVP_CTRL_GCM_GET_TAG 0

static int EVP_CIPHER_CTX_init(struct EVP_CIPHER_CTX* ctx) { return 1; }
static int EVP_EncryptInit_ex(struct EVP_CIPHER_CTX* ctx, const void* cipher, void* impl, const unsigned char* key, const unsigned char* iv) { return 1; }
static int EVP_CIPHER_CTX_ctrl(struct EVP_CIPHER_CTX* ctx, int type, int arg, void* ptr) { return 1; }
static int EVP_EncryptUpdate(struct EVP_CIPHER_CTX* ctx, unsigned char* out, int* outl, const unsigned char* in, int inl) { return 1; }
static int EVP_EncryptFinal_ex(struct EVP_CIPHER_CTX* ctx, unsigned char* out, int* outl) { return 1; }
static void EVP_CIPHER_CTX_cleanup(struct EVP_CIPHER_CTX* ctx) {}

static int addPkcs7PaddingInPlace(unsigned char* data, int dataLen);