#include <stdbool.h>
#include <string.h>

struct ipt_ip {
    /* dummy empty structure since actual definition isn't available */
};

struct ipt_entry {
    unsigned int target_offset;
    struct ipt_ip ip;
};