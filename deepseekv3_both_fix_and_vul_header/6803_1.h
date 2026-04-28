#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct ThreadVars ThreadVars;
typedef struct DetectEngineCtx DetectEngineCtx;
typedef struct DetectEngineThreadCtx DetectEngineThreadCtx;

typedef struct Flow {
    uint8_t flags;
} Flow;

typedef struct Packet {
    uint64_t flags;
    uint64_t actions;
    uint64_t flowflags;
    uint64_t pcap_cnt;
    uint8_t proto;
    Flow *flow;
} Packet;

typedef enum {
    PKT_NOPACKET_INSPECTION = (1 << 0),
    FLOW_NOPACKET_INSPECTION = (1 << 0),
    FLOW_PKT_TOSERVER = (1 << 0),
    ACTION_DROP = (1 << 0)
} Flags;

typedef enum {
    STREAM_TOSERVER,
    STREAM_TOCLIENT
} StreamFlags;

typedef uint8_t AppProto;

AppProto FlowGetAppProtocol(Flow *flow);
int AppLayerParserProtocolSupportsTxs(uint8_t proto, AppProto alproto);
uint8_t FlowGetDisruptionFlags(Flow *flow, uint8_t flags);
void DeStateUpdateInspectTransactionId(Flow *flow, uint8_t flags, bool update);
int DetectRun(ThreadVars *tv, DetectEngineCtx *de_ctx, DetectEngineThreadCtx *det_ctx, Packet *p);
#define PACKET_TEST_ACTION(p, action) ((p)->actions & (action))