#include <stddef.h>

struct sixpack {
    unsigned char *raw_buf;
    unsigned char *cooked_buf;
    int rx_count;
    int rx_count_cooked;
};