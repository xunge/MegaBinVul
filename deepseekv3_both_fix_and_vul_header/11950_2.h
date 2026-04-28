#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define FLOWSPEC_NLRI_SIZELIMIT 240
#define FLOWSPEC_NLRI_SIZELIMIT_EXTENDED 4096
#define BGP_NLRI_PARSE_OK 0
#define BGP_NLRI_PARSE_ERROR_FLOWSPEC_NLRI_SIZELIMIT -1
#define BGP_NLRI_PARSE_ERROR_PACKET_OVERFLOW -2
#define BGP_NLRI_PARSE_ERROR_FLOWSPEC_BAD_FORMAT -3
#define AF_FLOWSPEC 1
#define FLOWSPEC 1
#define flowspec 1
#define BGP_FLOWSPEC_NLRI_STRING_MAX 1024
#define NLRI_STRING_FORMAT_MIN 0
#define ECOMMUNITY_FORMAT_ROUTE_MAP 0
#define ZEBRA_ROUTE_BGP 0
#define BGP_ROUTE_NORMAL 0
#define MTYPE_TMP 0
#define EC_BGP_FLOWSPEC_PACKET 0

typedef unsigned short afi_t;
typedef unsigned char safi_t;

struct peer;
struct attr;
struct bgp_nlri {
    uint8_t *nlri;
    unsigned int length;
    afi_t afi;
    safi_t safi;
};

struct prefix {
    unsigned short family;
    unsigned char prefixlen;
    union {
        struct {
            unsigned short prefixlen;
            unsigned short family;
            uintptr_t ptr;
        } prefix_flowspec;
    } u;
};

void *XCALLOC(int, size_t);
void flog_err(int, const char *, ...);
int bgp_fs_nlri_validate(uint8_t *, int, afi_t);
void bgp_fs_nlri_get_string(unsigned char *, int, char *, int, void *, afi_t);
void bgp_update(struct peer *, struct prefix *, int, struct attr *, afi_t, safi_t, int, int, void *, void *, int, int, void *);
void bgp_withdraw(struct peer *, struct prefix *, int, afi_t, safi_t, int, int, void *, void *, int, void *);
int BGP_DEBUG(int, int);
void zlog_info(const char *, ...);
char *ecommunity_ecom2str(void *, int, int);
void ecommunity_strfree(char **);
char *afi2str(afi_t);
unsigned short afi2family(afi_t);
void *bgp_attr_get_ecommunity(struct attr *);