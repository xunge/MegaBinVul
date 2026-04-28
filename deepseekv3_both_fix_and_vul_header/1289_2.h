#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pthread.h>
#include <arpa/inet.h>

typedef uint16_t ovs_be16;
typedef uint32_t ovs_be32;

struct dp_packet;
struct dp_packet_batch;

struct ipf {
    pthread_mutex_t ipf_lock;
};

#define ETH_TYPE_IP 0x0800
#define ETH_TYPE_IPV6 0x86DD

#define OVS_UNLIKELY(condition) (condition)

#define DP_PACKET_BATCH_REFILL_FOR_EACH(IDX, CNT, PKT, BATCH) \
    for (size_t IDX = 0; IDX < CNT && ((PKT) = dp_packet_batch_at(BATCH, IDX)); IDX++)

static inline size_t dp_packet_batch_size(const struct dp_packet_batch *batch);
static inline struct dp_packet *dp_packet_batch_at(struct dp_packet_batch *batch, size_t idx);
static inline void dp_packet_batch_refill(struct dp_packet_batch *batch, struct dp_packet *pkt, size_t idx);

static inline bool ipf_is_valid_v4_frag(struct ipf *ipf, struct dp_packet *pkt);
static inline bool ipf_is_valid_v6_frag(struct ipf *ipf, struct dp_packet *pkt);
static inline bool ipf_handle_frag(struct ipf *ipf, struct dp_packet *pkt, ovs_be16 dl_type, uint16_t zone, long long now, uint32_t hash_basis);

static inline void ovs_mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static inline void ovs_mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }