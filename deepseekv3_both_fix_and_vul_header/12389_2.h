class CSecurityTLS {
public:
    void shutdown(bool needbye);
};

typedef void* gnutls_session_t;
typedef void* gnutls_anon_client_credentials_t; 
typedef void* gnutls_certificate_credentials_t;

#define GNUTLS_SHUT_RDWR 0
#define GNUTLS_E_SUCCESS 0

extern gnutls_session_t session;
extern gnutls_anon_client_credentials_t anon_cred;
extern gnutls_certificate_credentials_t cert_cred;

int gnutls_bye(gnutls_session_t, int);
void gnutls_anon_free_client_credentials(gnutls_anon_client_credentials_t);
void gnutls_certificate_free_credentials(gnutls_certificate_credentials_t);
void gnutls_deinit(gnutls_session_t);
void gnutls_global_deinit();

class VLog {
public:
    void error(const char* msg);
};
extern VLog vlog;