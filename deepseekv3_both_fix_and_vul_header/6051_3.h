#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

struct h2_error {
    const char *name;
};

typedef struct h2_error *h2_error;

typedef struct worker worker;
typedef struct h2_sess h2_sess;
typedef struct req req;
typedef struct h2_req h2_req;
typedef struct http http;
typedef struct vsl vsl;
typedef struct sess sess;
typedef struct ws ws;
typedef struct task task;
typedef struct pool pool;
typedef struct mtx {
    int dummy;
} mtx;
typedef struct htc htc;

enum req_body_status {
    REQ_BODY_NONE,
    REQ_BODY_INIT,
    REQ_BODY_WITHOUT_LEN,
    REQ_BODY_WITH_LEN
};

enum h2_state {
    H2_S_OPEN,
    H2_S_CLOS_REM,
    H2_S_CLOSED
};

enum http_hdr {
    HTTP_HDR_METHOD,
    HTTP_HDR_URL,
    HTTP_HDR_PROTO,
    H_Cookie,
    H_Content_Length
};

static struct h2_error H2SE_PROTOCOL_ERROR_VAL = { "H2SE_PROTOCOL_ERROR" };
static struct h2_error H2CE_PROTOCOL_ERROR_VAL = { "H2CE_PROTOCOL_ERROR" };
static struct h2_error H2SE_REFUSED_STREAM_VAL = { "H2SE_REFUSED_STREAM" };

static h2_error H2SE_PROTOCOL_ERROR = &H2SE_PROTOCOL_ERROR_VAL;
static h2_error H2CE_PROTOCOL_ERROR = &H2CE_PROTOCOL_ERROR_VAL;
static h2_error H2SE_REFUSED_STREAM = &H2SE_REFUSED_STREAM_VAL;

enum req_step {
    R_STP_TRANSPORT
};

enum task_queue {
    TASK_QUEUE_STR
};

enum slt_tag {
    SLT_Debug
};

struct http {
    struct {
        const char *b;
    } hd[16];
};

struct task {
    void (*func)(void *);
    void *priv;
};

struct req {
    enum req_body_status req_body_status;
    struct http *http;
    enum req_step req_step;
    struct task task;
    struct ws *ws;
    struct htc *htc;
    double t_req;
};

struct h2_req {
    enum h2_state state;
    struct req *req;
    int scheduled;
};

struct h2_sess {
    struct sess *sess;
    struct vsl *vsl;
    struct h2_req *new_req;
};

struct sess {
    struct mtx mtx;
};

struct vsl {
    int dummy;
};

struct ws {
    void *r;
};

struct pool {
    int dummy;
};

struct htc {
    ssize_t content_length;
};

#define ASSERT_RXTHR(h2)
#define AZ(x) assert((x) == 0)
#define AN(x) assert((x) != 0)
#define Lck_Lock(x)
#define Lck_Unlock(x)
#define VSLb(vsl, tag, fmt, ...)
#define VSLb_ts_req(req, tag, time)
#define http_CollectHdrSep(http, hdr, sep)
#define http_GetContentLength(http) (-1)
#define http_GetHdr(http, hdr, b) (0)
#define Pool_Task(pool, task, queue) (0)
#define h2h_decode_fini(h2) (NULL)
#define h2_del_req(wrk, r2)
#define h2_do_req ((void (*)(void *))0)