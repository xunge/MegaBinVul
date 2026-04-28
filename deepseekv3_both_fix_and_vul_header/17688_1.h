#include <stdint.h>
#include <inttypes.h>

typedef unsigned char BYTE;
typedef uint16_t UINT16;

typedef struct rdpTransport rdpTransport;
typedef struct wStream wStream;

typedef struct rdpNego {
    uint32_t SelectedProtocol;
    int state;
    int EnabledProtocols[3];
} rdpNego;

#define TYPE_RDP_NEG_RSP 1
#define TYPE_RDP_NEG_FAILURE 2

#define PROTOCOL_RDP 0
#define PROTOCOL_SSL 1
#define PROTOCOL_HYBRID 2

#define NEGO_STATE_FAIL 0
#define NEGO_STATE_FINAL 1

#define TAG "nego"

int tpkt_read_header(wStream* s, UINT16* length);
int tpdu_read_connection_confirm(wStream* s, BYTE* li, UINT16 length);
int nego_process_negotiation_response(rdpNego* nego, wStream* s);
int nego_process_negotiation_failure(rdpNego* nego, wStream* s);
int tpkt_ensure_stream_consumed(wStream* s, UINT16 length);
void Stream_Read_UINT8(wStream* s, BYTE* val);

void WLog_DBG(const char* tag, const char* format, ...);
void WLog_ERR(const char* tag, const char* format, ...);