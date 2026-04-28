#include <string.h>

typedef struct connection {
    int options;
    void *node;
} connection_t;

typedef struct vpn_packet {
    int len;
    int priority;
    char data[1024];
} vpn_packet_t;

#define OPTION_TCPONLY 1

void receive_packet(void *node, vpn_packet_t *pkt);