#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <netinet/in.h>

typedef struct {
    void *protoctx;
    uint8_t proto;
    uint32_t flags;
    uint8_t alproto;
    void *alstate;
} Flow;

typedef struct {
    uint32_t flowflags;
    uint32_t flags;
    Flow *flow;
} Packet;

typedef struct {
    int dummy;
} ThreadVars;

typedef struct {
    int dummy;
} DetectEngineThreadCtx;

typedef struct {
    uint32_t flags;
} DetectEngineCtx;

typedef struct {
    int dummy;
} TcpSession;

typedef struct {
    int dummy;
} AppLayerParserThreadCtx;

typedef struct {
    int dummy;
} HtpState;

typedef struct {
    struct {
        struct {
            uint8_t *value;
            uint32_t value_len;
        } fv_str;
    } data;
} FlowVar;

typedef struct {
    int dummy;
} Signature;

#define IPPROTO_TCP 6
#define FLOW_IPV4 0x01
#define ALPROTO_HTTP 1
#define FLOW_PKT_TOSERVER 0x01
#define FLOW_PKT_ESTABLISHED 0x02
#define PKT_HAS_FLOW 0x01
#define PKT_STREAM_EST 0x02
#define TRUE 1
#define DE_QUIET 0x01
#define STREAM_TOSERVER 0x01

extern char *ut_script;