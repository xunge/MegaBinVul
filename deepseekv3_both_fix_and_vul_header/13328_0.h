#include <string.h>

#define DNS_MAX_CNAME_LEN 255
#define DNS_T_HTTPS 65

typedef unsigned short dns_rr_type;

struct dns_rr_nested {
    struct {
        unsigned char *ptr;
    } context;
};

struct dns_packet;

struct dns_rr_nested *dns_add_rr_nested_start(struct dns_rr_nested *svcparam_buffer, struct dns_packet *packet, 
                                            dns_rr_type type, int https_type, const char *domain, int ttl);
int _dns_left_len(struct { unsigned char *ptr; } *context);
void _dns_write_short(unsigned char **ptr, int value);
void safe_strncpy(char *dest, const char *src, size_t n);