#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

typedef int32_t pj_status_t;
typedef uint8_t pj_uint8_t;

typedef struct {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct {
    pj_str_t name;
    uint16_t type;
    uint16_t dnsclass;
    uint32_t ttl;
    uint16_t rdlength;
    union {
        struct {
            uint32_t ip_addr;
        } a;
        struct {
            uint8_t ip_addr[16];
        } aaaa;
        struct {
            pj_str_t name;
        } cname;
        struct {
            uint16_t prio;
            uint16_t weight;
            uint16_t port;
            pj_str_t target;
        } srv;
    } rdata;
    void *data;
} pj_dns_parsed_rr;

typedef struct pj_pool_t pj_pool_t;

#define PJ_SUCCESS 0
#define PJLIB_UTIL_EDNSINSIZE (-1)
#define PJLIB_UTIL_EDNSINCLASS (-2)

#define PJ_DNS_TYPE_A 1
#define PJ_DNS_TYPE_AAAA 28
#define PJ_DNS_TYPE_CNAME 5
#define PJ_DNS_TYPE_NS 2
#define PJ_DNS_TYPE_PTR 12
#define PJ_DNS_TYPE_SRV 33

static pj_status_t get_name_len(int flags, const pj_uint8_t *pkt,
                               const pj_uint8_t *start, const pj_uint8_t *max,
                               int *name_part_len, int *name_len);
static pj_status_t get_name(int flags, const pj_uint8_t *pkt,
                           const pj_uint8_t *start, const pj_uint8_t *max,
                           pj_str_t *name);