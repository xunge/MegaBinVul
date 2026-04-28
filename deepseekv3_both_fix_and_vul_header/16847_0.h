#include <stddef.h>
#include <limits.h>

#define HTTP_IS_LWS(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')
#define unlikely(x) (x)
#define H1_MF_CLEN 0x01

struct ist {
    char *ptr;
    size_t len;
};

struct h1m {
    unsigned int flags;
    long long body_len;
    long long curr_len;
};

#define ULLONG_MAX (18446744073709551615ULL)