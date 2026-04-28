#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

struct dhcp6opt {
    uint16_t dh6opt_type;
    uint16_t dh6opt_len;
};

#define DH6OPT_CLIENTID 1
#define DH6OPT_SERVERID 2
#define DH6OPT_IA_NA 3
#define DH6OPT_IA_TA 4
#define DH6OPT_IA_ADDR 5
#define DH6OPT_ORO 6
#define DH6OPT_PREFERENCE 7
#define DH6OPT_ELAPSED_TIME 8
#define DH6OPT_RELAY_MSG 9
#define DH6OPT_AUTH 11
#define DH6OPT_UNICAST 12
#define DH6OPT_STATUS_CODE 13
#define DH6OPT_RAPID_COMMIT 14
#define DH6OPT_USER_CLASS 15
#define DH6OPT_VENDOR_CLASS 16
#define DH6OPT_VENDOR_OPTS 17
#define DH6OPT_INTERFACE_ID 18
#define DH6OPT_RECONF_MSG 19
#define DH6OPT_RECONF_ACCEPT 20
#define DH6OPT_SIP_SERVER_D 21
#define DH6OPT_SIP_SERVER_A 22
#define DH6OPT_DNS_SERVERS 23
#define DH6OPT_DOMAIN_LIST 24
#define DH6OPT_IA_PD 25
#define DH6OPT_IA_PD_PREFIX 26
#define DH6OPT_SNTP_SERVERS 31
#define DH6OPT_INFORMATION_REFRESH_TIME 32
#define DH6OPT_BCMCS_SERVER_D 33
#define DH6OPT_BCMCS_SERVER_A 34
#define DH6OPT_GEOCONF_CIVIC 36
#define DH6OPT_REMOTE_ID 37
#define DH6OPT_SUBSCRIBER_ID 38
#define DH6OPT_CLIENT_FQDN 39
#define DH6OPT_PANA_AGENT 40
#define DH6OPT_NEW_POSIX_TIMEZONE 41
#define DH6OPT_NEW_TZDB_TIMEZONE 42
#define DH6OPT_ERO 43
#define DH6OPT_LQ_QUERY 44
#define DH6OPT_CLIENT_DATA 45
#define DH6OPT_CLT_TIME 46
#define DH6OPT_LQ_RELAY_DATA 47
#define DH6OPT_LQ_CLIENT_LINK 48
#define DH6OPT_MUDURL 89
#define DH6OPT_V6_PCP_SERVER 90
#define DH6OPT_V6_PORTPARAMS 91
#define DH6OPT_CAPTIVE_PORTAL 92
#define DH6OPT_NTP_SERVER 99
#define DH6OPT_AFTR_NAME 64
#define DH6OPT_NIS_SERVERS 27
#define DH6OPT_NISP_SERVERS 28
#define DH6OPT_LIFETIME 29

#define DH6OPT_AUTHPROTO_DELAYED 2
#define DH6OPT_AUTHPROTO_RECONFIG 3
#define DH6OPT_AUTHALG_HMACMD5 1
#define DH6OPT_AUTHRDM_MONOCOUNTER 0
#define DH6OPT_AUTHRECONFIG_KEY 1
#define DH6OPT_AUTHRECONFIG_HMACMD5 2

#define DH6OPT_NTP_SUBOPTION_SRV_ADDR 1
#define DH6OPT_NTP_SUBOPTION_MC_ADDR 2
#define DH6OPT_NTP_SUBOPTION_SRV_FQDN 3

#define DH6_RENEW 5
#define DH6_INFORM_REQ 6

#define EXTRACT_16BITS(p) ((uint16_t)ntohs(*(const uint16_t *)(p)))
#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))

typedef struct netdissect_options netdissect_options;

extern const char *dhcp6stcode(uint16_t);
extern const char *tok2str(const char *, const char *, uint16_t);
extern const char *ip6addr_string(netdissect_options *, const u_char *);
extern const u_char *ns_nprint(netdissect_options *, const u_char *, const u_char *);
extern void dhcp6_print(netdissect_options *, const u_char *, u_int);
extern void fn_printn(netdissect_options *, const u_char *, u_int, const char *);

#define ND_TCHECK(p) 
#define ND_TCHECK2(p, l) 
#define ND_PRINT(args)