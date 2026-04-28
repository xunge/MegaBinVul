#include <stdint.h>
#include <stdbool.h>

typedef uint64_t hwaddr;

struct Vmxnet3_TxDesc {
    uint64_t addr;
    uint32_t len;
    bool eop;
};

#define VMXNET3_MAX_TX_BUF_SIZE 65536
#define VMXNET3_PKT_STATUS_ERROR 0

typedef struct VMXNET3State {
    bool skip_current_tx_pkt;
    bool tx_sop;
    bool needs_vlan;
    uint16_t tci;
    void *tx_pkt;
} VMXNET3State;

bool vmxnet3_pop_next_tx_descr(VMXNET3State *s, int qidx, struct Vmxnet3_TxDesc *txd, uint32_t *txd_idx);
void vmxnet3_dump_tx_descr(struct Vmxnet3_TxDesc *txd);
bool vmxnet_tx_pkt_add_raw_fragment(void *tx_pkt, hwaddr data_pa, uint32_t data_len);
void vmxnet3_tx_retrieve_metadata(VMXNET3State *s, struct Vmxnet3_TxDesc *txd);
bool vmxnet_tx_pkt_parse(void *tx_pkt);
void vmxnet_tx_pkt_setup_vlan_header(void *tx_pkt, uint16_t tci);
void vmxnet3_send_packet(VMXNET3State *s, int qidx);
void vmxnet3_on_tx_done_update_stats(VMXNET3State *s, int qidx, int status);
void vmxnet3_complete_packet(VMXNET3State *s, int qidx, uint32_t txd_idx);
void vmxnet_tx_pkt_reset(void *tx_pkt);

static inline uint64_t le64_to_cpu(uint64_t val) {
    return val;
}