#include <cstdint>
#include <iostream>

struct RawAddress {
};

enum EattChannelState {
  EATT_CHANNEL_OPENED
};

struct tL2CAP_LE_CFG_INFO {
  uint16_t result;
  uint16_t mtu;
};

#define L2CAP_CFG_OK 0

class EattChannel {
 public:
  void EattChannelSetState(EattChannelState state) {}
  void EattChannelSetTxMTU(uint16_t mtu) { tx_mtu_ = mtu; }
  uint16_t rx_mtu_;
  uint16_t tx_mtu_;
};

EattChannel* find_channel_by_cid(const RawAddress& bda, uint16_t lcid) {
  return nullptr;
}

#define LOG(level) std::cout
#define INFO 0
#define loghex(x) x