#include <cstddef>

typedef struct ssl_method_st SSL_METHOD;
typedef struct ssl_ctx_st SSL_CTX;
typedef struct x509_store_ctx_st X509_STORE_CTX;

enum ConnectionSecurityLevel {
    ENCRYPTED_AUTHENTICATED
};

enum LogLevel {
    kINFO
};

struct SSLWrapper {
    SSL_CTX* m_context;
};

struct SecureSocket {
    SSLWrapper* m_ssl;
    ConnectionSecurityLevel security_level_;
    void initContext(bool server);
    void showError(const char*);
    void showSecureLibInfo();
    LogLevel getFilter();
};

extern SecureSocket* CLOG;

#define SSL_OP_NO_SSLv3 0x02000000L
#define SSL_VERIFY_PEER 0x01
#define SSL_VERIFY_FAIL_IF_NO_PEER_CERT 0x02

int SSL_library_init();
void OpenSSL_add_all_algorithms();
void SSL_load_error_strings();
const SSL_METHOD* SSLv23_server_method();
const SSL_METHOD* SSLv23_client_method();
SSL_CTX* SSL_CTX_new(const SSL_METHOD*);
void SSL_CTX_set_options(SSL_CTX*, unsigned long);
void SSL_CTX_set_verify(SSL_CTX*, int, int (*)(int, X509_STORE_CTX*));
void SSL_CTX_set_cert_verify_callback(SSL_CTX*, int (*)(int, X509_STORE_CTX*), void*);
int cert_verify_ignore_callback(int, X509_STORE_CTX*);