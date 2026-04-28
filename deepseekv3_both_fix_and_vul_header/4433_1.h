#include <stdbool.h>
#include <string.h>

struct ip6t_ip6 {
    /* dummy empty structure */
};

struct ip6t_entry {
    unsigned int target_offset;
    struct ip6t_ip6 ipv6;
};