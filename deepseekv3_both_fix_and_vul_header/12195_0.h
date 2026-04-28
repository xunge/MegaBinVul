#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define FLOWSPEC_NLRI_SIZELIMIT 240
#define FLOWSPEC_NLRI_SIZELIMIT_EXTENDED 4096
#define BGP_NLRI_PARSE_ERROR_FLOWSPEC_NLRI_SIZELIMIT 1
#define BGP_NLRI_PARSE_ERROR_PACKET_OVERFLOW 2
#define BGP_NLRI_PARSE_ERROR_FLOWSPEC_BAD_FORMAT 3
#define BGP_NLRI_PARSE_OK 0
#define AF_FLOWSPEC 1
#define BGP_FLOWSPEC_NLRI_STRING_MAX 512
#define NLRI_STRING_FORMAT_MIN 0
#define ECOMMUNITY_FORMAT_ROUTE_MAP 0
#define ZEBRA_ROUTE_BGP 0
#define BGP_ROUTE_NORMAL 0
#define MTYPE_TMP 0
#define EC_BGP_FLOWSPEC_PACKET 0

typedef uint16_t afi_t;
typedef uint8_t safi_t;

struct peer;
struct attr;
struct bgp_nlri {
    uint8_t *nlri;
    uint16_t length;
    afi_t afi;
    safi_t safi;
};

struct prefix {
    uint16_t family;
    uint8_t prefixlen;
    union {
        struct {
            uint16_t prefixlen;
            uint16_t family;
            uintptr_t ptr;
        } prefix_flowspec;
    } u;
};

struct ecommunity;

void *XCALLOC(int mtype, size_t size);
void flog_err(int ec, const char *format, ...);
int bgp_fs_nlri_validate(uint8_t *pnt, int psize, afi_t afi);
uint16_t afi2family(afi_t afi);
void bgp_fs_nlri_get_string(unsigned char *ptr, int prefixlen, char *return_string, int format, void *null, afi_t afi);
char *ecommunity_ecom2str(struct ecommunity *ecom, int format, int json);
void ecommunity_strfree(char **s);
void zlog_info(const char *format, ...);
void bgp_update(struct peer *peer, struct prefix *p, int i, struct attr *attr, afi_t afi, safi_t safi, int zebra_route_bgp, int bgp_route_normal, void *null1, void *null2, int i1, int i2, void *null3);
void bgp_withdraw(struct peer *peer, struct prefix *p, int i, afi_t afi, safi_t safi, int zebra_route_bgp, int bgp_route_normal, void *null1, void *null2, int i1, void *null3);
struct ecommunity *bgp_attr_get_ecommunity(struct attr *attr);
char *afi2str(afi_t afi);
#define BGP_DEBUG(type, subtype) 0