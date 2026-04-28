#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct nghttp2_session nghttp2_session;
typedef struct nghttp2_frame nghttp2_frame;

struct HTTP {
    char **push_headers;
    size_t push_headers_alloc;
    size_t push_headers_used;
    int bodystarted;
    int status_code;
    void *header_recvbuf;
    void *trailer_recvbuf;
};

struct Curl_easy {
    struct {
        struct HTTP *protop;
    } req;
};

struct connectdata {
    struct Curl_easy *data;
};

struct nghttp2_frame_hd {
    int32_t stream_id;
    uint8_t type;
};

struct nghttp2_frame {
    struct nghttp2_frame_hd hd;
};

#define NGHTTP2_PUSH_PROMISE 0x05
#define NGHTTP2_ERR_CALLBACK_FAILURE -902
#define NGHTTP2_ERR_TEMPORAL_CALLBACK_FAILURE -907
#define EXPIRE_RUN_NOW 0

#define DEBUGASSERT(x)
#define DEBUGF(x)
#define failf(x, y)
#define infof(x, y, ...)

static int decode_status_code(const uint8_t *value, size_t valuelen) { return 0; }
static void *nghttp2_session_get_stream_user_data(nghttp2_session *session, int32_t stream_id) { return NULL; }
static void Curl_add_buffer(void *buf, const void *data, size_t len) {}
static void *Curl_saferealloc(void *ptr, size_t size) { return NULL; }
static char *aprintf(const char *fmt, ...) { return NULL; }
static void Curl_expire(struct Curl_easy *data, int ms, int expire_now) {}