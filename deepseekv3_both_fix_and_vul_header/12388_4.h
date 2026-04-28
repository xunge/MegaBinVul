class CSecurityTLS {
private:
    void* session;
    void* anon_cred;
    bool anon;
    void* fis;
    void* fos;
    const char* cafile;
    const char* crlfile;
public:
    CSecurityTLS(bool _anon);
};

class X509CA {
public:
    static const char* getData();
} X509CA;

class X509CRL {
public:
    static const char* getData();
} X509CRL;

class AuthFailureException {
public:
    AuthFailureException(const char* msg);
};

enum {
    GNUTLS_E_SUCCESS = 0
};

int gnutls_global_init();