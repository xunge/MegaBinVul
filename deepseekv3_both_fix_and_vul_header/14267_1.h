#include <stdint.h>
#include <string.h>

typedef struct {
    // Define IP_Port structure members here
} IP_Port;

typedef struct {
    // Define Onion structure members here
    uint8_t secret_symmetric_key[32];  // CRYPTO_SYMMETRIC_KEY_SIZE = 32
    void *net;
} Onion;

#define ONION_MAX_PACKET_SIZE 2048
#define RETURN_1 32
#define RETURN_2 32
#define SIZE_IPPORT 18
#define CRYPTO_NONCE_SIZE 24
#define CRYPTO_MAC_SIZE 16

#define NET_PACKET_ANNOUNCE_RESPONSE 0x20
#define NET_PACKET_ONION_DATA_RESPONSE 0x21
#define NET_PACKET_ONION_RECV_1 0x22

int decrypt_data_symmetric(const uint8_t *key, const uint8_t *nonce, const uint8_t *encrypted, uint16_t length, uint8_t *plain);
int ipport_unpack(IP_Port *target, const uint8_t *data, uint16_t length, int disable_family_check);
uint32_t sendpacket(void *net, IP_Port dest, const uint8_t *data, uint16_t length);
void change_symmetric_key(Onion *onion);