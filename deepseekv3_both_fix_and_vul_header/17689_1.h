#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define BOOL bool
#define BYTE uint8_t
#define UINT16 uint16_t
#define PRIu8 "u"
#define FALSE false
#define TAG ""

typedef struct rdpNego rdpNego;
typedef struct wStream wStream;

#define TYPE_RDP_NEG_REQ 0

bool tpkt_read_header(wStream* s, UINT16* length);
bool tpdu_read_connection_request(wStream* s, BYTE* li, UINT16 length);
size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT8(wStream* s, BYTE* val);
bool nego_read_request_token_or_cookie(rdpNego* nego, wStream* s);
bool nego_process_negotiation_request(rdpNego* nego, wStream* s);
bool tpkt_ensure_stream_consumed(wStream* s, UINT16 length);
void WLog_ERR(const char* tag, const char* fmt, ...);