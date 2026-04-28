#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define ARES_SUCCESS 0
#define ARES_EBADSTR 1
#define ARES_ENOMEM 2

#define PATTERN_CIDR 1
#define PATTERN_MASK 2

#define ISSPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')

struct apattern {
    int type;
    int family;
    union {
        struct in6_addr addrV6;
        struct in_addr addrV4;
    };
    union {
        unsigned short bits;
        struct in_addr addr4;
    } mask;
};