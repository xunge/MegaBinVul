#include <syslog.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

extern int proto_atoi(const char *protocol);
extern int check_upnp_rule_against_permissions(void *upnppermlist, int num_upnpperm, unsigned short eport, struct in_addr address, unsigned short iport);
extern int get_redirect_rule(const char *ext_if_name, unsigned short eport, int proto, char *iaddr_old, int iaddr_old_size, unsigned short *iport_old, int unused1, int unused2, char *rhost_old, int rhost_old_size, unsigned int *timestamp, int unused3, int unused4);
extern unsigned int upnp_time();
extern int update_portmapping(const char *ext_if_name, unsigned short eport, int proto, unsigned short iport, const char *desc, unsigned int timestamp);
extern int update_portmapping_desc_timestamp(const char *ext_if_name, unsigned short eport, int proto, const char *desc, unsigned int timestamp);
extern int upnp_redirect_internal(const char *rhost, unsigned short eport, const char *iaddr, unsigned short iport, int proto, const char *desc, unsigned int timestamp);
extern const char *ext_if_name;
extern void *upnppermlist;
extern int num_upnpperm;