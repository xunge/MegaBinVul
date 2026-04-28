#include <stdint.h>
#include <sys/types.h>

typedef unsigned char u_char;

struct prism2_pkthdr {
    uint32_t host_time;
    uint32_t mac_time;
    uint32_t channel;
    uint32_t rssi;
    uint32_t sq;
    uint32_t signal;
    uint32_t noise;
    uint32_t rate;
    uint32_t istx;
};

class WifiPacket {
public:
    void handle_prism(const u_char *pc, size_t len);
    void handle_80211(const u_char *pc, size_t len);
};

class WifiCallbacks {
public:
    void HandlePrism(WifiPacket& packet, prism2_pkthdr* hdr, const u_char* data, size_t len);
};

extern WifiCallbacks* cbs;

#define EXTRACT_LE_32BITS(p) ((uint32_t)((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24)))