#include <stdint.h>
#include <inttypes.h>

#define ERROR_INVALID_DATA 1
#define CHANNEL_RC_OK 0

typedef uint32_t UINT;
typedef uint16_t UINT16;
typedef uint32_t UINT32;

typedef struct _wStream wStream;
typedef struct _RDPEI_CHANNEL_CALLBACK RDPEI_CHANNEL_CALLBACK;

#define EVENTID_SC_READY 0x0001
#define EVENTID_SUSPEND_TOUCH 0x0002
#define EVENTID_RESUME_TOUCH 0x0003

#define TAG "RDPEI"

#define WLog_DBG(tag, ...) 
#define WLog_ERR(tag, ...) 

static UINT rdpei_recv_sc_ready_pdu(RDPEI_CHANNEL_CALLBACK* callback, wStream* s);
static UINT rdpei_send_cs_ready_pdu(RDPEI_CHANNEL_CALLBACK* callback);
static UINT rdpei_recv_suspend_touch_pdu(RDPEI_CHANNEL_CALLBACK* callback, wStream* s);
static UINT rdpei_recv_resume_touch_pdu(RDPEI_CHANNEL_CALLBACK* callback, wStream* s);
static const char* rdpei_eventid_string(UINT16 eventId);