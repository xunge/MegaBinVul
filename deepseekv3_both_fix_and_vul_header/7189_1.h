#include <string.h>
#include <stddef.h>

typedef int apr_status_t;
typedef size_t apr_size_t;

typedef struct mgs_handle_t mgs_handle_t;
typedef struct char_buffer_t char_buffer_t;

struct char_buffer_t {
    char *value;
    apr_size_t length;
};

struct mgs_handle_t {
    char_buffer_t input_cbuf;
    int input_mode;
    int input_block;
    void *session;
    apr_status_t input_rc;
    void *c;
};

#define AP_MODE_SPECULATIVE 0
#define AP_MODE_GETLINE 1
#define APR_NONBLOCK_READ 0
#define APR_ASCII_LF '\n'
#define APR_SUCCESS 0
#define APR_EGENERAL -1
#define APR_EOF -2
#define APR_EAGAIN -3
#define APR_EINTR -4
#define APR_STATUS_IS_TIMEUP(x) (0)

#define APLOG_MARK 0
#define APLOG_INFO 0
#define APLOG_TRACE2 0
#define APLOG_DEBUG 0

#define GNUTLS_E_INTERRUPTED -1
#define GNUTLS_E_AGAIN -2
#define GNUTLS_E_REHANDSHAKE -3
#define GNUTLS_E_WARNING_ALERT_RECEIVED -4
#define GNUTLS_E_FATAL_ALERT_RECEIVED -5
#define GNUTLS_E_PULL_ERROR -6

const char *gnutls_strerror(int error);
int gnutls_alert_get(void *session);
const char *gnutls_alert_get_name(int alert);
int gnutls_error_is_fatal(int error);
int gnutls_record_recv(void *session, char *buf, size_t len);

void ap_log_cerror(int mark, int level, apr_status_t status, void *c, const char *fmt, ...);
apr_size_t char_buffer_read(char_buffer_t *cbuf, char *buf, apr_size_t len);
void char_buffer_write(char_buffer_t *cbuf, char *buf, int len);