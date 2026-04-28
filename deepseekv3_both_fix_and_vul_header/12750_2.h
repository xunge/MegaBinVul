#include <errno.h>
#include <sys/socket.h>

#define XFRM_MAX_DEPTH 6
#define IPSEC_LEVEL_USE 1
#define IPSEC_LEVEL_UNIQUE 2
#define IPSEC_MANUAL_REQID_MAX 0xffff
#define XFRM_MODE_TUNNEL 1

struct net;
struct xfrm_address_t {
    unsigned char data[16];
};

struct xfrm_id {
    struct xfrm_address_t daddr;
    unsigned short proto;
};

struct xfrm_tmpl {
    struct xfrm_id id;
    int mode;
    int optional;
    unsigned int reqid;
    struct xfrm_address_t saddr;
    unsigned short encap_family;
    int allalgs;
};

struct xfrm_policy {
    struct xfrm_tmpl *xfrm_vec;
    unsigned int xfrm_nr;
    unsigned short family;
    struct net *net;
};

struct sadb_x_ipsecrequest {
    unsigned short sadb_x_ipsecrequest_len;
    unsigned short sadb_x_ipsecrequest_proto;
    unsigned char sadb_x_ipsecrequest_mode;
    unsigned char sadb_x_ipsecrequest_level;
    unsigned int sadb_x_ipsecrequest_reqid;
};

static inline struct net *xp_net(struct xfrm_policy *xp) { return xp->net; }
static int pfkey_mode_to_xfrm(int mode) { return mode; }
static unsigned int gen_reqid(struct net *net) { return 0; }
static int parse_sockaddr_pair(struct sockaddr *sa, int len, 
                             struct xfrm_address_t *saddr, 
                             struct xfrm_address_t *daddr, 
                             unsigned short *family) { return 0; }