#include <sys/types.h>
#include <stdint.h>
#include <stddef.h>

#define DLT_JUNIPER_ATM2 123
#define ATM2_PKT_TYPE_MASK 0x01
#define ATM_OAM_NOHEC 0
#define ATM2_GAP_COUNT_MASK 0x0F
#define JUNIPER_BPF_PKT_IN 0

typedef struct netdissect_options netdissect_options;

struct pcap_pkthdr {
    struct timeval ts;
    uint32_t caplen;
    uint32_t len;
};

struct juniper_l2info_t {
    int pictype;
    int header_len;
    uint8_t cookie[8];
    int length;
    int caplen;
    int direction;
};

#define EXTRACT_24BITS(p) ((uint32_t)((p)[0] << 16 | (p)[1] << 8 | (p)[2]))
#define EXTRACT_32BITS(p) ((uint32_t)((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3]))