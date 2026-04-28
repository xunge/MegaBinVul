#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define TIME_NONE (struct timeval){0, 0}
#define DLT_PRISM_HEADER 119
#define DLT_IEEE802_11_RADIO 127
#define DLT_IEEE802_11 105
#define DLT_EN10MB 1
#define PRId64 "ld"

typedef unsigned char u_char;

struct pcap_pkthdr {
    struct timeval ts;
    uint32_t caplen;
    uint32_t len;
};

class WifipcapCallbacks {
public:
    virtual void PacketBegin(class WifiPacket& pkt, const u_char* packet, uint32_t caplen, uint32_t len) = 0;
    virtual void PacketEnd(class WifiPacket& pkt) = 0;
};

class WifiPacket {
public:
    WifiPacket(WifipcapCallbacks* cbs, int header_type, const struct pcap_pkthdr* header, const u_char* packet);
    void handle_prism(const u_char* packet, uint32_t caplen);
    void handle_radiotap(const u_char* packet, uint32_t caplen);
    void handle_80211(const u_char* packet, uint32_t caplen);
    void handle_ether(const u_char* packet, uint32_t caplen);
    void handle_ip(const u_char* packet, uint32_t caplen);
private:
    WifipcapCallbacks* cbs;
};

inline bool operator==(const struct timeval& t1, const struct timeval& t2) {
    return t1.tv_sec == t2.tv_sec && t1.tv_usec == t2.tv_usec;
}

struct timeval startTime = TIME_NONE;
struct timeval lastPrintTime = TIME_NONE;
int64_t packetsProcessed = 0;
bool verbose = false;

class Wifipcap {
public:
    static const int PRINT_TIME_INTERVAL;
    void handle_packet(WifipcapCallbacks* cbs, int header_type, 
                      const struct pcap_pkthdr* header, const u_char* packet);
};