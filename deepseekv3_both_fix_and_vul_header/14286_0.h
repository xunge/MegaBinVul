#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define TCP_OPTMAX 40
#define TCP_OPT_EOL 0
#define TCP_OPT_NOP 1
#define TCP_OPT_WS 3
#define TCP_OPT_WS_LEN 3
#define TCP_OPT_MSS 2
#define TCP_OPT_MSS_LEN 4
#define TCP_OPT_SACKOK 4
#define TCP_OPT_SACKOK_LEN 2
#define TCP_OPT_TS 8
#define TCP_OPT_TS_LEN 10
#define TCP_OPT_SACK 5
#define TCP_OPT_SACK_MIN_LEN 10
#define TCP_OPT_SACK_MAX_LEN 34
#define TCP_OPT_TFO 34
#define TCP_OPT_TFO_MIN_LEN 4
#define TCP_OPT_TFO_MAX_LEN 6
#define TCP_OPT_EXP1 253
#define TCP_OPT_EXP2 254
#define TCP_OPT_MD5 19
#define TCP_OPT_AO 29
#define TCP_OPT_INVALID_LEN 1
#define TCP_OPT_DUPLICATE 2

#define unlikely(x) (x)
#define SCNtohl(x) (x)
#define SCNtohs(x) (x)
#define SCLogDebug(fmt, ...)
#define ENGINE_SET_EVENT(p, x)
#define ENGINE_SET_INVALID_EVENT(p, x)
#define SET_OPTS(dst, src) memcpy(&(dst), &(src), sizeof(src))

typedef struct {
    uint8_t type;
    uint8_t len;
    const uint8_t *data;
} TCPOpt;

typedef struct {
    TCPOpt ws;
    TCPOpt mss;
    TCPOpt sackok;
    bool ts_set;
    uint32_t ts_val;
    uint32_t ts_ecr;
    TCPOpt sack;
    TCPOpt tfo;
    bool md5_option_present;
    bool ao_option_present;
} TCPVars;

typedef struct {
    TCPVars tcpvars;
} Packet;