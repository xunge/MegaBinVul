#include <assert.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define MAXPACKET 65536
#define COUNTER uint64_t
#define COUNTER_SPEC "%" PRIu64

typedef unsigned char u_char;

typedef struct pcap_pkthdr {
    uint32_t caplen;
    // other members omitted for brevity
} pcap_pkthdr;

typedef struct pcap_t {
    // dummy definition since we can't include pcap.h
} pcap_t;

typedef enum {
    TCPR_DIR_ERROR,
    TCPR_DIR_C2S,
    TCPR_DIR_S2C,
    DIR_UNKNOWN,
    DIR_SERVER,
    DIR_CLIENT
} tcpr_dir_t;

typedef enum {
    MAC_MODE,
    AUTO_MODE,
    REGEX_MODE,
    CIDR_MODE,
    ROUTER_MODE,
    BRIDGE_MODE,
    SERVER_MODE,
    CLIENT_MODE,
    PORT_MODE,
    FIRST_MODE
} tcpprep_mode_t;

typedef enum {
    xXExclude
} xX_mode_t;

typedef struct {
    tcpprep_mode_t mode;
    xX_mode_t xX_mode;
    void *xX_list;
    void *xX_cidr;
    void *cachedata;
    void *cidrdata;
    void *maclist;
    int nonip;
    int automode;
    int verbose;
    struct {
        int mode;
        void *list;
        void *cidr;
    } xX;
} tcpprep_opt_t;

typedef struct {
    tcpprep_opt_t *options;
    void *tcpdump;
} tcpprep_t;

typedef struct {
    uint8_t ether_shost[6];
} eth_hdr_t;

typedef struct {
    struct {
        uint32_t s_addr;
    } ip_src;
} ipv4_hdr_t;

typedef struct in6_addr {
    uint8_t s6_addr[16];
} in6_addr;

typedef struct {
    struct in6_addr ip_src;
} ipv6_hdr_t;

extern tcpprep_t *tcpprep;
#define HAVE_OPT(x) 0
#define DONT_SEND 0
#define SEND 1
#define ENABLE_VERBOSE 0

static void dbg(int level, const char *fmt, ...);
static void dbgx(int level, const char *fmt, ...);
static void errx(int code, const char *fmt, ...);
static int check_list(void *list, COUNTER packetnum);
static void add_cache(void **cachedata, int send, tcpr_dir_t direction);
static ipv4_hdr_t *get_ipv4(const u_char *pktdata, int caplen, int datalink, u_char **buffptr);
static ipv6_hdr_t *get_ipv6(const u_char *pktdata, int caplen, int datalink, u_char **buffptr);
static int get_l2len(const u_char *pktdata, int caplen, int datalink);
static int process_xX_by_cidr_ipv4(xX_mode_t mode, void *cidr, ipv4_hdr_t *ip_hdr);
static int process_xX_by_cidr_ipv6(xX_mode_t mode, void *cidr, ipv6_hdr_t *ip6_hdr);
static tcpr_dir_t check_ipv4_regex(uint32_t ip_src);
static tcpr_dir_t check_ipv6_regex(struct in6_addr *ip_src);
static int check_ip_cidr(void *cidrdata, uint32_t ip_src);
static int check_ip6_cidr(void *cidrdata, struct in6_addr *ip_src);
static tcpr_dir_t macinstring(void *maclist, u_char *ether_shost);
static void add_tree_ipv4(uint32_t ip_src, const u_char *pktdata, int caplen);
static void add_tree_ipv6(struct in6_addr *ip_src, const u_char *pktdata, int caplen);
static void add_tree_first_ipv4(const u_char *pktdata, int caplen);
static void add_tree_first_ipv6(const u_char *pktdata, int caplen);
static tcpr_dir_t check_ip_tree(tcpr_dir_t default_dir, uint32_t ip_src);
static tcpr_dir_t check_ip6_tree(tcpr_dir_t default_dir, struct in6_addr *ip_src);
static tcpr_dir_t check_dst_port(ipv4_hdr_t *ip_hdr, ipv6_hdr_t *ip6_hdr, int len);
static void tcpdump_print(void *tcpdump, struct pcap_pkthdr *pkthdr, const u_char *pktdata);