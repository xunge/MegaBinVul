#include <stdint.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct netdissect_options netdissect_options;

struct lsa6_hdr {
    uint16_t ls_age;
    uint16_t ls_type;
    uint32_t ls_seq;
    struct in6_addr ls_router;
    struct in6_addr ls_stateid;
    uint16_t ls_length;
};

#define ND_TCHECK(p)
#define ND_PRINT(args)
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))