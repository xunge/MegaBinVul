#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <cstdint>

constexpr size_t maxKeySize = 32;
constexpr size_t META_PASSWD_SIG = 0x50534D42;
const char* encryptKeyFileName = "/etc/ipmi_pass/encrypt_key";
const char* passwdFileName = "/etc/ipmi_pass/passwd";

struct EVP_CIPHER {
    int dummy;
};

struct EVP_MD {
    int dummy;
};

#define EVP_aes_128_cbc() (nullptr)
#define EVP_sha256() (nullptr)
#define EVP_CIPHER_block_size(cipher) (16)
#define EVP_MD_block_size(digest) (32)
#define EVP_CIPHER_iv_length(cipher) (16)
#define EVP_MAX_KEY_LENGTH (32)
#define EVP_MAX_MD_SIZE (32)
#define EVP_MAX_BLOCK_LENGTH (16)

inline int RAND_bytes(uint8_t* buf, size_t len) { return 1; }
inline void* HMAC(const EVP_MD* digest, const void* key, int key_len,
                 const uint8_t* data, size_t data_len, uint8_t* md,
                 unsigned int* md_len) { return nullptr; }
inline void OPENSSL_cleanse(void* ptr, size_t len) {}

struct MetaPassStruct {
    size_t signature;
    struct {
        uint8_t major;
        uint8_t minor;
    } version;
    size_t hashSize;
    size_t ivSize;
    size_t dataSize;
    size_t padSize;
    size_t macSize;
};

class PasswdMgr {
public:
    int updatePasswdSpecialFile(const std::string& userName,
                              const std::string& newUserName);
};

namespace phosphor {
namespace user {
namespace shadow {
class Lock {
public:
    Lock() {}
};
} // namespace shadow

class File {
public:
    File(int fd, const std::string& name, const char* mode, bool) {}
    FILE* operator()() { return nullptr; }
};
} // namespace user
} // namespace phosphor

namespace level {
const int DEBUG = 0;
}

int readPasswdFileData(std::vector<uint8_t>&) { return 0; }
int encryptDecryptData(bool, const EVP_CIPHER*, const uint8_t*, size_t,
                      const uint8_t*, size_t, const uint8_t*, size_t,
                      uint8_t*, size_t*, uint8_t*, size_t*) { return 0; }

template<int level>
void log(const char*) {}