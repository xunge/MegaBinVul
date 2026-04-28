#include <stdint.h>
#include <string.h>

typedef unsigned char u_char;

typedef struct packet_t {
    int type;
} packet_t;

#define WH_OPCODE 0x0F
#define WH_MASK 0x80
#define WH_LEN 0x7F
#define WS_OPCODE_TEXT 0x01

#define PACKET_SIP_TLS 0
#define PACKET_SIP_WS 1
#define PACKET_SIP_WSS 2

uint32_t packet_payloadlen(packet_t *packet);
u_char *packet_payload(packet_t *packet);
void packet_set_payload(packet_t *packet, u_char *payload, uint32_t size);
void packet_set_type(packet_t *packet, int type);
void *sng_malloc(size_t size);
void sng_free(void *ptr);