#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <stdint.h>
#include <string.h>

typedef struct netdissect_options netdissect_options;

struct sunrpc_msg {
    struct {
        uint32_t cb_vers;
        uint32_t cb_proc;
    } rm_call;
    uint32_t rm_xid;
};

struct xid_map_entry {
    uint32_t xid;
    int ipver;
    union {
        struct in_addr client4;
        struct in6_addr client6;
    } client;
    union {
        struct in_addr server4;
        struct in6_addr server6;
    } server;
    uint32_t proc;
    uint32_t vers;
};

#define ND_TTEST(p) (1)
#define EXTRACT_32BITS(p) (*(uint32_t*)(p))
#define UNALIGNED_MEMCPY(dst, src, size) memcpy(dst, src, size)
#define IP_V(ip) ((ip)->ip_v)

#define XIDMAPSIZE 1024
static struct xid_map_entry xid_map[XIDMAPSIZE];
static unsigned int xid_map_next = 0;