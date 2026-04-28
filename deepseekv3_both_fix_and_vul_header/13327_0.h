#include <stddef.h>

#define DNS_RR_AAAA_LEN 16
#define DNS_HTTPS_T_IPV6HINT 6

struct dns_rr_nested {
    void *context;
};

int _dns_left_len(void *context);
void dns_add_rr_nested_memcpy(struct dns_rr_nested *svcparam, const void *src, size_t n);