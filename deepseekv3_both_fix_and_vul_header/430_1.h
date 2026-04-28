#include <stdint.h>
#include <stddef.h>

typedef struct DetectEngineThreadCtx {
    void *raw_stream_progress;
} DetectEngineThreadCtx;

typedef struct Packet {
    uint8_t proto;
    uint8_t flags;
} Packet;

typedef struct Flow {
    void *protoctx;
} Flow;

#define IPPROTO_TCP 6
#define PKT_STREAM_EST 0x01
#define PROF_DETECT_CLEANUP 0
#define SCReturn

void PACKET_PROFILING_DETECT_START(Packet *p, int profile);
void PACKET_PROFILING_DETECT_END(Packet *p, int profile);
void PacketPatternCleanup(DetectEngineThreadCtx *det_ctx);
void StreamReassembleRawUpdateProgress(void *protoctx, Packet *p, void *progress);
void DetectEngineCleanHCBDBuffers(DetectEngineThreadCtx *det_ctx);