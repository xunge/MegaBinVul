#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <inttypes.h>

#define BUNDLE_MAX_SLAVES 128
#define OFPP_MAX 0xff00
#define NX_BD_ALG_HRW 0
#define NX_BD_ALG_ACTIVE_BACKUP 1

typedef uint16_t ofp_port_t;
typedef uint32_t ovs_be32;
typedef uint16_t ovs_be16;

enum ofperr {
    OFPERR_OFPBAC_BAD_ARGUMENT,
    OFPERR_OFPBAC_BAD_LEN
};

enum mf_field_id {
    MFF_IN_PORT
};

struct nx_action_bundle {
    ovs_be16 n_slaves;
    ovs_be16 basis;
    ovs_be16 fields;
    ovs_be16 algorithm;
    ovs_be32 slave_type;
    ovs_be16 len;
    uint8_t zero[6];
    ovs_be16 ofs_nbits;
    ovs_be32 dst;
};

struct vl_mff_map;

struct ofpbuf {
    void *header;
    void *data;
    size_t size;
};

struct ofpact_bundle {
    ofp_port_t *slaves;
    uint16_t n_slaves;
    uint16_t basis;
    uint16_t fields;
    uint16_t algorithm;
    struct {
        enum mf_field_id field;
        uint8_t ofs;
        uint8_t n_bits;
    } dst;
};

struct vlog_rate_limit {
    unsigned int interval;
    unsigned int burst;
};

#define VLOG_RATE_LIMIT_INIT(interval, burst) {interval, burst}
#define VLOG_WARN_RL(limit, ...) 

static inline bool flow_hash_fields_valid(uint16_t fields) { return true; }
static inline bool is_all_zeros(const uint8_t *data, size_t len) { return true; }
static inline uint8_t nxm_decode_ofs(ovs_be16 ofs_nbits) { return 0; }
static inline uint8_t nxm_decode_n_bits(ovs_be16 ofs_nbits) { return 0; }
static inline uint32_t mf_nxm_header(enum mf_field_id id) { return 0; }
static inline ofp_port_t u16_to_ofp(uint16_t port) { return port; }
static inline enum ofperr mf_vl_mff_mf_from_nxm_header(uint32_t header, const struct vl_mff_map *vl_mff_map, enum mf_field_id *field, uint64_t *tlv_bitmap) { return 0; }
static inline struct ofpact_bundle *ofpact_put_BUNDLE(struct ofpbuf *ofpacts) { return (struct ofpact_bundle *)ofpacts->header; }
static inline void ofpact_finish_BUNDLE(struct ofpbuf *ofpacts, struct ofpact_bundle **bundle) {}
static inline enum ofperr bundle_check(struct ofpact_bundle *bundle, ofp_port_t max_port, const char **port_name) { return 0; }
static inline void ofpbuf_put(struct ofpbuf *ofpacts, const void *data, size_t size) {}