#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;
typedef int64_t atomic64_t;

#define NETDEV_TX_OK 0
#define NETDEV_TX_BUSY 1
#define FALLBACK 1
#define TLS_CIPHER_AES_GCM_128_TAG_SIZE 16

#define unlikely(x) __builtin_expect(!!(x), 0)
#define pr_debug(fmt, ...)

struct sk_buff {
    unsigned int len;
    void *sk;
    unsigned int queue_mapping;
};

struct net_device {};

struct tcphdr {
    uint32_t seq;
    uint32_t ack_seq;
    uint16_t window;
    uint8_t fin;
    uint8_t psh;
};

struct skb_shared_info {
    unsigned short gso_size;
};

struct tls_record_info {
    uint32_t end_seq;
    uint32_t len;
    int num_frags;
    struct skb_frag_struct *frags;
};

struct skb_frag_struct {
    void *page;
};

struct tls_context {
    struct net_device *netdev;
};

struct ch_ktls_stats_debug {
    struct ch_ktls_port_stats_debug *ktls_port;
};

struct ch_ktls_port_stats_debug {
    atomic64_t ktls_tx_drop_no_sync_data;
    atomic64_t ktls_tx_skip_no_sync_data;
    atomic64_t ktls_tx_encrypted_packets;
    atomic64_t ktls_tx_encrypted_bytes;
};

struct adapter {
    struct {
        struct {
            struct sge_eth_txq *ethtxq;
        } sge;
        struct ch_ktls_stats_debug ch_ktls_stats;
    };
};

struct sge_eth_txq {
    void *q;
};

struct chcr_ktls_ofld_ctx_tx {
    struct {
        int lock;
    } base;
    struct chcr_ktls_info *chcr_info;
};

struct chcr_ktls_info {
    struct adapter *adap;
    unsigned int port_id;
    unsigned int first_qset;
    unsigned int tx_chan;
    uint32_t prev_seq;
    uint32_t record_no;
};

static inline uint32_t ntohl(uint32_t netlong) { return netlong; }
static inline uint16_t ntohs(uint16_t netshort) { return netshort; }
static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}
static inline void atomic64_inc(atomic64_t *v) {}
static inline void atomic64_add(long long i, atomic64_t *v) {}
static inline void __skb_frag_ref(struct skb_frag_struct *frag) {}
static inline void __skb_frag_unref(struct skb_frag_struct *frag) {}
static inline void dev_kfree_skb_any(struct sk_buff *skb) {}
static inline void skb_get(struct sk_buff *skb) {}
static inline struct tcphdr *tcp_hdr(const struct sk_buff *skb) { return NULL; }
static inline unsigned int skb_transport_offset(const struct sk_buff *skb) { return 0; }
static inline unsigned int tcp_hdrlen(const struct sk_buff *skb) { return 0; }
static inline bool skb_is_gso(const struct sk_buff *skb) { return false; }
static inline struct skb_shared_info *skb_shinfo(const struct sk_buff *skb) { return NULL; }
static inline struct tls_context *tls_get_ctx(void *sk) { return NULL; }
static inline struct chcr_ktls_ofld_ctx_tx *chcr_get_ktls_tx_context(struct tls_context *ctx) { return NULL; }
static inline void cxgb4_reclaim_completed_tx(struct adapter *adap, void *q, bool b) {}
static inline bool chcr_ktls_check_tcp_options(struct tcphdr *th) { return false; }
static inline int chcr_ktls_write_tcp_options(struct chcr_ktls_info *tx_info, struct sk_buff *skb, struct sge_eth_txq *q, unsigned int chan) { return 0; }
static inline bool tls_record_is_start_marker(struct tls_record_info *record) { return false; }
static inline int chcr_ktls_xmit_tcb_cpls(struct chcr_ktls_info *tx_info, struct sge_eth_txq *q, uint32_t tx_max, uint32_t ack_seq, uint16_t window, bool b) { return 0; }
static inline int chcr_ktls_tx_plaintxt(struct chcr_ktls_info *tx_info, struct sk_buff *skb, uint32_t seq, int mss, bool push, struct sge_eth_txq *q, unsigned int port_id, void *null, uint32_t end_offset, unsigned int skb_offset, int zero) { return 0; }
static inline int chcr_end_part_handler(struct chcr_ktls_info *tx_info, struct sk_buff *skb, struct tls_record_info *record, uint32_t seq, int mss, bool push, struct sge_eth_txq *q, unsigned int skb_offset, uint32_t end_offset, bool b) { return 0; }
static inline int chcr_short_record_handler(struct chcr_ktls_info *tx_info, struct sk_buff *skb, struct tls_record_info *record, uint32_t seq, int mss, bool push, int data_len, unsigned int skb_offset, struct sge_eth_txq *q, uint32_t end_offset) { return 0; }
static inline int chcr_ktls_sw_fallback(struct sk_buff *skb, struct chcr_ktls_info *tx_info, struct sge_eth_txq *q) { return 0; }
static inline void WARN_ON(bool condition) {}
static inline struct tls_record_info *tls_get_record(void *base, uint32_t seq, uint32_t *record_no) { return NULL; }