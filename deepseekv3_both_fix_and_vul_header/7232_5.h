#include <memory>
#include <vector>
#include <string>
#include <type_traits>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <format>

#define EVP_MAX_MD_SIZE 64
#define SHA256_DIGEST_LENGTH 32
#define RELEASE_ASSERT(x, y) do { if (!(x)) { throw std::runtime_error(y); } } while (0)

namespace bssl {
class ScopedEVP_MD_CTX {
public:
    void* get();
};
}

class X509;
int X509_digest(X509* x, void* md, uint8_t* buf, unsigned* len);
void* EVP_sha256();
int EVP_DigestUpdate(void* ctx, const void* data, size_t len);

class DefaultCertValidator {
public:
    void updateDigestForSessionId(bssl::ScopedEVP_MD_CTX& md,
                                uint8_t hash_buffer[EVP_MAX_MD_SIZE],
                                unsigned hash_length);
private:
    std::shared_ptr<X509> ca_cert_;
    std::vector<std::vector<uint8_t>> verify_certificate_hash_list_;
    std::vector<std::vector<uint8_t>> verify_certificate_spki_list_;
    bool verify_trusted_ca_;
    struct Config {
        std::vector<std::string> subjectAltNameMatchers();
        std::string certificateRevocationList();
        bool allowExpiredCertificate();
        int trustChainVerification();
        bool onlyVerifyLeafCertificateCrl();
    };
    std::shared_ptr<Config> config_;
};

namespace Utility {
    std::optional<std::string> getLastCryptoError();
}

namespace MessageUtil {
    size_t hash(const std::string& matcher);
}

namespace fmt {
    std::string format(const std::string& fmt, unsigned length);
}