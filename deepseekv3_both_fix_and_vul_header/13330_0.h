#include <string.h>

struct dns_rr_nested {
    struct {
        void *ptr;
    } context;
};

int _dns_left_len(struct dns_rr_nested *rr_nested);