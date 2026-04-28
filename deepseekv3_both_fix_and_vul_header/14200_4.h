#include <string>
#include <exception>
#include <vector>

namespace barrier {
namespace fs {
    class path {
    public:
        std::string u8string() const;
    };
}

enum class FingerprintType { SHA1, SHA256 };

struct FingerprintData {
    std::string data;
};

struct X509;
struct SSL;

class SecureSocket {
public:
    struct SSLWrapper {
        SSL* m_ssl;
    };
    SSLWrapper* m_ssl;

    bool verify_cert_fingerprint(const fs::path& fingerprint_db_path);
};

FingerprintData get_ssl_cert_fingerprint(X509* cert, FingerprintType type);
std::string format_ssl_fingerprint(const std::string& fingerprint);

class FingerprintDatabase {
public:
    void read(const fs::path& path);
    bool is_trusted(const FingerprintData& fingerprint) const;
    const std::vector<FingerprintData>& fingerprints() const;

private:
    std::vector<FingerprintData> m_fingerprints;
};

X509* SSL_get_peer_certificate(SSL* ssl);

#define CLOG_ERR 0
#define CLOG_NOTE 0
#define LOG(x)
}

using namespace barrier;