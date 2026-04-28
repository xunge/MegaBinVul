#include <unistd.h>

enum ConnectionSecurityLevel {
    ENCRYPTED_AUTHENTICATED
};

namespace barrier {
    class DataDirectories {
    public:
        static const char* trusted_clients_ssl_fingerprints_path();
    };
}

class SSL;
class SSLWrapper {
public:
    SSL* m_ssl;
};

class ARCH {
public:
    static void sleep(unsigned int seconds);
};

class CLOG {
public:
    static int getFilter();
};

class SecureSocket {
private:
    SSLWrapper* m_ssl;
    bool m_secureReady;
    ConnectionSecurityLevel security_level_;
    static const int s_retryDelay = 1;

public:
    int secureAccept(int socket);
    void createSSL();
    void checkResult(int r, int& retry);
    bool isFatal();
    bool verify_cert_fingerprint(const char* path);
    bool ensure_peer_certificate();
    void disconnect();
    void showSecureCipherInfo();
    void showSecureConnectInfo();
    static int SSL_accept(SSL* ssl);
    static void SSL_set_fd(SSL* ssl, int fd);
};

#define LOG(x)
#define CLOG_DEBUG2 ""
#define CLOG_ERR ""
#define CLOG_INFO ""
#define kDEBUG1 1

extern ARCH* ARCH;
extern CLOG* CLOG;