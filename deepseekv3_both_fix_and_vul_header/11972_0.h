#include <stdint.h>
#include <string.h>

typedef struct BT_HDR {
  uint16_t offset;
  uint16_t len;
} BT_HDR;

typedef struct AvdtpCcb {
  BT_HDR* p_rx_msg;
} AvdtpCcb;

#define AVDT_PKT_TYPE_SINGLE 0
#define AVDT_PKT_TYPE_START 1
#define AVDT_PKT_TYPE_END 2
#define AVDT_LEN_TYPE_CONT 1

extern uint8_t avdt_msg_pkt_type_len[];
extern void osi_free(void* ptr);
extern void osi_free_and_reset(void** ptr);
extern void* osi_malloc(size_t size);
extern void AVDT_TRACE_WARNING(const char* fmt, ...);
extern void AVDT_MSG_PRS_PKT_TYPE(uint8_t* p, uint8_t pkt_type);
extern void android_errorWriteLog(uint32_t tag, const char* msg);
#define BT_DEFAULT_BUFFER_SIZE 1024