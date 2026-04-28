#include <string>
#include <iostream>

class String {
public:
    const char* c_str() const { return ""; }
};

struct X509_VERIFY_PARAM;
#define X509_V_FLAG_TRUSTED_FIRST 0x8000
#define SSL_OP_ALL 0x80000BFFUL
#define SSL_MODE_AUTO_RETRY 0x00000004

class Socket {
public:
    int startSslClient(const std::string &certificate_path, String hostname);
    void stopSsl();
    int getFD();
    bool isssl;
    bool issslserver;
    void* ctx;
    void* ssl;
};

void ERR_clear_error();
void log_ssl_errors(const char* fmt, const char* str);
void* SSL_CTX_new(void* method);
void* SSLv23_client_method();
void* TLS_client_method();
int SSL_CTX_set_timeout(void* ctx, long timeout);
void SSL_CTX_free(void* ctx);
int SSL_CTX_load_verify_locations(void* ctx, const char* ca_file, const char* ca_path);
int SSL_CTX_set_default_verify_paths(void* ctx);
X509_VERIFY_PARAM* X509_VERIFY_PARAM_new();
int X509_VERIFY_PARAM_set_flags(X509_VERIFY_PARAM* param, unsigned long flags);
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM* param);
int SSL_CTX_set1_param(void* ctx, X509_VERIFY_PARAM* param);
void* SSL_new(void* ctx);
void SSL_set_options(void* ssl, long options);
void SSL_set_mode(void* ssl, long mode);
void SSL_set_connect_state(void* ssl);
void SSL_set_fd(void* ssl, int fd);
void SSL_set_tlsext_host_name(void* ssl, const char* name);
int SSL_connect(void* ssl);
int SSL_get_error(void* ssl, int ret);
void SSL_free(void* ssl);
void* SSL_get0_param(void* ssl);
int X509_VERIFY_PARAM_set1_host(X509_VERIFY_PARAM* param, const char* name, size_t namelen);