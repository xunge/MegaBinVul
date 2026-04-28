#include <stdint.h>

typedef struct IP_Port {
    struct {
        int family;
    } ip;
} IP_Port;

typedef struct Onion {
    uint8_t secret_symmetric_key[32];
    int (*recv_1_function)(void *, IP_Port, const uint8_t *, uint16_t);
    void *callback_object;
    void *net;
} Onion;

#define ONION_MAX_PACKET_SIZE 2048
#define RETURN_1 32
#define NET_PACKET_ANNOUNCE_RESPONSE 0x20
#define NET_PACKET_ONION_DATA_RESPONSE 0x21
#define SIZE_IPPORT 18
#define CRYPTO_NONCE_SIZE 24
#define CRYPTO_MAC_SIZE 16
#define TOX_AF_INET 2
#define TOX_AF_INET6 10

int change_symmetric_key(Onion *onion);
int decrypt_data_symmetric(const uint8_t *key, const uint8_t *nonce, const uint8_t *encrypted, uint32_t length, uint8_t *plain);
int ipport_unpack(IP_Port *target, const uint8_t *data, uint16_t data_length, int disable_family_check);
uint32_t sendpacket(void *net, IP_Port dest, const uint8_t *data, uint16_t length);