#include <stdlib.h>
#include <string.h>

#define IS_ENABLED(x) 0
#define CONFIG_PASSWD_CRYPTO_PBKDF2 0
#define PBKDF2_LENGTH 0
#define PBKDF2_SALT_LEN 0
#define PBKDF2_COUNT 0
#define PASSWD_SUM NULL
#define ENOENT 2
#define ENOMEM 12
#define EINVAL 22

struct digest {
    // dummy structure
};

static struct digest* digest_alloc(const char* algo) { return NULL; }
static int digest_length(struct digest* d) { return 0; }
static void digest_free(struct digest* d) {}
static int digest_digest(struct digest* d, unsigned char* data, size_t len, unsigned char* out) { return 0; }
static int is_passwd_env_enable() { return 0; }
static int is_passwd_default_enable() { return 0; }
static int read_env_passwd(unsigned char* out, int len) { return 0; }
static int read_default_passwd(unsigned char* out, int len) { return 0; }
static int pkcs5_pbkdf2_hmac_sha1(unsigned char* pass, size_t pass_len, char* salt, int salt_len, int iterations, int key_len, unsigned char* out) { return 0; }