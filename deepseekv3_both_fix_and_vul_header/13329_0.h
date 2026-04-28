#include <stddef.h>

#define DNS_RR_A_LEN 4
#define DNS_HTTPS_T_IPV4HINT 4

struct dns_rr_nested {
    void *context;
};

int _dns_left_len(void *context);
void dns_add_rr_nested_memcpy(struct dns_rr_nested *svcparam, void *data, size_t len);