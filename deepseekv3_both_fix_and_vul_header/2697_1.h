#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef unsigned char u_char;
typedef unsigned int u_int;

struct pkt_id {
    struct {
        uint32_t slot;
        struct {
            uint32_t p_sid;
            uint32_t p_uid;
        } page;
        uint16_t nid;
    } pi_ps;
    uint32_t pi_mslot;
    struct {
        uint32_t p_sid;
        uint32_t p_uid;
    } pi_mpage;
};

struct id_off {
    uint32_t id;
    uint32_t off;
};

typedef struct netdissect_options netdissect_options;

#define ND_TTEST(ptr) 1
#define ND_TTEST2(ptr, len) 1
#define ND_PRINT(args) printf args
#define EXTRACT_16BITS(p) ntohs(*(const uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(const uint32_t *)(p))

const char *ipaddr_string(netdissect_options *ndo, const uint32_t *addr);
void fn_print(netdissect_options *ndo, const u_char *cp, const u_char *ep);