#include <stdbool.h>
#include <sys/uio.h>

#define NET_MAX_FRAG_SG_LIST 32
#define NET_TX_PKT_PL_START_FRAG 0
#define NET_TX_PKT_L2HDR_FRAG 0
#define NET_TX_PKT_L3HDR_FRAG 1
#define NET_TX_PKT_FRAGMENT_L2_HDR_POS 0
#define NET_TX_PKT_FRAGMENT_L3_HDR_POS 1

struct NetTxPkt {
    struct iovec *vec;
    size_t payload_len;
};

typedef struct NetClientState NetClientState;

size_t net_tx_pkt_fetch_fragment(struct NetTxPkt *pkt, int *src_idx, size_t *src_offset,
                                struct iovec *fragment, int *dst_idx);
void eth_setup_ip4_fragmentation(void *l2_iov_base, size_t l2_iov_len,
                                void *l3_iov_base, size_t l3_iov_len,
                                size_t fragment_len, size_t fragment_offset,
                                bool more_frags);
void eth_fix_ip4_checksum(void *l3_iov_base, size_t l3_iov_len);
void net_tx_pkt_sendv(struct NetTxPkt *pkt, NetClientState *nc,
                     struct iovec *fragment, int dst_idx);