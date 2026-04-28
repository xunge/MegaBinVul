#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>
#include <netinet/in.h>

typedef uint32_t bgp_size_t;
typedef uint16_t afi_t;
typedef uint8_t safi_t;
typedef uint32_t mpls_label_t;

struct bgp;
struct peer;
struct stream;
struct attr;
struct bpacket_attr_vec_arr;
struct prefix;
struct prefix_rd;
struct aspath {
    void *segments;
};

#define CHECK_FLAG(flags, flag) ((flags) & (flag))
#define PEER_CAP_AS4_RCV 0
#define PEER_FLAG_AS_PATH_UNCHANGED 0
#define PEER_FLAG_RSERVER_CLIENT 0
#define PEER_FLAG_LOCAL_AS_REPLACE_AS 0
#define PEER_FLAG_SEND_COMMUNITY 0
#define PEER_FLAG_SEND_LARGE_COMMUNITY 0
#define PEER_FLAG_SEND_EXT_COMMUNITY 0
#define ECOMMUNITY_FLAG_NON_TRANSITIVE 0
#define BGP_CONFIG_CONFEDERATION 0
#define BGP_CONFIG_CLUSTER_ID 0
#define BGP_AS_TRANS 0
#define BGP_INVALID_LABEL_INDEX 0
#define ENABLE_BGP_VNC 0
#define BGP_ATTR_VEC_NH 0
#define BGP_LABEL_BYTES 3

#define AFI_IP 0
#define AFI_IP6 1
#define AFI_L2VPN 2
#define SAFI_UNICAST 0
#define SAFI_MPLS_VPN 1
#define SAFI_ENCAP 2
#define SAFI_LABELED_UNICAST 3
#define SAFI_EVPN 4

#define BGP_ATTR_FLAG_TRANS 0x40
#define BGP_ATTR_FLAG_EXTLEN 0x10
#define BGP_ATTR_FLAG_OPTIONAL 0x80
#define BGP_ATTR_ORIGIN 1
#define BGP_ATTR_AS_PATH 2
#define BGP_ATTR_NEXT_HOP 3
#define BGP_ATTR_MULTI_EXIT_DISC 4
#define BGP_ATTR_LOCAL_PREF 5
#define BGP_ATTR_ATOMIC_AGGREGATE 6
#define BGP_ATTR_AGGREGATOR 7
#define BGP_ATTR_COMMUNITIES 8
#define BGP_ATTR_LARGE_COMMUNITIES 9
#define BGP_ATTR_ORIGINATOR_ID 10
#define BGP_ATTR_CLUSTER_LIST 11
#define BGP_ATTR_EXT_COMMUNITIES 12
#define BGP_ATTR_PREFIX_SID 13
#define BGP_ATTR_AS4_PATH 14
#define BGP_ATTR_AS4_AGGREGATOR 15
#define BGP_ATTR_ENCAP 16
#define BGP_ATTR_VNC 17
#define BGP_ATTR_PMSI_TUNNEL 18

#define BGP_PEER_EBGP 0
#define BGP_PEER_IBGP 1
#define BGP_PEER_CONFED 2

#define BGP_PREFIX_SID_LABEL_INDEX 0
#define BGP_PREFIX_SID_LABEL_INDEX_LENGTH 0
#define PMSI_TNLTYPE_INGR_REPL 6

#define ATTR_FLAG_BIT(x) (1 << (x))

struct community {
    size_t size;
    uint8_t *val;
};

struct lcommunity {
    size_t size;
    uint8_t *val;
};

struct ecommunity {
    size_t size;
    uint8_t *val;
};

struct transit {
    size_t length;
    uint8_t *val;
};

struct cluster {
    size_t length;
    uint8_t *list;
};

struct attr {
    uint8_t origin;
    uint32_t flag;
    struct aspath *aspath;
    struct in_addr nexthop;
    uint32_t med;
    uint32_t local_pref;
    uint32_t aggregator_as;
    struct in_addr aggregator_addr;
    struct community *community;
    struct lcommunity *lcommunity;
    struct ecommunity *ecommunity;
    struct in_addr originator_id;
    struct cluster *cluster;
    struct transit *transit;
    uint32_t label_index;
    mpls_label_t label;
};

struct peer {
    struct bgp *bgp;
    uint32_t cap;
    uint32_t af_flags[3][5];
    int sort;
    uint32_t local_as;
    uint32_t change_local_as;
    uint32_t flags;
    struct in_addr remote_id;
    uint32_t af_safi_flags[3][5];
};

struct bgp {
    uint32_t config;
    uint32_t confed_id;
    uint32_t maxmed_active;
    uint32_t maxmed_value;
    struct in_addr cluster_id;
    struct in_addr router_id;
};

struct stream {
    size_t endp;
    uint8_t *data;
};

static size_t stream_get_endp(struct stream *s) { return s->endp; }
static void stream_putc(struct stream *s, uint8_t c) { }
static void stream_putw(struct stream *s, uint16_t w) { }
static void stream_putw_at(struct stream *s, size_t pos, uint16_t w) { }
static void stream_putl(struct stream *s, uint32_t l) { }
static void stream_put_ipv4(struct stream *s, uint32_t ip) { }
static void stream_put_in_addr(struct stream *s, struct in_addr *addr) { }
static void stream_put(struct stream *s, void *data, size_t len) { }

static int peer_cap_enhe(struct peer *peer, afi_t afi, safi_t safi) { return 0; }
static size_t bgp_packet_mpattr_start(struct stream *s, struct peer *peer, afi_t afi, safi_t safi, struct bpacket_attr_vec_arr *vecarr, struct attr *attr) { return 0; }
static void bgp_packet_mpattr_prefix(struct stream *s, afi_t afi, safi_t safi, struct prefix *p, struct prefix_rd *prd, mpls_label_t *label, uint32_t num_labels, int addpath_encode, uint32_t addpath_tx_id, struct attr *attr) { }
static void bgp_packet_mpattr_end(struct stream *s, size_t mpattrlen_pos) { }
static struct aspath *aspath_dup(struct aspath *aspath) { return NULL; }
static struct aspath *aspath_delete_confed_seq(struct aspath *aspath) { return NULL; }
static struct aspath *aspath_add_seq(struct aspath *aspath, uint32_t as) { return NULL; }
static struct aspath *aspath_add_confed_seq(struct aspath *aspath, uint32_t as) { return NULL; }
static int aspath_has_as4(struct aspath *aspath) { return 0; }
static size_t aspath_put(struct stream *s, struct aspath *aspath, int use32bit) { return 0; }
static void aspath_free(struct aspath *aspath) { }
static void bpacket_attr_vec_arr_set_vec(struct bpacket_attr_vec_arr *vecarr, int vec, struct stream *s, struct attr *attr) { }
static size_t lcom_length(struct lcommunity *lcommunity) { return 0; }
static void bgp_packet_mpattr_tea(struct bgp *bgp, struct peer *peer, struct stream *s, struct attr *attr, int type) { }