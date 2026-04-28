#include <stdint.h>

#define SESS_MAGIC 0
#define HTTP_CONN_MAGIC 0
#define HTTP_MAGIC 0
#define HTTP_Rx 0
#define HTTP_HDR_REQ 0
#define HTTP_HDR_URL 0
#define HTTP_HDR_PROTO 0
#define SLT_HttpGarbage 0
#define SLT_Error 0

struct sess {
    struct http_conn *htc;
    struct http *http;
    void *wrk;
    int fd;
};

struct http_conn {
    char *rxbuf;
};

struct http {
    int logtag;
};

#define CHECK_OBJ_NOTNULL(obj, magic) (void)0
#define WSPR(sp, slt, msg) (void)0
#define WSP(sp, slt, msg) (void)0

uint16_t http_splitline(void *wrk, int fd, struct http *hp, struct http_conn *htc, int hdr_req, int hdr_url, int hdr_proto);
void http_ProtoVer(struct http *hp);
uint16_t htc_request_check_host_hdr(struct http *hp);