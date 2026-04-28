#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LEN 64
#define DNS_MAX_CNAME_LEN 256
#define DNS_RRS_END 4

enum {
    DNS_T_A = 1,
    DNS_T_NS = 2,
    DNS_T_CNAME = 5,
    DNS_T_SOA = 6,
    DNS_T_AAAA = 28,
    DNS_T_HTTPS = 65
};

enum {
    DNS_HTTPS_T_MANDATORY = 0,
    DNS_HTTPS_T_ALPN = 1,
    DNS_HTTPS_T_NO_DEFAULT_ALPN = 2,
    DNS_HTTPS_T_PORT = 3,
    DNS_HTTPS_T_IPV4HINT = 4,
    DNS_HTTPS_T_ECH = 5,
    DNS_HTTPS_T_IPV6HINT = 6
};

struct dns_packet;
struct dns_rrs {
    int type;
};

struct dns_soa {
    char mname[DNS_MAX_CNAME_LEN];
    char rname[DNS_MAX_CNAME_LEN];
    int serial;
    int refresh;
    int retry;
    int expire;
    int minimum;
};

struct dns_https_param {
    int key;
    int len;
    char *value;
    struct dns_https_param *next;
};

extern int dns_conf_force_no_cname;
extern struct dns_rrs *dns_get_rrs_start(struct dns_packet *packet, int section, int *count);
extern struct dns_rrs *dns_get_rrs_next(struct dns_packet *packet, struct dns_rrs *rrs);
extern int dns_get_A(struct dns_rrs *rrs, char *name, int len, int *ttl, unsigned char *addr);
extern int dns_get_AAAA(struct dns_rrs *rrs, char *name, int len, int *ttl, unsigned char *addr);
extern int dns_get_CNAME(struct dns_rrs *rrs, char *name, int len, int *ttl, char *cname, int cname_len);
extern int dns_get_SOA(struct dns_rrs *rrs, char *name, int len, int *ttl, struct dns_soa *soa);
extern struct dns_https_param *dns_get_HTTPS_svcparm(struct dns_rrs *rrs, char *name, int name_len, int *ttl, int *priority, char *target, int target_len);
extern struct dns_https_param *dns_get_HTTPS_svcparm_next(struct dns_rrs *rrs, struct dns_https_param *p);