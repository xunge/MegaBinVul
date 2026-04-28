#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

typedef void* gnutls_transport_ptr_t;
typedef struct gnutls_session_int *gnutls_session_t;

typedef size_t apr_size_t;
typedef int apr_status_t;

typedef struct apr_bucket_brigade apr_bucket_brigade;
typedef struct ap_filter_t {
    struct ap_filter_t *next;
} ap_filter_t;
typedef struct conn_rec conn_rec;

typedef struct mgs_handle_t {
    apr_bucket_brigade *input_bb;
    ap_filter_t *input_filter;
    int input_block;
    apr_status_t input_rc;
    gnutls_session_t session;
    conn_rec *c;
} mgs_handle_t;

typedef enum {
    APR_BLOCK_READ,
    APR_NONBLOCK_READ
} apr_read_type_e;

#define APR_SUCCESS 0
#define APR_EOF 1
#define APR_EINTR 2
#define APR_EAGAIN 3
#define APR_TIMEUP 4
#define APR_STATUS_IS_EAGAIN(x) ((x) == APR_EAGAIN)
#define APR_STATUS_IS_EINTR(x) ((x) == APR_EINTR)
#define APR_STATUS_IS_TIMEUP(x) ((x) == APR_TIMEUP)
#define APR_STATUS_IS_EOF(x) ((x) == APR_EOF)
#define APR_BRIGADE_EMPTY(x) (1)
#define AP_MODE_READBYTES 0
#define APLOG_MARK 0
#define APLOG_INFO 0

void gnutls_transport_set_errno(gnutls_session_t session, int err);
int EAI_APR_TO_RAW(apr_status_t rc);
apr_status_t ap_get_brigade(ap_filter_t *next, apr_bucket_brigade *bb, int mode, int block, apr_size_t len);
void ap_log_cerror(int mark, int level, apr_status_t rc, conn_rec *c, const char *msg, ...);
void apr_brigade_cleanup(apr_bucket_brigade *bb);
apr_status_t brigade_consume(apr_bucket_brigade *bb, int block, void *buffer, size_t *len);