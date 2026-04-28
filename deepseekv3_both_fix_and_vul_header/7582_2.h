#include <assert.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <sys/time.h>

typedef struct tcpedit_s tcpedit_t;

struct pcap_pkthdr {
    struct timeval ts;
    u_int32_t caplen;
    u_int32_t len;
};

struct ipv4_hdr_s {
    u_int8_t ip_v:4;
    u_int8_t ip_hl:4;
    u_int8_t ip_tos;
    u_int16_t ip_len;
    u_int16_t ip_id;
    u_int16_t ip_off;
    u_int8_t ip_ttl;
    u_int8_t ip_p;
    u_int16_t ip_sum;
    struct in_addr ip_src;
    struct in_addr ip_dst;
};
typedef struct ipv4_hdr_s ipv4_hdr_t;

#define TCPEDIT_OK 0
#define TCPEDIT_WARN 1
#define TCPEDIT_ERROR -1

#define IP_MF 0x2000
#define IP_OFFMASK 0x1fff

int tcpedit_setwarn(tcpedit_t *tcpedit, const char *format, ...);
int tcpedit_seterr(tcpedit_t *tcpedit, const char *format, ...);
int do_checksum(tcpedit_t *tcpedit, u_char *data, int proto, int len);