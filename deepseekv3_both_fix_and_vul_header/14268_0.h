#include <stdint.h>
#include <string.h>

#define ONION_MAX_PACKET_SIZE 2048
#define CRYPTO_SHARED_KEY_SIZE 32
#define CRYPTO_NONCE_SIZE 24
#define CRYPTO_PUBLIC_KEY_SIZE 32
#define CRYPTO_MAC_SIZE 16
#define SEND_3 32
#define RETURN_2 32
#define RETURN_3 56
#define SIZE_IPPORT 18
#define NET_PACKET_ANNOUNCE_REQUEST 0
#define NET_PACKET_ONION_DATA_REQUEST 1

typedef struct {
    uint8_t shared_keys_3[CRYPTO_SHARED_KEY_SIZE];
    uint8_t secret_symmetric_key[CRYPTO_SHARED_KEY_SIZE];
    void *dht;
    void *net;
} Onion;

typedef struct {
    uint8_t ip[16];
    uint16_t port;
} IP_Port;

void change_symmetric_key(Onion *onion);
void get_shared_key(uint8_t (*shared_keys_3)[CRYPTO_SHARED_KEY_SIZE], uint8_t *shared_key, const uint8_t *secret_key, const uint8_t *public_key);
const uint8_t *dht_get_self_secret_key(void *dht);
int decrypt_data_symmetric(const uint8_t *shared_key, const uint8_t *nonce, const uint8_t *encrypted, uint16_t length, uint8_t *plain);
int ipport_unpack(IP_Port *target, const uint8_t *data, uint16_t length, int disable_family_check);
void ipport_pack(uint8_t *data, const IP_Port *ipport);
void random_nonce(uint8_t *nonce);
int encrypt_data_symmetric(const uint8_t *key, const uint8_t *nonce, const uint8_t *plain, uint16_t length, uint8_t *encrypted);
uint32_t sendpacket(void *net, IP_Port dest, const uint8_t *data, uint16_t length);