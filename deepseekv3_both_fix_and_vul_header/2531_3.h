#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

#define DLT_JUNIPER_ATM2 123
#define ATM2_PKT_TYPE_MASK 0x01
#define ATM_OAM_NOHEC 0
#define ATM2_GAP_COUNT_MASK 0xFFFF
#define JUNIPER_BPF_PKT_IN 0

typedef struct netdissect_options netdissect_options;

struct pcap_pkthdr {
    struct timeval ts;
    uint32_t caplen;
    uint32_t len;
};

struct juniper_l2info_t {
    int pictype;
    uint32_t header_len;
    uint8_t cookie[8];
    uint32_t length;
    uint32_t caplen;
    int direction;
};

#define EXTRACT_24BITS(p) ((p)[0] << 16 | (p)[1] << 8 | (p)[2])
#define EXTRACT_32BITS(p) ((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3])