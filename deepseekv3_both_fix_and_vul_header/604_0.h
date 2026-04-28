#include <stdint.h>
#include <inttypes.h>

typedef struct {
    uint16_t off_ctl;
} tcp_hdr_t;

typedef struct {
    uint8_t kind;
    uint8_t length;
    uint8_t value[];
} tcp_hdr_opt_t;

typedef struct {
    uint16_t mss;
} gnrc_tcp_tcb_t;

#define GET_OFFSET(x) ((x) >> 12)
#define TCP_HDR_OFFSET_MIN 5
#define TCP_OPTION_KIND_EOL 0
#define TCP_OPTION_KIND_NOP 1
#define TCP_OPTION_KIND_MSS 2
#define TCP_OPTION_LENGTH_MSS 4

#define DEBUG(...)