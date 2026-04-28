#include <stdint.h>
#include <assert.h>
#include <stddef.h>

typedef struct AvahiServer {
    struct {
        int enable_reflector;
        int check_response_ttl;
    } config;
    void *monitor;
} AvahiServer;

typedef struct AvahiDnsPacket AvahiDnsPacket;

typedef struct AvahiAddress {
    int proto;
} AvahiAddress;

typedef struct AvahiInterface {
    int announcing;
    struct {
        char *name;
    } *hardware;
    int protocol;
} AvahiInterface;

typedef int AvahiIfIndex;

#define AVAHI_MDNS_PORT 5353
#define AVAHI_ADDRESS_STR_MAX 64
#define AVAHI_DNS_FIELD_ANCOUNT 0
#define AVAHI_DNS_FIELD_NSCOUNT 1
#define AVAHI_DNS_FIELD_QDCOUNT 2

int avahi_dns_packet_check_valid_multicast(AvahiDnsPacket *p);
int avahi_dns_packet_is_query(AvahiDnsPacket *p);
int avahi_dns_packet_get_field(AvahiDnsPacket *p, int field);
int originates_from_local_legacy_unicast_socket(AvahiServer *s, const AvahiAddress *src_address, uint16_t port);
int originates_from_local_iface(AvahiServer *s, AvahiIfIndex iface, const AvahiAddress *src_address, uint16_t port);
int avahi_address_is_ipv4_in_ipv6(const AvahiAddress *a);
char *avahi_address_snprint(char *s, size_t l, const AvahiAddress *a);
AvahiInterface *avahi_interface_monitor_get_interface(AvahiServer *s, AvahiIfIndex iface, int proto);
int is_mdns_mcast_address(const AvahiAddress *a);
int avahi_interface_address_on_link(AvahiInterface *i, const AvahiAddress *a);
void avahi_log_debug(const char *fmt, ...);
void handle_query_packet(AvahiServer *s, AvahiDnsPacket *p, AvahiInterface *i, const AvahiAddress *src_address, uint16_t port, int legacy_unicast, int from_local_iface);
void handle_response_packet(AvahiServer *s, AvahiDnsPacket *p, AvahiInterface *i, const AvahiAddress *src_address, int from_local_iface);
void reflect_legacy_unicast_query_packet(AvahiServer *s, AvahiDnsPacket *p, AvahiInterface *i, const AvahiAddress *src_address, uint16_t port);