#include <stdbool.h>

enum CryptoMethod {
    ClientSSLv23,
    ClientTLS,
    ServerSSLv23,
    ClientSSLv3,
    ServerSSLv3,
    ClientSSLv2,
    ServerSSLv2,
    ServerTLS
};

struct SSL_METHOD;
struct SSL_CTX;
struct SSL;

struct Context {
    bool exists(const char*);
    void set(const char*, bool);
};

struct SSLSocketData {
    bool m_client;
    CryptoMethod m_method;
    SSL* m_handle;
    SSL_CTX* m_ctx;
};

class SSLSocket {
private:
    SSLSocketData* m_data;
    Context m_context;
    static const char* s_verify_peer;
    int getFd();
    void handleError(int, bool);
    SSL* createSSL(SSL_CTX*);
    void raise_warning(const char*);
public:
    bool setupCrypto(SSLSocket* session);
};

const char* SSLSocket::s_verify_peer = "verify_peer";

#define SSL_OP_ALL 0x80000BFFUL
#define TLS_client_method TLSv1_client_method
#define TLS_server_method TLSv1_server_method

SSL_METHOD* SSLv23_client_method();
SSL_METHOD* SSLv23_server_method();
SSL_METHOD* TLSv1_client_method();
SSL_METHOD* TLSv1_server_method();
SSL_METHOD* SSLv3_client_method();
SSL_METHOD* SSLv3_server_method();
SSL_METHOD* SSLv2_client_method();
SSL_METHOD* SSLv2_server_method();
SSL_CTX* SSL_CTX_new(SSL_METHOD*);
void SSL_CTX_free(SSL_CTX*);
void SSL_CTX_set_options(SSL_CTX*, int);
SSL* createSSL(SSL_CTX*);
int SSL_set_fd(SSL*, int);
void SSL_copy_session_id(SSL*, SSL*);