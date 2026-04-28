#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <errno.h>
#include <net/ethernet.h>

#define _U_
#define SENDPACKET_ERRBUF_SIZE 256
#define ENABLE_PCAP_FINDALLDEVS
#define DEBUG
#define ENABLE_VERBOSE
#define HAVE_OPT(x) 0
#define OPT_VALUE_DBUG 0
#define OPT_ARG(x) ""
#define OPT_VALUE_LIMIT 0
#define STACKCT_OPT(x) 0
#define STACKLST_OPT(x) NULL
#define TCPR_DIR_C2S 0
#define TCPR_DIR_S2C 1
#define SP_TYPE_NONE 0

struct tcpr_ether_addr {
    u_char addr[ETH_ALEN];
};

typedef struct {
    int verbose;
    char *args;
    int unidir;
    int limit_send;
    char *intf1;
    char *intf2;
    u_char intf1_mac[ETH_ALEN];
    u_char intf2_mac[ETH_ALEN];
    void *pcap1;
    void *pcap2;
    int snaplen;
    int promisc;
    int to_ms;
    int poll_timeout;
    struct {
        char *args;
    } *tcpdump;
} options_t;

typedef struct {
    // Define interface_list_t structure members here
} interface_list_t;

typedef struct {
    // Define sendpacket_t structure members here
} sendpacket_t;

extern options_t options;
extern int debug;

interface_list_t *get_interface_list(void);
char *get_interface(interface_list_t *intlist, const char *name);
void mac2hex(const char *mac, u_char *hex, int len);
sendpacket_t *sendpacket_open(const char *intf, char *ebuf, int dir, int type, void *arg);
struct tcpr_ether_addr *sendpacket_get_hwaddr(sendpacket_t *sp);
const char *sendpacket_geterr(sendpacket_t *sp);
void sendpacket_close(sendpacket_t *sp);
void *pcap_open_live(const char *device, int snaplen, int promisc, int to_ms, char *errbuf);
char *safe_strdup(const char *s);
void safe_free(void *ptr);
void warn(const char *fmt, ...);
void warnx(const char *fmt, ...);
void err(int eval, const char *fmt, ...);
void errx(int eval, const char *fmt, ...);