#include <stdio.h>
#include <stdarg.h>

typedef int gnutls_alert_description_t;
typedef void* gnutls_certificate_credentials_t;
typedef void* gnutls_session_t;
typedef void* gnutls_transport_ptr_t;

#define GNUTLS_X509_FMT_PEM 0
#define GNUTLS_E_SUCCESS 0
#define GNUTLS_E_WARNING_ALERT_RECEIVED 1
#define GNUTLS_E_FATAL_ALERT_RECEIVED 2
#define GNUTLS_SERVER 0
#define GNUTLS_CLIENT 1
#define GNUTLS_CRD_CERTIFICATE 0
#define GNUTLS_CERT_REQUIRE 0
#define GNUTLS_SHUT_RDWR 0

extern int csync_conn_usessl;
extern char *systemdir;
extern FILE *csync_debug_out;
extern int conn_fd_in;
extern int conn_fd_out;
extern gnutls_certificate_credentials_t conn_x509_cred;
extern gnutls_session_t conn_tls_session;

void ssl_log(int level, const char *message);
void csync_fatal(const char *format, ...);
int ASPRINTF(char **strp, const char *fmt, ...);
const char *gnutls_strerror(int err);
const char *gnutls_strerror_name(int err);
const char *gnutls_alert_get_name(gnutls_alert_description_t alrt);
int gnutls_alert_get(gnutls_session_t session);
int gnutls_global_init(void);
void gnutls_global_deinit(void);
void gnutls_global_set_log_function(void (*log_func)(int, const char*));
void gnutls_global_set_log_level(int level);
int gnutls_certificate_allocate_credentials(gnutls_certificate_credentials_t *cred);
void gnutls_certificate_free_credentials(gnutls_certificate_credentials_t cred);
int gnutls_certificate_set_x509_key_file(gnutls_certificate_credentials_t cred, const char *certfile, const char *keyfile, int format);
void gnutls_certificate_free_cas(gnutls_certificate_credentials_t cred);
int gnutls_certificate_set_x509_trust_file(gnutls_certificate_credentials_t cred, const char *file, int format);
void gnutls_certificate_free_ca_names(gnutls_certificate_credentials_t cred);
int gnutls_init(gnutls_session_t *session, int type);
int gnutls_priority_set_direct(gnutls_session_t session, const char *priorities, const char **err_pos);
int gnutls_credentials_set(gnutls_session_t session, int type, gnutls_certificate_credentials_t cred);
void gnutls_certificate_send_x509_rdn_sequence(gnutls_session_t session, int status);
void gnutls_certificate_server_set_request(gnutls_session_t session, int req);
void gnutls_transport_set_ptr2(gnutls_session_t session, gnutls_transport_ptr_t recv_ptr, gnutls_transport_ptr_t send_ptr);
int gnutls_handshake(gnutls_session_t session);
int gnutls_bye(gnutls_session_t session, int how);
void gnutls_deinit(gnutls_session_t session);