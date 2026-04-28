#include <stdint.h>
#include <stddef.h>

typedef struct fastd_socket_t fastd_socket_t;
typedef struct fastd_peer_address_t fastd_peer_address_t;
typedef struct fastd_buffer_t {
    uint8_t *data;
} fastd_buffer_t;

#define PACKET_DATA 0
#define PACKET_HANDSHAKE 1

extern int backoff_unknown(const fastd_peer_address_t *addr);
extern void pr_debug(const char *fmt, ...);
extern void fastd_buffer_free(fastd_buffer_t *buffer);
extern void fastd_handshake_handle(fastd_socket_t *sock, const fastd_peer_address_t *local_addr, const fastd_peer_address_t *remote_addr, void *arg, fastd_buffer_t *buffer);

struct {
    struct {
        void (*handshake_init)(fastd_socket_t *sock, const fastd_peer_address_t *local_addr, const fastd_peer_address_t *remote_addr, void *arg);
    } *protocol;
} conf;