#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int COUNTER;
#define COUNTER_SPEC "%d"

#define MAXPACKET 65536
#define ENABLE_FRAGROUTE
#define ENABLE_VERBOSE
#define DEBUG

typedef enum {
    TCPR_DIR_C2S,
    TCPR_DIR_S2C,
    TCPR_DIR_NOSEND
} tcpr_dir_t;

typedef enum {
    TCPEDIT_ERROR,
    TCPEDIT_SOFT_ERROR
} tcpedit_rc_t;

typedef struct {
    int verbose;
    void *cachedata;
    struct {
        char errbuf[256];
    } *frag_ctx;
    int fragroute_dir;
} options_t;

typedef struct {
    // tcpdump context fields
} tcpdump_t;

typedef struct {
    // tcpedit context fields
} tcpedit_t;

struct pcap_pkthdr {
    uint32_t ts_sec;
    uint32_t ts_usec;
    uint32_t caplen;
    uint32_t len;
};

typedef struct pcap pcap_t;
typedef struct pcap_dumper pcap_dumper_t;

#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IP6 0x86DD

extern options_t options;
extern tcpdump_t tcpdump;

#define HAVE_OPT(opt) (0)
#define SKIP_SOFT_ERRORS (0)
#define FRAGROUTE_DIR_BOTH 0
#define FRAGROUTE_DIR_C2S 1
#define FRAGROUTE_DIR_S2C 2
#define AFTER_PROCESS 0

void *safe_malloc(size_t size);
tcpr_dir_t check_cache(void *cachedata, COUNTER packetnum);
int tcpedit_packet(tcpedit_t *tcpedit, struct pcap_pkthdr **pkthdr_ptr, uint8_t **pktdata, tcpr_dir_t cache_result);
int tcpedit_l3proto(tcpedit_t *tcpedit, int after_process, uint8_t *pktdata, int caplen);
void tcpdump_print(tcpdump_t *tcpdump, struct pcap_pkthdr *pkthdr_ptr, uint8_t *pktdata);
int fragroute_process(void *frag_ctx, uint8_t *pktdata, int caplen);
int fragroute_getfragment(void *frag_ctx, char **frag);
void dbgx(int level, const char *fmt, ...);
void errx(int status, const char *fmt, ...);
const uint8_t *pcap_next(pcap_t *p, struct pcap_pkthdr *h);
void pcap_dump(uint8_t *user, const struct pcap_pkthdr *h, const uint8_t *sp);