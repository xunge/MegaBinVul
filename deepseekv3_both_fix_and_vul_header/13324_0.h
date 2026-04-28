#include <stddef.h>

typedef unsigned short dns_type_t;

struct dns_rr_nested {
    unsigned char *rr_start;
    unsigned char *rr_len_ptr;
    size_t rr_head_len;
    dns_type_t type;
    struct {
        unsigned char *ptr;
        struct dns_packet *packet;
    } context;
};

struct dns_packet;

int _dns_left_len(struct dns_rr_nested *rr_nested);
void _dns_write_short(unsigned char **ptr, int value);
int _dns_rr_add_end(struct dns_packet *packet, dns_type_t type, dns_type_t rtype, int len);