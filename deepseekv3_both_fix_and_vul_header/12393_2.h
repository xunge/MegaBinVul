#include <string>
#include <exception>
#include <cstdio>

extern int GNUTLS_E_SUCCESS;
int gnutls_global_init();

template<typename T>
class ConfigItem {
public:
    const char* getData() { return data.c_str(); }
private:
    std::string data;
};

extern ConfigItem<std::string> X509_CertFile;
extern ConfigItem<std::string> X509_KeyFile;

class AuthFailureException : public std::exception {
public:
    AuthFailureException(const char* msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
private:
    std::string message;
};

class SSecurityTLS {
private:
    void* session;
    void* dh_params;
    void* anon_cred;
    void* cert_cred;
    bool anon;
    FILE* fis;
    FILE* fos;
    const char* certfile;
    const char* keyfile;
public:
    SSecurityTLS(bool _anon);
};