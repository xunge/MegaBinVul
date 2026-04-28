#include <stdint.h>
#include <string.h>

#define ONION_MAX_PACKET_SIZE 1024
#define RETURN_3 32
#define RETURN_2 24
#define SIZE_IPPORT 18
#define CRYPTO_NONCE_SIZE 24
#define CRYPTO_MAC_SIZE 16
#define NET_PACKET_ANNOUNCE_RESPONSE 0x20
#define NET_PACKET_ONION_DATA_RESPONSE 0x21
#define NET_PACKET_ONION_RECV_2 0x22

typedef struct {
    uint8_t secret_symmetric_key[32];
    void *net;
} Onion;

typedef struct {
    uint8_t ip[16];
    uint16_t port;
} IP_Port;

int decrypt_data_symmetric(const uint8_t *key, const uint8_t *nonce, const uint8_t *encrypted, uint32_t length, uint8_t *plain);
int ipport_unpack(IP_Port *target, const uint8_t *data, uint16_t length, int disable_family_check);
uint32_t sendpacket(void *net, IP_Port dest, const uint8_t *data, uint16_t length);
void change_symmetric_key(Onion *onion);