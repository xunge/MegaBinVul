#include <stdlib.h>
#include <string.h>

typedef unsigned char u_char;
typedef unsigned long COUNTER;
#define COUNTER_SPEC "%lu"

#define MAXPACKET 65536
#define ENABLE_FRAGROUTE
#define ENABLE_VERBOSE
#define HAVE_OPT(x) (0)
#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IP6 0x86DD
#define AFTER_PROCESS 0
#define FRAGROUTE_DIR_BOTH 0
#define FRAGROUTE_DIR_C2S 1
#define FRAGROUTE_DIR_S2C 2

typedef enum {
    TCPR_DIR_C2S,
    TCPR_DIR_S2C,
    TCPR_DIR_NOSEND
} tcpr_dir_t;

typedef enum {
    TCPEDIT_ERROR,
    TCPEDIT_SOFT_ERROR,
    TCPEDIT_OK
} tcpedit_ret_t;

typedef struct {
    int verbose;
    void *cachedata;
    struct {
        char errbuf[256];
    } *frag_ctx;
    int fragroute_dir;
} options_t;

typedef struct pcap_pkthdr {
    int caplen;
    int len;
} pcap_pkthdr;

typedef struct pcap_t pcap_t;
typedef struct pcap_dumper_t pcap_dumper_t;
typedef struct tcpedit_t tcpedit_t;
typedef struct tcpdump_t tcpdump_t;

extern options_t options;
extern tcpdump_t tcpdump;
extern void *safe_malloc(size_t size);
extern tcpr_dir_t check_cache(void *cachedata, COUNTER packetnum);
extern int tcpedit_packet(tcpedit_t *tcpedit, struct pcap_pkthdr **pkthdr, u_char **pktdata, tcpr_dir_t direction);
extern int tcpedit_l3proto(tcpedit_t *tcpedit, int after_process, u_char *pktdata, int caplen);
extern void dbgx(int level, const char *fmt, ...);
extern void errx(int status, const char *fmt, ...);
extern int fragroute_process(void *ctx, u_char *pktdata, int caplen);
extern int fragroute_getfragment(void *ctx, char **frag);
extern const u_char *pcap_next(pcap_t *p, struct pcap_pkthdr *h);
extern void pcap_dump(u_char *user, const struct pcap_pkthdr *h, const u_char *sp);
extern void tcpdump_print(tcpdump_t *tcpdump, struct pcap_pkthdr *pkthdr, u_char *pktdata);