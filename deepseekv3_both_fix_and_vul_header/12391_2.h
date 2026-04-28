class SSecurityTLS {
public:
    void shutdown();
    
    void* session;
    void* dh_params;
    void* anon_cred;
    void* cert_cred;
};

class VLog {
public:
    void error(const char*);
};

VLog vlog;

#define GNUTLS_SHUT_RDWR 0
#define GNUTLS_E_SUCCESS 0

static int gnutls_bye(void*, int) { return 0; }
static void gnutls_dh_params_deinit(void*) {}
static void gnutls_anon_free_server_credentials(void*) {}
static void gnutls_certificate_free_credentials(void*) {}
static void gnutls_deinit(void*) {}
static void gnutls_global_deinit() {}